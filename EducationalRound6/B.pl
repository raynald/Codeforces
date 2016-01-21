use warnings;
use strict;

my @num = (6, 2, 5, 5, 4, 5, 6, 3, 7, 6);
my ($a, $b) = split ' ', <>;
my $ans = 0;
foreach my $i ($a..$b) {
    while ($i) {
        $ans += $num[$i % 10];
        $i = int($i / 10);
    }
}
print "$ans\n";

