/*
// Last digit of exponentiation - pow(base^exp)
// for example 13^19 -> 7   (1461920290375446110677)
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

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

BOOST_AUTO_TEST_CASE( testLastDigit )
{
    BOOST_CHECK( lastDigit( 13, 19 ) == 7 ); // ok
    BOOST_CHECK( lastDigit(   2, 3 ) == 8 ); // ok
    BOOST_CHECK( lastDigit(   2, 3 ) == 9 ); // error
}
