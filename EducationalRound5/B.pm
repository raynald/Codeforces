use strict;
use warnings;
use List::Util qw(max min);
use feature qw/say/;

my ($n, $m) = split ' ', <>;
my @a = ();
for (my $i = 0;$i < $n;$i ++) {
    my @c = split ' ', <>;
    push @a, min @c;
}
say max @a;
1;
