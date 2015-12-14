#!/usr/bin/perl

sub count {
    if ($_[0] > $_[1]) {
        return int(($_[0] - $_[1])/2);
    } else {
        return $_[0] - $_[1];
    }
}

@m = split(' ', <STDIN>);
@x = split(' ', <STDIN>);
$sum = count($m[0], $x[0]) + count($m[1], $x[1]) + count($m[2], $x[2]);
if ($sum >= 0) {
    print "Yes\n";
} else {
    print "No\n";
}

