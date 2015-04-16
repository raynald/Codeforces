import sys

oneth = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

twoth = ['zero', 'ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']

diff = ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
s = int(sys.stdin.readline())
if s % 10 == 0:
    print twoth[s/10]
else:
    if s < 10:
        print oneth[s]
    else:
        if s < 20:
            print diff[s-11]
        else:
            print '%s-%s' % (twoth[s/10], oneth[s%10])
