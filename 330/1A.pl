#!/usr/bin/perl

$n = <STDIN>;
@x = split " ", <STDIN>;
@x = sort {$a <=> $b} @x;
$len = @x;
$step = ($n - 2) / 2 + 1;
$ans = -1;
for ($i = 0;$i + $step < $len;$i ++) {
    if ($ans == -1 || $x[$i + $step] - $x[$i] < $ans) {
        $ans = $x[$i + $step] - $x[$i];
    }
}
print $ans, "\n";

