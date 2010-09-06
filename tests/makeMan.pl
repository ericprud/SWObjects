#!/usr/bin/perl -w

open (JIG,"tests/manualHarness.cpp") || die;
open (TEST,$ARGV[0]) || die "unable to open $ARGV[0]: $!";
open (OUT,">$ARGV[1]") || die "unable to open >$ARGV[1]: $!";
my $Mode="HEAD";
while(<JIG>) {
    if ($Mode eq "HEAD" && m/include/) {
	$Mode = "BODY";
	print OUT "#include \"$ARGV[0]\"\n";
    } elsif ($Mode eq "BODY" && m/tests/) {
	$Mode = "TAIL";
	my @ifdefs = ();
	for (my $line = 0; <TEST>; ++$line) {
	    if (@ifdefs > 0) {
		if (m/\*#if(.*)/) {
		    push(@ifdefs, $1);
		} elsif (m/\*#endif(.*)/) {
		    pop(@ifdefs);
		}
	    } elsif (m/\s*\/\//) {
		;
	    } elsif (m/\s*#if(.*)/) {
		push(@ifdefs, $1);
	    } elsif (m/\s*#endif(.*)/) {
		die "unexpected endif $1 at line $line";
	    } elsif (m/BOOST_AUTO_TEST_SUITE\(\s*(\S*)\s*/) {
		push (@S, $1);
	    } elsif (m/BOOST_AUTO_TEST_SUITE_END\(\s*/) {
		pop (@S);
	    } elsif (m/BOOST_AUTO_TEST_CASE\(\s*(\S*)\s*/) {
		print OUT "    ",join("::", @S,$1), "();\n";
	    }
	}
    } else {
	print OUT;
    }
}

