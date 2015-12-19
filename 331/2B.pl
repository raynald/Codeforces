#!/usr/bin/perl

$n = <STDIN>;
@b = split ' ', <STDIN>;
$ans = 0;
$delta = 0;
foreach (@b) {
    $ans += abs $_ - $delta;
    $delta += $_ - $delta;
}
print $ans, "\n";

