#!/usr/bin/perl

sub min {
    return $_[0] < $_[1] ? $_[0]: $_[1];
}

sub max {
    return $_[0] > $_[1] ? $_[0]: $_[1];
}


@d = split(' ', <STDIN>);
$max_one = max(max($d[0], $d[1]), $d[2]);
$ans = min($d[0] + $d[1] + $d[2], 2 * ($d[1] + $d[2] + $d[0] - $max_one));
print $ans, "\n";

