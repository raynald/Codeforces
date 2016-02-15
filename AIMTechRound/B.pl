$n=<>;
@a=reverse(sort {$a<=>$b} (split ' ',<>));
$c=0;
$b=2e9;
for $_ (@a) {
    if ($_<$b) {$b=$_;} else {$b--;}
    if($b>0) {$c+=$b;}
}
print "$c\n";
