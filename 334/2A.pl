#!/usr/bin/perl

sub max {
    return $_[0] > $_[1] ? $_[0]: $_[1];
}

@m = split(' ', <STDIN>);
@w = split(' ', <STDIN>);
@h = split(' ', <STDIN>);
$i = 1;
$sum = 0;
foreach (@m) {
    $a = 0.3 * 500 * $i;
    $b = (500 - 2 * $m[$i-1]) * $i - 50 * $w[$i-1];
    $t = max($a, $b);
    $i ++;
    $sum += $t;
}

$sum += $h[0] * 100 - $h[1] * 50;
print $sum . "\n";

