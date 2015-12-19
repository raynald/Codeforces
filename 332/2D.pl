#!/usr/bin/perl

$x = <STDIN>;
$ans = 0;
@arr = ();
for($i = 1;$i <= $x;$i ++) {
    $tmp = $x * 6;
    if($tmp / $i / ($i + 1) + $i - 1 < 3 * $i) {
        last;
    }
    if ($tmp % $i > 0) {
        next;
    }
    $tmp /= $i;
    if ($tmp % ($i + 1) > 0) {
        next;
    }
    $tmp /= $i + 1;
    $tmp += $i - 1;
    if ($tmp % 3 > 0) {
        next;
    }
    push @arr, $i;
    if($tmp / 3 > $i) {
        push @arr, $tmp / 3;
    }
}
$len = @arr;
@sorted = sort {int($a) <=> int($b)} @arr;
print $len, "\n";
for ($i = 0;$i < $len; $i ++ ) {
    print $sorted[$i], " ", $sorted[$len - 1 - $i], "\n";
}
