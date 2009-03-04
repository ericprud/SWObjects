#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef enum {Binding_STRONG = 3, Binding_WEAK = 1, Binding_FILTER = 4, Binding_COREF = 2} BindingStrength;
typedef std::map< int, BindingStrength >	ConsequentMap;
typedef std::map< const char*, ConsequentMap >	ConsequentMapList;
typedef std::pair< const char*, int >		IQEnt;
typedef std::vector< IQEnt >			InsertQueue;

typedef std::set<int> OuterGraphList;
typedef std::map<int, OuterGraphList > OuterGraphs;

/* {:1 {:2 ?x ?z }
       {:3 OPT {:4 ?x ?y } FILTER ?y }
       {:5 {:6 {:7 ?z } }
           {:8 {:9 {:10 ?z } } }
        }
    }
   consequents[x][1] = COREF
                 [2] = STRONG
                 [3] = COREF
                 [4] = WEAK
   consequents[y][3] = FILTER
                 [4] = WEAK
   consequents[z][5] = STRONG
                 [6] = FILTER
                 [7] = STRONG
                 [8] = COREF
                 [9] = COREF
                [10] = STRONG
 */

class Test {
    ConsequentMapList consequents;
    OuterGraphs outerGraphs;

public:
    Test () {
	consequents["x"][ 2] = Binding_STRONG ;
	consequents["x"][ 4] = Binding_WEAK   ;
	consequents["y"][ 3] = Binding_FILTER ;
	consequents["y"][ 4] = Binding_WEAK   ;
	consequents["z"][ 5] = Binding_STRONG ;
	consequents["z"][ 6] = Binding_FILTER ;
	consequents["z"][ 7] = Binding_STRONG ;
	consequents["z"][10] = Binding_STRONG ;

	outerGraphs[2].insert(1);
	outerGraphs[3].insert(1);
	outerGraphs[4].insert(1);
	outerGraphs[4].insert(3);
	outerGraphs[5].insert(1);
	outerGraphs[6].insert(1);
	outerGraphs[6].insert(5);
	outerGraphs[7].insert(1);
	outerGraphs[7].insert(5);
	outerGraphs[7].insert(6);
	outerGraphs[8].insert(1);
	outerGraphs[8].insert(5);
	outerGraphs[9].insert(1);
	outerGraphs[9].insert(5);
	outerGraphs[9].insert(8);
	outerGraphs[10].insert(1);
	outerGraphs[10].insert(5);
	outerGraphs[10].insert(8);
	outerGraphs[10].insert(9);
    }
    ~Test () {  }

    static string bindingStr (BindingStrength s) {
	return s == Binding_STRONG ? "STRONG" : 
	       s == Binding_WEAK   ? "WEAK"   :
	       s == Binding_FILTER ? "FILTER" :
	       s == Binding_COREF  ? "COREF"  : 
	       "???";
    }

    string dumpConsequents () {
	stringstream s;
	for (ConsequentMapList::iterator varIt = consequents.begin();
	     varIt != consequents.end(); ++varIt)
	    for (ConsequentMap::iterator graphIt = varIt->second.begin();
		 graphIt != varIt->second.end(); ++graphIt)
		s << "consequents[\"" << varIt->first << "\"][" << graphIt->first << "] = " << bindingStr(consequents[varIt->first][graphIt->first]) << endl;
	return s.str();
    }

    string dumpOuterGraphs () {
	stringstream s;
	for (OuterGraphs::iterator innerGraphIt = outerGraphs.begin();
	     innerGraphIt != outerGraphs.end(); ++innerGraphIt) {
	    s << "outerGraphs[" << innerGraphIt->first << "][";
	    for (OuterGraphList::iterator outerGraphIt = innerGraphIt->second.begin();
		 outerGraphIt != innerGraphIt->second.end(); ++outerGraphIt) {
		if (outerGraphIt != innerGraphIt->second.begin())
		    s << ",";
		s << *outerGraphIt;
	    }
	    s << "]" << endl;
	}
	return s.str();
    }

    void findCorefs (int parent) {
	/* For each known variable: */
	for (ConsequentMapList::iterator varIt = consequents.begin();
	     varIt != consequents.end(); ++varIt) {

	    /* Create an insert queue so we don't muck with the iterator. */
	    InsertQueue iq;

	    /* For each pair of graphs that reference var: */
	    for (ConsequentMap::iterator graph1It = consequents[varIt->first].begin();
		 graph1It->first != consequents[varIt->first].rbegin()->first; ++graph1It) {
		ConsequentMap::iterator graph2It = graph1It;
		for (++graph2It; graph2It != consequents[varIt->first].end(); ++graph2It) {

		    /* Walk pairwise through the lineage of g1,g2 from the root
		     * until the lineage diverges, storing the common parents. */
		    OuterGraphList::iterator graph1parents = outerGraphs[graph1It->first].begin();
		    OuterGraphList::iterator graph2parents = outerGraphs[graph2It->first].begin();
		    int commonAncestor = parent; // assignment not strictly necessary, but useful for templating.
		    while (*graph1parents == *graph2parents) {
			commonAncestor = *graph1parents;
			++graph1parents;
			++graph2parents;
		    }

		    /* If neither lineage is not subsumed by the other, and
		     * there's no existing entry for that pair, the last
		     * ancestor is the top COREF. */
		    if (*graph1parents != graph2It->first &&
			*graph2parents != graph1It->first &&
			consequents[varIt->first].find(commonAncestor) == consequents[varIt->first].end())
			iq.push_back(IQEnt(varIt->first, commonAncestor));

		    /* All items in the lineage from here down are COREFs unless
		     * they are already set to something else */
		    for (; graph1parents != outerGraphs[graph1It->first].end(); ++graph1parents)
			if (consequents[varIt->first].find(*graph1parents) == consequents[varIt->first].end())
			    iq.push_back(IQEnt(varIt->first, *graph1parents));

		    for (; graph2parents != outerGraphs[graph2It->first].end(); ++graph2parents)
			if (consequents[varIt->first].find(*graph2parents) == consequents[varIt->first].end())
			    iq.push_back(IQEnt(varIt->first, *graph2parents));
		}
	    }
	    /* Insert queued items (so they don't muck with the iterators).
	     */
	    for (InsertQueue::iterator p = iq.begin(); p != iq.end(); ++p)
		consequents[p->first][p->second] = Binding_COREF;
	}
    }
};

int main () {
    Test t;
    //cout << t.dumpConsequents();
    //cout << t.dumpOuterGraphs();
    t.findCorefs(-1);
    cout << "produced:" << endl << t.dumpConsequents();
    return 0;
}

