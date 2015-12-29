<?php
fscanf(STDIN, "%d %d", $n, $k);
$temp = trim(fgets(STDIN));
$a = explode(" ", $temp);
$temp = trim(fgets(STDIN));
$b = explode(" ", $temp);
$m = $n / $k;
$ans = 1;
for($i = 0;$i < $m;$i ++) {
    if($b[$i] == 0) {
        $tmp = pow(10, $k - 1);
        $mul = intval(($tmp * 10 - 1) / $a[$i]) - intval($tmp / $a[$i]) + 1;
        if ($tmp % $a[$i]) $mul --;
    } else {
        $tmp = pow(10, $k - 1);
        $mul = intval(($tmp * 10 - 1) / $a[$i]) - intval($tmp * ($b[$i] + 1) / $a[$i]) + 1 + intval(($tmp * $b[$i] - 1) / $a[$i]) + 1;
        if ($tmp * ($b[$i] + 1) % $a[$i]) $mul --;
    }
    $ans = $ans * $mul;
    $ans %= (pow(10, 9) + 7);
}
echo intval($ans), "\n";
?>