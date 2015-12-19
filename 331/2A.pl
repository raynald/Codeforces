#!/usr/bin/perl

$n = <STDIN>;
@x = ();
@y = ();
for ($i = 0;$i < $n;$i ++) {
    @tmp = split(' ', <STDIN>);
    $x[$i] = $tmp[0];
    $y[$i] = $tmp[1];
}
if ($n == 1) {
    print "-1\n";
} else {
    if ($n == 2) {
        if($x[0] == $x[1] or $y[0] == $y[1]) {
            print "-1\n";
        } else {
            print abs ($x[0] - $x[1]) * abs ($y[0] - $y[1]), "\n";
        }
    } else {
        if($x[0] == $x[1]) {
            $len = abs $x[0] - $x[2];
        } else {
            $len = abs $x[0] - $x[1];
        }
        if($y[0] == $y[1]) {
            $hei = abs $y[0] - $y[2];
        } else {
            $hei = abs $y[0] - $y[1];
        }
        print $len * $hei, "\n";
    }
}

