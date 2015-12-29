$n = <>;
@m = split ' ', <>;
$cnt = 0;
@sum = ();
$pos = 0;
$ans = 0;
for($i = 1;$i < $n;$i ++) {
    if ($i < $n - 1 and $m[$i - 1] == $m[$i + 1] and $m[$i] != $m[$i - 1]) {
        if($cnt == 0) {
            $start = $m[$i - 1];
            $end = $m[$i];
        }
        $cnt ++;
    } else {
        if (int(($cnt + 1) / 2) > $ans) {
            $ans = int(($cnt + 1) / 2);
        }
        push @sum, @m[$pos..$i - $cnt - 1];
        if ($cnt % 2 == 0) {
            for($j = 0;$j < $cnt / 2;$j ++) {
                push @sum, $start;
            }
            for($j = 0;$j < $cnt / 2;$j ++) {
                push @sum, $end;
            }
        } else {
            for($j = 0;$j < $cnt;$j ++) {
                push @sum, $start;
            }
        }
        $pos = $i;
        $cnt = 0;
    }
}
print $ans, "\n";
push @sum, $m[-1];
$m = join ' ', @sum;
print $m, "\n";
