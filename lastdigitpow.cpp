/*
// Last digit of exponentiation - pow(base^exp)
// for example 13^19 -> 7   (1461920290375446110677)
*/

#include <iostream>

using namespace std;

int lastDigit(int, int);

int main(int argc, char *argv[])
{
    int base, exp;

    if (argc != 3) { cout << "\nusage:\tfilename base exp\n"; return 0; }

    try
    {
        string s1, s2;
        s1 = argv[1];
        s2 = argv[2];
        base = stoi(s1, nullptr, 10);
        exp  = stoi(s2, nullptr, 10);
    }
    catch(const std::exception &e)
    {
        cout << "\ninput error!\n";
        return 1;
    }
    if ( (base < 0) || (exp < 0) )
        { cout << "\nbase & exp must be 0 or greater\n"; return 1; }
    else
        cout << "\nlast digit of " << base << "^" << exp << " is " << lastDigit(base, exp) << endl;

    return 0;
}

int lastDigit(int base, int exp)
{
    if (!exp) return 1;

    int i = 1;
    base %= 10;

    while (1)
    {
        if (exp & 1)
            i = (i * base) % 10;
        exp >>= 1;
        if (!exp) return i;
        base = (base * base) % 10;
    }
}
