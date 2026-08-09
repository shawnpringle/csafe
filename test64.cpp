#include "safe64.h"
 #define BOOST_TEST_MODULE Safe64Test
 #define BOOST_TEST_DYN_LINK
 #include <boost/test/unit_test.hpp>



BOOST_AUTO_TEST_CASE( Safe64Test )
{
    safe64_t a(4'000'000'000);

    safe64_t max64(safe64_t::max());
    safe64_t g(safe64_t::min());
    safe64_t(0LL) - max64;
    // cout << "0 minus the largest safe64_t is ";
    // cout << (safe64_t(0) - c) << endl;
    BOOST_CHECK_EQUAL( safe64_t(0) - max64, safe64_t(-9223372036854775807LL));

    BOOST_CHECK_THROW(-g, std::overflow_error *);
    
    BOOST_CHECK_THROW(max64*max64, std::overflow_error *);

    BOOST_CHECK_THROW(a*a, std::overflow_error *);

    int64_t d((1LL << 32) - 1);
    int64_t e((1LL << 31) - 1);
    safe64_t b(d);
    safe64_t c(e);

    BOOST_CHECK_EQUAL(b*c, safe64_t(e*d));
    BOOST_CHECK_EQUAL((int64_t)(b*c), e*d);
    BOOST_CHECK_EQUAL(d*e, 9223372030412324865LL);
         
    b = safe64_t(-4611686018427387904LL);
    c = safe64_t(2);
    BOOST_CHECK_EQUAL(b*c, safe64_t(-9'223'372'036'854'775'808LL));
  
    BOOST_CHECK_EQUAL((int64_t)-9'223'372'036'854'775'808LL, (int64_t)-0x8000'0000'0000'0000);
    BOOST_CHECK_EQUAL(4294967296 & 4294967296, 4294967296);
    BOOST_CHECK_EQUAL(2251799813685248 & 2251799813685248, 2251799813685248);
}



