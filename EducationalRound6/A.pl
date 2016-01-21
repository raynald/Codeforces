use warnings;
use strict;

my ($x1, $y1) = split ' ' , <>;
my ($x2, $y2) = split ' ' , <>;
my $ans = abs $x1 - $x2;
$ans = abs $y1 - $y2 if abs $y1 - $y2 > $ans;
print "$ans\n";
