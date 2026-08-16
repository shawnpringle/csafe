#include <assert.h>
#include "safe64.h"
std::overflow_error overflow("larger than type");
std::overflow_error negative_to_unsigned("negative to unsigned");
std::domain_error divide_by_zero("divide by zero");

bool safe64_t::debug_log2(false);
bool safe64_t::debug_multiply(false);

ostream& display_binary(ostream& out, int64_t i) {
  union {
    struct {
      uint32_t low;
      uint32_t high;
    } u32;
    uint64_t u64;
    int64_t s64;
  } v, m;
  v.s64 = i;

  out << "0b";
  uint32_t sb = 2147483648;
  for (short log2v = 31; log2v >= 0; --log2v) {
    if (v.u32.high & sb)
      out << '1';
    else
      out << '0';
    sb /= 2;
  }
  sb = 2147483648;
  for (short log2v = 31; log2v >= 0; --log2v) {
    if (v.u32.low & sb)
      out << '1';
    else
      out << '0';
    sb /= 2;
  }
  return out; 
}

short log2(int64_t a) {
    short alog = 63;
    if (a != std::numeric_limits<int64_t>::min()) {
      int64_t absa = abs(a);
      if (safe64_t::debug_log2) {
        cerr << a << " => " << absa << endl;
      }
      alog = 62;
      int64_t amask = 1LL << alog;
      while ((amask & absa) == 0 && amask) {
        if (safe64_t::debug_log2) {
          cerr << "amask = " << hex << amask << ", alog = " << dec << alog << endl;
        }
        amask >>= 1;
        alog --;
      }
      if (safe64_t::debug_log2) cerr << "alog is " << alog << endl;
    }
    if (safe64_t::debug_log2 && safe64_t::power2(alog) & a == 0) {
      cout << "0x" << hex << a << endl;
      display_binary(cout, a) << endl;
      display_binary(cout, safe64_t::power2(alog)) << endl;
    }
    return alog;  
}

safe64_t operator * (const safe64_t& a, const safe64_t& b) {
  #if __GNUG__
  // this non-standard type simplifies this sooo much.
  __int128 c128(__int128(a.data)*__int128(b.data));
  if (__int128(safe64_t::min()) <= c128 && c128 <= __int128(safe64_t::max()))
    return safe64_t((int64_t)c128);
  else
    throw &overflow;
  #else
  #error  not implemented
  #endif
}

safe64_t& safe64_t::operator = (const safe64_t& that) {
  data = that.data;
  return *this;
}

safe64_t operator + (safe64_t a, safe64_t b) {
    int64_t c = a.data+b.data;
  if ((a.data ^ b.data) >= 0) {
    // same sign
    if (c ^ a.data < 0) {
      // sign reversal indicates overflow in either direction.
      throw &overflow;
    }
  } // differing signs can only result in a lower absolute value than the addend with the largest absolute value. 
  return safe64_t(c);
}

safe64_t operator - (safe64_t a, safe64_t b) {
  int64_t c = a.data-b.data;
  if ((a.data ^ b.data) < 0) {
    // differing signs
    if (c ^ a.data < 0) {
      // sign of the difference being different than the first subend indicates overflow in either direction.
      throw &overflow;
    }
  } // same signs can only result in a lower absolute value than the subend with the largest absolute value. 
  return safe64_t(c);
}

safe64_t operator / (safe64_t a, safe64_t b) {
  if (b.data == 0) {
    throw &divide_by_zero;
  }
  if (b.data == std::numeric_limits<int64_t>::min() && b.data == -1) {
    throw &overflow;
  }
  return safe64_t(a/b);
}


ostream& operator << (ostream& out, const safe64_t& i) {
  return out << i.data;
}

istream& operator >> (istream& in, safe64_t& i) {
  return in >> i.data;
}

#define defineOP(op) bool operator op (const safe64_t &a, const safe64_t& b) {\
return a.data op b.data;\
}

defineOP(!=)
defineOP(==)
defineOP(<=)
defineOP(>=)
defineOP(<)
defineOP(>)

#undef defineOP
#define defineOP(op) safe64_t operator op (const safe64_t &a, const safe64_t& b) {\
  return (int64_t)a op (int64_t)b;\
}

defineOP(||)
defineOP(|)
defineOP(&&)
defineOP(&)
defineOP(^)


int64_t safe64_t::power2(unsigned short a) {
  if (a > 63) throw &overflow;
  uint64_t v(1);
  while (a) {
    v*=2;
    --a;
  }
  return v;
}

#undef defineOP
