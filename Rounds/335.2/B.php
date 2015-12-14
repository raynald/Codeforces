<?php
fscanf(STDIN, "%d %d %d %d", $x, $y, $x0, $y0);
$temp = str_split(trim(fgets(STDIN)));
$len = count($temp);
$ans = array_fill(0, $len + 1, 0);
$visit = array_fill(1, $x * $y, 0);
$step = 0;
$ans[0] = 1;
$visit[($x0-1)*$y+$y0] = 1;
foreach ($temp as $ch) {
    $step ++;
    switch ($ch) {
        case 'U':
            if ($x0 > 1) $x0 --;
            break;
        case 'R':
            if ($y0 < $y) $y0 ++;
            break;
        case 'D':
            if ($x0 < $x) $x0 ++;
            break;
        case 'L':
            if ($y0 > 1) $y0 --;
    }
    $tmp = ($x0 - 1) * $y + $y0;
    if ($visit[$tmp]==0) {
        $visit[$tmp] = 1;
        $ans[$step] = 1;
    }
}
$ans[$len] += $x * $y - array_sum($visit);
for ($i = 0;$i <= $len;$i ++) {
    if($i > 0) echo " ";
    echo $ans[$i];
}
echo "\n";
?>
