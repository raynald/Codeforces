#!/usr/bin/perl

$n = <STDIN>;
@d = split(' ', <STDIN>);
$len = @d;
$big[0] = $d[0];
$small[$len - 1] = $d[$len - 1];
for($i = 1;$i < $len;$i ++) {
    $big[$i] = $big[$i - 1] > $d[$i]? $big[$i - 1]: $d[$i];
    $small[$len - $i - 1] = $small[$len - $i] < $d[$len - 1 - $i]? $small[$len - $i]: $d[$len - 1 - $i];
}
$ans = 1;
for($i = 1;$i < $len;$i ++) {
    if ($big[$i - 1] <= $small[$i]) {
        $ans ++;
    }
}
print $ans, "\n";

