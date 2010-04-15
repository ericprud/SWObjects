/*
    4store - a clustered RDF storage and query engine

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
 *  Copyright 2006 Nick Lamb for Garlik.com
 */

/* Sample usage
 *
 * 4s-insert-query kbname many FS_BIND_MODEL FS_BIND_SUBJECT FS_BIND_PREDICATE FS_BIND_OBJECT FS_BIND_BY_SUBJECT http://example.com/TGR06001.nt http://www.census.gov/tiger/2002/landmark/6001/734 p o 0 1
 * note that `make test` creates a kb in /var/lib/4store/ called query_test_<user> .

 * Compiled with:
cc -std=gnu99 -fno-strict-aliasing -Wall  -g -O0 -I../../4store/src/ -DHAVE_LAQRS -DHAVE_RASQAL_WORLD  -DGIT_REV=\"v1.0.0-7-g0bcda14\" `pkg-config --cflags rasqal glib-2.0 libxml-2.0` `pcre-config --cflags`   -c -o 4s-insert-query.o 4s-insert-query.c
cc  -rdynamic  `pkg-config --libs rasqal glib-2.0 libxml-2.0 avahi-client avahi-glib` `pcre-config --libs`  4s-insert-query.o ../../4store/src//common/lib4store.a   -o 4s-insert-query

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "common/4store.h"
#include "common/hash.h"
#include "common/error.h"

static char *flag_name[] = {
  "FS_BIND_MODEL",
  "FS_BIND_SUBJECT",
  "FS_BIND_PREDICATE",
  "FS_BIND_OBJECT",
  "FS_BIND_DISTINCT",
  "FS_BIND_OPTIONAL",
  "FS_BIND_UNION",
  "FS_BIND_SAME_XXXX",
  "FS_BIND_SAME_XXAA",
  "FS_BIND_SAME_XAXA",
  "FS_BIND_SAME_XAAX",
  "FS_BIND_SAME_XAAA",
  "FS_BIND_SAME_AXXA",
  "FS_BIND_SAME_AXAX",
  "FS_BIND_SAME_AXAA",
  "FS_BIND_SAME_AAXX",
  "FS_BIND_SAME_AAXA",
  "FS_BIND_SAME_AAAX",
  "FS_BIND_SAME_AAAA",
  "FS_BIND_SAME_AABB",
  "FS_BIND_SAME_ABAB",
  "FS_BIND_SAME_ABBA",

  "FS_BIND_BY_SUBJECT",
  "FS_BIND_BY_OBJECT",
};

static int flag_value[] = {
  FS_BIND_MODEL,
  FS_BIND_SUBJECT,
  FS_BIND_PREDICATE,
  FS_BIND_OBJECT,
  FS_BIND_DISTINCT,
  FS_BIND_OPTIONAL,
  FS_BIND_UNION,
  FS_BIND_SAME_XXXX,
  FS_BIND_SAME_XXAA,
  FS_BIND_SAME_XAXA,
  FS_BIND_SAME_XAAX,
  FS_BIND_SAME_XAAA,
  FS_BIND_SAME_AXXA,
  FS_BIND_SAME_AXAX,
  FS_BIND_SAME_AXAA,
  FS_BIND_SAME_AAXX,
  FS_BIND_SAME_AAXA,
  FS_BIND_SAME_AAAX,
  FS_BIND_SAME_AAAA,
  FS_BIND_SAME_AABB,
  FS_BIND_SAME_ABAB,
  FS_BIND_SAME_ABBA,

  FS_BIND_BY_SUBJECT,
  FS_BIND_BY_OBJECT,
};

static long res_pos[FS_MAX_SEGMENTS];

#define RES_BUF_SIZE 256
static fs_resource res_buffer[FS_MAX_SEGMENTS][RES_BUF_SIZE];
static char *lex_tmp[FS_MAX_SEGMENTS][RES_BUF_SIZE];

static int buffer_res(fsp_link *link, const int segments, fs_rid r, char *lex, fs_rid attr, int dryrun) {
    int seg = FS_RID_SEGMENT(r, segments);

    if (FS_IS_BNODE(r)) {
	return 1;
    }
    /* if (nodecache[r & CACHE_MASK] == r) { */
    /* 	return 1; */
    /* } */
    if (!lex) {
        return 1;
    }
    /* nodecache[r & CACHE_MASK] = r; */
    res_buffer[seg][res_pos[seg]].rid = r;
    res_buffer[seg][res_pos[seg]].attr = attr;
    if (strlen(lex) < RES_BUF_SIZE) {
	strcpy(lex_tmp[seg][res_pos[seg]], lex);
	res_buffer[seg][res_pos[seg]].lex = lex_tmp[seg][res_pos[seg]];
    } else {
	res_buffer[seg][res_pos[seg]].lex = g_strdup(lex);
    }
    if (++res_pos[seg] == RES_BUF_SIZE) {
	if (fsp_res_import(link, seg, res_pos[seg], res_buffer[seg])) {
	    fs_error(LOG_ERR, "resource import failed");
	    return 1;
	}
	for (int i=0; i<res_pos[seg]; i++) {
	    if (res_buffer[seg][i].lex != lex_tmp[seg][i]) {
		free(res_buffer[seg][i].lex);
		res_buffer[seg][i].lex = NULL;
	    }
	}
	res_pos[seg] = 0;
    }

    return 0;
}

static fs_rid_vector *rid_uri(char *uri, int segments, fsp_link* link)
{
  fs_rid_vector *rids = fs_rid_vector_new(0);

//  if (strcmp(uri, "NULL")) {
      fs_rid rid = fs_hash_uri(uri);
      printf("016llx: %016llx\n", rid);
      fs_rid_vector_append(rids, rid);

      if (buffer_res(link, segments, rid, uri, FS_RID_NULL, 0)) {
	  fs_error(LOG_ERR, "resource import failed");
      }
//  }

  return rids;
}

static char *get_uri(fsp_link *link, int segments, fs_rid rid)
{
  fs_rid_vector onerid = { .length = 1, .size = 1, .data = &rid };
  fs_resource resource;

  if (fsp_resolve(link, FS_RID_SEGMENT(rid, segments), &onerid, &resource)) {
    return "#error URI#";
  }

  return (char *) resource.lex;
}

int main(int argc, char *argv[])
{
  fs_hash_init(FS_HASH_UMAC);


  char *password = fsp_argv_password(&argc, argv);

  int flags = 0, many = 0, all = 0;
  int seg = 0; /* deliberately using signed type */
  fs_rid_vector *mrids= NULL, *srids= NULL, *prids= NULL, *orids= NULL;
  fs_rid_vector **result = NULL;

  if (argc < 7) {
    fprintf(stderr, "%s revision %s\n", argv[0], FS_FRONTEND_VER);
    fprintf(stderr, "Usage: %s <kbname> { many | all | seg# } <flags>\n", argv[0]);
    fprintf(stderr, " mrid-file srid-file prid-file orid-file [offset limit]\n");
    fprintf(stderr, "For flags use FS_BIND_... symbols or a numeric value\n");
    fprintf(stderr, "RID files are one RID per line\n");
    exit(1);
  }

  char *kbname = argv[1];

  if (!strcasecmp(argv[2], "many")) {
    many = 1;
  } else if (!strcasecmp(argv[2], "all")) {
    all = 1;
  } else {
    seg = atoi(argv[2]);
  }

  int param = 3;

  flags = strtol(argv[param], NULL, 0);

  if (flags == 0) { /* symbolic flags, hopefully */
    while (param < argc) {
      const int len = sizeof(flag_name) / sizeof(char *);
      int k;
      for (k = 0; k < len; ++k) {
        if (!strcmp(flag_name[k], argv[param])) {
          flags |= flag_value[k];
          break;
        }
      }
      if (k == len) break;
      param ++;
    }
  } else {
    param ++; /* done with the numeric flags then */
  }

  if (argc < param + 4) {
    fprintf(stderr, "Wrong number of arguments\n");
    exit(1);
  }

  fsp_link *link = fsp_open_link(kbname, password, FS_OPEN_HINT_RO);

  if (!link) {
    fs_error (LOG_ERR, "couldn't connect to “%s”", argv[1]);
    exit(2);
  }

  int segments = fsp_link_segments(link);
  for (int seg = 0; seg < segments; seg++) {
      res_pos[seg] = 0;
      for (int j=0; j<RES_BUF_SIZE; j++) {
	  lex_tmp[seg][j] = malloc(RES_BUF_SIZE);
      }
  }


  mrids = rid_uri(argv[param++], segments, link);
  srids = rid_uri(argv[param++], segments, link);
  prids = rid_uri(argv[param++], segments, link);
  orids = rid_uri(argv[param++], segments, link);

  for (int seg = 0; seg < segments; seg++) {
      if (res_pos[seg] > 0 && fsp_res_import(link, seg, res_pos[seg], res_buffer[seg])) {
	  fs_error(LOG_ERR, "resource import failed");
	  return 1;
      }
  }

  if (fsp_res_import_commit_all(link)) {
      fs_error(LOG_ERR, "resource commit failed");
      return 2;
  }

  int limit, offset;

  if (argc == param ) {
    /* defaults */
    limit = -1;
    offset = -1;
  } else if (argc > param + 2) {
    fprintf(stderr, "Wrong number of arguments\n");
    exit(1);
  } else if (argc < param + 2) {
    fprintf(stderr, "Wrong number of arguments\n");
    exit(1);
  } else {
    offset = atoi(argv[param]);
    limit = atoi(argv[param + 1]);
  }

  if (seg < 0 || seg > segments) {
    fs_error (LOG_ERR, "Segment %d out of range (0-%u)", seg, segments);
    exit(1);
  }


  fs_rid quad_buf[1][4] = { {
      mrids->data[0], 
      srids->data[0], 
      prids->data[0], 
      orids->data[0]
      } };
  int segment = FS_RID_SEGMENT(quad_buf[0][1], segments);
  if (fsp_quad_import(link, segment, FS_BIND_BY_SUBJECT, 1, quad_buf)) {
      fs_error(LOG_ERR, "quad import failed");
      return 1;
  }
  if (fsp_quad_import_commit_all(link, FS_BIND_BY_SUBJECT)) {
      fs_error(LOG_ERR, "quad commit failed");
      return 3;
  }

  double then = fs_time();
  int ans = 0;

  if (all) {
    ans = fsp_bind_limit_all(link, flags, mrids, srids, prids, orids, &result, offset, limit);
  } else if (many) {
    ans = fsp_bind_limit_many(link, flags, mrids, srids, prids, orids, &result, offset, limit);
  } else {
    ans = fsp_bind_limit(link, seg, flags, mrids, srids, prids, orids, &result, offset, limit);
  }

  double time_binding = fs_time() - then;
  if (ans != 0) exit(1);

  /* print results */

  int cols = 0;
  for (int k = 0; k < 4; ++k) {
    if (flags & (1 << k)) cols++;
  }

  if (!result) {
    printf("NO MATCH found.\n");
  } else if (cols == 0) {
    printf("MATCH found.\n");
  } else if (result[0]) {
    int length = result[0]->length;

    if (flags & FS_BIND_MODEL) printf("-----Model------  ");
    if (flags & FS_BIND_SUBJECT) printf("----Subject-----  ");
    if (flags & FS_BIND_PREDICATE) printf("----Predicate---  ");
    if (flags & FS_BIND_OBJECT) printf("-----Object-----");
    putchar('\n');

    for (int k = 0; k < length; ++k) {
      for (int c = 0; c < cols; ++c) {
        printf("%016llX  ", result[c]->data[k]);
      }
      for (int c = 0; c < cols; ++c) {
	  char *uri = get_uri(link, segments, result[c]->data[k]);
	  printf("  <%s>", uri);
      }

      putchar('\n');
    }
  }

  fprintf(stderr, "bind took %f seconds on client\n", time_binding);

  fs_query_timing times;
  if (all || many) {
    fprintf(stderr, "binding on all or many segments, times in seconds...\n");
    for (int s = 0; s < segments; ++s) {
      fsp_get_query_times(link, s, &times);
      if (times.bind > 0.0f) {
        fprintf(stderr, "%d: %f\n", s, times.bind);
      }
    }
    fputc('\n', stderr);
  } else {
    fsp_get_query_times(link, seg, &times);
    fprintf(stderr, "binding segment %d took %f seconds\n", seg, times.bind);
  }

  fsp_close_link(link);
}
