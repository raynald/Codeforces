($n, $t) = split ' ', <>;
$n eq '1' && $t == '10' ? print -1, "\n" : print $t . '0' x ($n - length $t); 
