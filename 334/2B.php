<?php
function calc($size, $repo) {
    $i = 0; $j = count($repo) - 1;
    $bucket = 0;
    while ($i < $j) {
        if ($repo[$j] + $repo[$i] <= $size) {
            $i ++;
        } 
        $bucket ++;
        $j --;
    }
    if ($i == $j) $bucket ++;
    return $bucket;
}

fscanf(STDIN, "%d %d", $n, $k);
$temp = fgets(STDIN);
$repo = explode(" ", $temp);
$len = count($repo);
$left = $repo[$len - 1];
$right = 2 * $left;
while($left < $right) {
    $mid = intval(($left + $right) / 2);
    if (calc($mid, $repo) <= $k) {
        $right = $mid; 
    } else {
        $left = $mid + 1;
    }
}
echo intval($left), "\n";
?>
