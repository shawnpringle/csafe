#include <limits>
#include <stdexcept>
#include <cstdint>
#include <iostream>
#include <set>
#include <string>



short log2(int64_t a);

class overflow_error_with_short : public std::overflow_error {
  // for now, the only key looked for is 'operator *'
public:
  
  signed short answer;  
  overflow_error_with_short(char * const msg, signed short ans) : overflow_error(msg) {
    answer = ans;
  }
};

extern std::overflow_error overflow;
extern std::overflow_error negative_to_unsigned;
extern std::domain_error divide_by_zero;

using namespace std;
#include <exception>

class safe64_t {
    int64_t data;
  public:
    static bool debug_log2;
    static bool debug_multiply;
    inline static unsigned long int max() {
      return std::numeric_limits<int64_t>::max();
    }
    inline static signed long int min() {
      return std::numeric_limits<int64_t>::min();
    }
    safe64_t(int64_t i) : data(i) {}
    safe64_t(const safe64_t& that) : data(that.data) {}
    safe64_t& operator = (const safe64_t& that);
    static int64_t power2(unsigned short);
    explicit inline operator char () const {
      if (data < -0x80)
        throw &negative_to_unsigned;
      if (data > 0x7f)
        throw &overflow;
      return data;
    }
    explicit inline operator signed char () const {
      if (data < -0x80)
        throw &negative_to_unsigned;
      if (data > 0x7f)
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > 0xff)
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > 0xffff)
        throw &overflow;
      return data;
    }
    explicit operator signed short() const {
      if (data > 0x7fff)
        throw &overflow;
      if (data < -(int64_t)0x00008000)
        throw &overflow;
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned int>::max())
        throw &overflow;
      return data;
    }
    explicit operator int64_t() const {
      return data;
    }
    explicit operator uint64_t() const {
      if (data < 0)
        throw &negative_to_unsigned;
      return (uint64_t)data;
    }
    safe64_t operator - () const {
      if (data == std::numeric_limits<int64_t>::min())
        throw &overflow;
      return safe64_t(-data);
    }
    friend safe64_t operator + (safe64_t a, safe64_t b);
    friend safe64_t operator - (safe64_t a, safe64_t b);
    friend safe64_t operator / (safe64_t a, safe64_t b);
    friend safe64_t operator * (const safe64_t& a, const safe64_t& b);
    friend ostream& operator << (ostream& out, const safe64_t& i);
    friend istream& operator >> (istream& in, safe64_t& i);

    friend bool operator != (const safe64_t &a, const safe64_t& b);
    friend bool operator == (const safe64_t &a, const safe64_t& b);
    friend bool operator <= (const safe64_t &a, const safe64_t& b);
    friend bool operator >= (const safe64_t &a, const safe64_t& b);
    friend bool operator < (const safe64_t &a, const safe64_t& b);
    friend bool operator > (const safe64_t &a, const safe64_t& b);
};

extern ostream& operator << (ostream& out, const safe64_t& i);
extern istream& operator >> (istream& in, safe64_t& i);