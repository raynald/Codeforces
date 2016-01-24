$n=<>; $f=0; $y=1; $a=1; @x=split ' ',<>;
foreach (@x) { if (!$_) { if ($f) { $y++; } } else { $f=1; $a*=$y; $y=1; } }
if ($f) { print "$a\n"; } else { print "0\n" }
