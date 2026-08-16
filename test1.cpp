#include "safeint.h"
#include <iostream>
#define BOOST_TEST_MODULE Test1
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( M1 ) {

   safeint<1> a(-1);
   
   BOOST_CHECK_EQUAL( 0, (int64_t)a++);   // okay.
   BOOST_CHECK_THROW( a++, overflow_error*);
}

BOOST_AUTO_TEST_CASE( M2 ) {
  safeint<2> b(-2);
  
  BOOST_CHECK_EQUAL( b, -2 );
  
  BOOST_CHECK_EQUAL( ++b, -1 );
  
  BOOST_CHECK_EQUAL( b++, -1 );
  BOOST_CHECK_EQUAL( ++b, 1 );
  BOOST_CHECK_THROW( ++b, overflow_error* );
}

BOOST_AUTO_TEST_CASE( ASSIGN_TO_SMALL1 ) {
  safeint<1> a;
  safeint<2> b(-2);
  
  BOOST_CHECK_THROW( a = b, overflow_error* );
}


void dummy() {
   // // error
   // a = b;

    safeint<1> c(0);
    safeint<1> d(0);

    // returns a safeint<2>
    auto b = c+d;

    c = -1;
    d = -1;

    // good
    b = c+d;

    // overflow:
    // c = c+d;

    try {
        // overflow:
        c = d = 1;
    } catch (...) {

    }

    c = -1;
    d = 0;
    
    b = d - c;
    // b is 1 a safeint<2>.

    c * c; // is also a safeint<2>.
}