$n = <>;
@a = split ' ', <>;
$ans = $k = 0;
foreach $_ (@a) {
    if ($_ == '1') {
        if ($ans > 0 && $k == 1) {
            $ans ++;
        }
        $ans ++;
        $k = 0;
    } else {
        $k ++;
    }
}
print $ans, "\n";
