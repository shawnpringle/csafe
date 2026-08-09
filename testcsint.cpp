#define BOOST_TEST_MODULE csintTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "csint.hpp"
#include <iostream>


BOOST_AUTO_TEST_CASE( CS1INCDEC ) {
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


    } catch (std::runtime_error* e) {
        std::cerr << "Exception: " << e->what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in CS1INCDEC" << std::endl;
    }
}

BOOST_AUTO_TEST_CASE( CS1COMPARE ) {
    try {
        const csint1_t False((int32_t)0);
        const csint1_t True((int32_t)-1);

        BOOST_CHECK(False != True);
        BOOST_CHECK(True < False);
        BOOST_CHECK(True <= False);
        BOOST_CHECK(False >= True);
        BOOST_CHECK(False > True);
        BOOST_CHECK(False == False);
        BOOST_CHECK(True == True);

    } catch (std::runtime_error* e) {
        std::cerr << "Exception in CS1COMPARE: " << e->what() << std::endl;
    }
}


BOOST_AUTO_TEST_CASE( CS2COMPARE ) {
    try {
        const csint2_t p1((int32_t)1);
        const csint2_t m1((int32_t)-1);

        BOOST_CHECK(p1 != m1);        
        BOOST_CHECK(m1 < p1);
        BOOST_CHECK(m1 <= p1);
        BOOST_CHECK(p1 >= m1);
        BOOST_CHECK(p1 > m1);
        BOOST_CHECK(p1 == p1);
        BOOST_CHECK(m1 == m1);

        const csint1_t False((int32_t)0);
        const csint1_t True((int32_t)-1);

        BOOST_CHECK_EQUAL(m1, True);
        BOOST_CHECK(p1 != True);
        BOOST_CHECK(p1 > True);
        BOOST_CHECK(m1 < False);

        BOOST_CHECK_THROW(csint1_t(2), std::overflow_error*);
        BOOST_CHECK_THROW(csint1_t(-2), std::underflow_error*);

        BOOST_CHECK_EQUAL(True, m1);
        BOOST_CHECK(True != p1);
        BOOST_CHECK(True < p1);
        BOOST_CHECK(False > m1);


    } catch (std::runtime_error* e) {
        std::cerr << "Exception in CS2COMPARE: " << e->what() << std::endl;
    }
}


BOOST_AUTO_TEST_CASE( SUMS ) {
    try {
        const csint1_t False((int32_t)0);
        const csint1_t True((int32_t)-1);

#define SHOW_SHIFTS 0

#if SHOW_SHIFTS

        cout << "1 << 0 = " << (1 << 0) << endl;
        cout << "1LL << 1 = " << (1LL << 1) << endl;
        cout << "1LL << 2 = " << (1LL << 2) << endl;
        cout << "1LL << 3 = " << (1LL << 3) << endl;
        cout << "1 << 4 = " << (1 << 4) << endl;
        cout << "1 << 29 = " << (1 << 29) << endl;
        cout << "1 << 30 = " << (1 << 30) << endl;
        cout << "1LL << 31 = " << (1LL << 31) << endl;
        cout << "1LL << 32 = " << (1LL << 32) << endl;
        cout << "1LL << 33 = " << (1LL << 33) << endl;
        cout << "1LL << 62 = " << (1LL << 62) << endl;
#endif        

    } catch (std::runtime_error* e) {
        std::cerr << "Exception: " << e->what() << std::endl;
    }


}

#include <sstream>
BOOST_AUTO_TEST_CASE( Stream ) {
    try {
        const csint1_t False((int32_t)0);
        const csint1_t True((int32_t)-1);
        csint1_t a(0);
        std::istringstream iss("-1");

        iss >> a;

        BOOST_CHECK_EQUAL(a, True);


    } catch (std::runtime_error* e) {
        std::cerr << "Exception in Stream test: " << e->what() << std::endl;
    }


}


BOOST_AUTO_TEST_CASE( Extreme ) {
    try {
        BOOST_CHECK_EQUAL(csint1_t::min(), -1);
        BOOST_CHECK_EQUAL(csint1_t::max(), 0);

        BOOST_CHECK_EQUAL(csint2_t::min(), -2);
        BOOST_CHECK_EQUAL(csint2_t::max(), 1);

        BOOST_CHECK_EQUAL(csint3_t::min(), -4);
        BOOST_CHECK_EQUAL(csint3_t::max(), 3);

        BOOST_CHECK_EQUAL(csint4_t::min(), -8);
        BOOST_CHECK_EQUAL(csint4_t::max(), 7);

        BOOST_CHECK_EQUAL(csint5_t::min(), -16);
        BOOST_CHECK_EQUAL(csint5_t::max(), 15);

        BOOST_CHECK_EQUAL(csint6_t::min(), -32);
        BOOST_CHECK_EQUAL(csint6_t::max(), 31);

        BOOST_CHECK_EQUAL(csint7_t::min(), -64);
        BOOST_CHECK_EQUAL(csint7_t::max(), 63);

        BOOST_CHECK_EQUAL(csint8_t::min(), -128);
        BOOST_CHECK_EQUAL(csint8_t::max(), 127);

        BOOST_CHECK_EQUAL(csint9_t::min(), -256);
        BOOST_CHECK_EQUAL(csint9_t::max(), 255);

    } catch (std::runtime_error* e) {
        std::cerr << "Exception in Stream test: " << e->what() << std::endl;
    }


}


