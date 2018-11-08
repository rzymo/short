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

BOOST_AUTO_TEST_SUITE(s1)
    BOOST_AUTO_TEST_CASE(test1)
    {
        BOOST_CHECK( lastDigit( 13, 19 ) == 7 ); // ok
    }
    
    BOOST_AUTO_TEST_CASE(test2)
    {
        BOOST_CHECK( lastDigit( 2, 3 ) == 8 ); // ok
    }
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(s2)
    BOOST_AUTO_TEST_CASE(test3)
    {
        BOOST_CHECK( lastDigit( 2, 3 ) == 9 ); // error
    }

    BOOST_AUTO_TEST_CASE(test4)
    {
        BOOST_CHECK( lastDigit( 3, 3) == 2 ); // error
    }
BOOST_AUTO_TEST_SUITE_END()
