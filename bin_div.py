#
# Divisibility by 2-15 for binary numbers
#
# -*- coding: utf-8 -*-
import sys
from numpy import*

def verifyBin(s):
    for i in s:
        if (i != '0') and (i != '1'):
            return False
    return True

def divByX(x, s):
    tab = zeros((int(x),2), int)

                    # DFA    
    if (x == 3): 
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 0; tab[2][0] = 1; tab[2][1] = 2;
    elif (x == 5):
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 0; tab[3][0] = 1; tab[3][1] = 2; tab[4][0] = 3; tab[4][1] = 4;
    elif (x == 7):
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 0; tab[4][0] = 1; tab[4][1] = 2;
        tab[5][0] = 3; tab[5][1] = 4; tab[6][0] = 5; tab[6][1] = 6;
    elif (x == 9):
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 0;
        tab[5][0] = 1; tab[5][1] = 2; tab[6][0] = 3; tab[6][1] = 4; tab[7][0] = 5; tab[7][1] = 6; tab[8][0] = 7; tab[8][1] = 8;
    elif (x == 11):
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 9;
        tab[5][0] = 10; tab[5][1] = 0; tab[6][0] = 1; tab[6][1] = 2; tab[7][0] = 3; tab[7][1] = 4; tab[8][0] = 5; tab[8][1] = 6; tab[9][0] = 7; tab[9][1] = 8;
        tab[10][0] = 9; tab[10][1] = 10;
    elif (x == 13):
        tab[0][0] = 0; tab[0][1] = 1; tab[1][0] = 2; tab[1][1] = 3; tab[2][0] = 4; tab[2][1] = 5; tab[3][0] = 6; tab[3][1] = 7; tab[4][0] = 8; tab[4][1] = 9;
        tab[5][0] = 10; tab[5][1] = 11; tab[6][0] = 12; tab[6][1] = 0; tab[7][0] = 1; tab[7][1] = 2; tab[8][0] = 3; tab[8][1] = 4; tab[9][0] = 5; tab[9][1] = 6;
        tab[10][0] = 7; tab[10][1] = 8; tab[11][0] = 9; tab[11][1] = 10; tab[12][0] = 11; tab[12][1] = 12;
          
    pos = 0
    jumpTo = 0
        
    for i in range(0,len(s)):
        jumpTo = int(s[i])
        pos = tab[pos][jumpTo]
    
    if (pos == 0):
        return True
    else:
        return False

def div(s):
    out = zeros((16), bool)

    print("\nDivisibility by:\n")
    
    if (s[-1:] == "0"): out[2] = True;
    if (s[-2:] == "00"): out[4] = True;
    if (s[-3:] == "000"): out[8] = True;

    for i in range(3, 14, 2):
        out[i] = divByX(i, s)
 
    out[6]  = out[2] and out[3]
    out[10] = out[2] and out[5]
    out[12] = out[3] and out[4]
    out[14] = out[2] and out[7]
    out[15] = out[3] and out[5]

    for i in range(2,16):
        if (out[i] == True):
            out_str = "true"
        else:
            out_str = "   false"
        print("%3d - %s" % (i, out_str))


# --- START --- 
    
if (sys.argv.__len__() == 2):
    try:
        f = open(sys.argv[1], 'r')
        s = f.readline().rstrip()
        f.close()
    except:
        s = sys.argv[1]
else:
    s = input('binary number: ')

if (not verifyBin(s)):
    print("Input error!")
    sys.exit(1)
else:
    if (len(s) < 3):
        print("At least 3 characters!")
    else:
        div(s)
