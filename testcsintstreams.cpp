/*
 * Test cases for streams with csint types.
 Should there be a problem with iostreams and csint types,
 this file will be useful for reading the error messages.  The
 other test file, relies on streams working already with csint 
 types for the testing itself.

  * Rules: 
  1. Do not use BOOST_CHECK or friends in this file.
  2. Use ostreams for every csint type in order for the other
  test file to have instructive value.

 */

#define BOOST_TEST_MODULE csintTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "csint.hpp"
#include <iostream>
using namespace std;

BOOST_AUTO_TEST_CASE( Streams ) {
    try {
        const csint1_t False((int32_t)0);
        const csint1_t True((int32_t)-1);

        csint1_t a(False);
        csint1_t b(True);
        try {
            BOOST_CHECK_THROW(++a, std::overflow_error*);
        } catch (std::runtime_error* e) {
            std::cerr << "Unexpected Exception Increment: " << e->what() << std::endl;
        }
        BOOST_CHECK_EQUAL(a, False);
        BOOST_CHECK_EQUAL(++b, False); // ++b == 0

        try {
            BOOST_CHECK_EQUAL(b, False); // b == 0
            BOOST_CHECK_EQUAL(--b, True); // b == -1
            BOOST_CHECK_THROW(--b, std::underflow_error*);
        } catch (std::runtime_error* e) {
            std::cerr << "Unexpected Exception Decrement: " << e->what() << std::endl;
        }

        csint2_t c(0);

        cout << c << endl;
        csint3_t d(1);
        csint4_t e(1);

        cout << d << endl;
        cout << e << endl;

        csint5_t f(4);
        cout << f << endl;
        csint6_t g(4);
        cout << g << endl;
        csint7_t h(8);
        cout << h << endl;
        csint8_t i(8);
        cout << i << endl;
        
        csint9_t j(255);
        cout << j << endl;

        csint10_t k(255);
        cout << k << endl;

        csint11_t l(852);
        cout << l << endl;

        csint12_t m(852);
        cout << m << endl;

        csint13_t n(852);
        cout << n << endl;

        csint14_t o(1492);
        cout << o << endl;

        csint15_t p(1974);
        cout << p << endl;

        csint16_t q(1974);
        
        csint17_t r(1974);
        cout << r << endl;

        csint64_t s(319000777215);
        cout << s << endl;

    } catch (std::overflow_error* e) {
        std::cerr << "Exception: " << e->what() << std::endl;

    } catch (std::runtime_error* e) {
        std::cerr << "Exception: " << e->what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in CS1INCDEC" << std::endl;
    }
}
