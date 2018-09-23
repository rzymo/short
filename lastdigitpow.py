#
# Last digit of exponentiation - pow(base^exp)
# for example 13^19 -> 7   (1461920290375446110677)
#

# -*- coding: utf-8 -*-
import sys

def lastDigit(base, exp):
    if (exp == 0):
        return 1
    
    i = 1
    base = base % 10
    
    while (i):
        if (exp & 1):
            i = (i * base) % 10
        exp >>= 1
        if (exp == 0):
            return i
        base = (base * base) % 10

if (sys.argv.__len__() !=3):
    print("\nusage:\tscriptname base exp\n")
    sys.exit(0)
    
try:
    base = int(sys.argv[1])
    exp  = int(sys.argv[2])
except:
    print("\ninput error!\n")
    sys.exit(1)

if (base < 0) or (exp < 0):
    print("\nbase & exp must be 0 or greater\n")
    sys.exit(1)
else:
    print("\nlast digit of "+str(base)+"^"+str(exp)+" is "+str(lastDigit(base, exp))+"\n")

