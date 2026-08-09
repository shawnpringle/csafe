#include "accuorg_binary.hpp"
#include <sstream>
#define BOOST_TEST_MODULE BinaryManip
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( BinaryManip10 ) {
  {
    std::ostringstream oss;
    
    oss << hex << 10;
    BOOST_CHECK_EQUAL( oss.str(), "a" );
    
    oss << dec << 10;
    BOOST_CHECK_EQUAL( oss.str(), "a10" );
    
    oss << bin << 10;
    BOOST_CHECK_EQUAL( oss.str(), "a101010" );
  }
}

BOOST_AUTO_TEST_CASE( BinaryManipM10 ) {
  {
      std::ostringstream oss;
      oss << bin << -10;
      BOOST_CHECK_EQUAL( oss.str(), "-1010");
  }
  
  {
      std::ostringstream oss;
      oss << hex << -10;
      BOOST_CHECK_EQUAL( oss.str(), "-a");
  }
  
  {
      std::ostringstream oss;
      oss << dec << -10;
      BOOST_CHECK_EQUAL( oss.str(), "-10");
  }
}

BOOST_AUTO_TEST_CASE( BinaryManipLimits ) {
  {
      // std::numeric_limits<int64_t>::max()
      // Should be 63 '1's.
      std::ostringstream oss;
      std::string s;
      for (int i = 0; i < 63; ++i) s += '1';
      oss << bin << std::numeric_limits<int64_t>::max();      
      BOOST_CHECK_EQUAL( oss.str(), s);
  }
  
  {
      // std::numeric_limits<int64_t>::max()
      // Should be 9223372036854775807 (=2^63 - 1)
      std::ostringstream oss;
      std::string s;
      for (int i = 0; i < 63; ++i) s += '1';
      oss << dec << std::numeric_limits<int64_t>::max();      
      BOOST_CHECK_EQUAL( oss.str(), "9223372036854775807");
  }
  
  {      
    // Should be '-1' and then 63 0s. 
      std::ostringstream oss;
      std::string s = "-1";
      for (int i = 0; i < 63; ++i) s += '0';
      oss << bin << std::numeric_limits<int64_t>::min();
      BOOST_CHECK_EQUAL( oss.str(), s );
  }
  
  {      
      // Should be -(2^63) 
      std::ostringstream oss;
      oss << dec << std::numeric_limits<int64_t>::min();
      BOOST_CHECK_EQUAL( oss.str(), "-9223372036854775808");
  }
}

BOOST_AUTO_TEST_CASE( FillAndWidth ) {
  {      
      std::ostringstream oss;
      oss << std::setw(5) << std::setfill('*') << bin << 10;
      BOOST_CHECK_EQUAL( oss.str(), "*1010" );
  }
  
  {      
      std::ostringstream oss;
      oss << std::setw(5) << std::setfill('*') << hex << 10;
      BOOST_CHECK_EQUAL( oss.str(), "****a" );
  }
  
  
  {      
      std::ostringstream oss;
      oss << std::setw(5) << std::setfill('*') << hex << 10;
      BOOST_CHECK_EQUAL( oss.str(), "****a" );
  }
  {
    std::ostringstream oss;
    oss << std::setw(8) << std::setfill('*') << dec << 10;
    BOOST_CHECK_EQUAL( oss.str(), "******10" );
  }
  
  {
    std::ostringstream oss;
    oss << std::setw(8) << std::setfill('*') << bin << 20;
    BOOST_CHECK_EQUAL( oss.str(), "***10100" );
  }

  {
    std::ostringstream oss;
    oss << std::setw(8) << std::setfill('*') << bin << 40;
    BOOST_CHECK_EQUAL( oss.str(), "**101000" );
  }

}