($n,$b,$p)=split ' ',<>;
$c=$n*$p;
$a=0;
while($n>1) {
    $x=1<< int(log($n)/log(2));
    $a+=$b*$x+$x/2;
    $n-=$x/2;
}
print "$a $c\n";
