#!/usr/bin/perl
# WA for large numbers;

use bignum;

sub gcd {
    my ($a, $b) = @_;
    ($a, $b) = ($b, $a) if $a > $b;
    while ($a) { ($a, $b) = ($b % $a, $a) }
    return $b;
}

sub min {
    my ($a, $b) = @_;
    ($a, $b) = ($b, $a) if $a > $b;
    return $a;
}

@in = split ' ', <>;
($in[1], $in[2]) = ($in[2], $in[1]) if $in[1] > $in[2];
$lcm = $in[1] / gcd($in[1], $in[2]) * $in[2];
$ans = $in[1] * int($in[0] /  $lcm) + min($in[0] % $lcm,  $in[1] - 1);
$gc = gcd($ans, $in[0]);
print $ans / $gc, '/', $in[0] / $gc, "\n";
