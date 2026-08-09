#include <limits>
#include <stdexcept>
#include <cstdint>
#include <iostream>
static std::underflow_error negative_to_unsigned("negative to unsigned");
static std::overflow_error overflow("larger than type maximum");
static std::underflow_error underflow("less than type minimum");
static std::domain_error divide_by_zero("divide by zero");
static std::domain_error invalid_class("invalid class");
using namespace std;
#include <exception>

typedef intmax_t intbiggest_t;


class bytebearer_t {
    protected:
    signed char data;
    public:
    bytebearer_t( signed char c ) : data(c) {}
    explicit operator signed char () const {
        return data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator const unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed short() const {
      if (data < std::numeric_limits<signed short>::min())
        throw &underflow;
      if (data > std::numeric_limits<signed short>::max())
        throw &overflow;
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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

};

template <class T>
class Tbearer_t {
    protected:
    T data;
    public:
    Tbearer_t( T  s ) : data(s) {}
    explicit inline operator char () const {
      if (data < std::numeric_limits<char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<char>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator const unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed short() const {
      if (data < std::numeric_limits<signed short>::min())
        throw &underflow;
      if (data > std::numeric_limits<signed short>::max())
        throw &overflow;
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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
};

class shortbearer_t {
    protected:
    signed short data;
    public:
    shortbearer_t( signed short  s ) : data(s) {}
    explicit operator signed short () const {
        return data;
    }
    explicit inline operator char () const {
      if (data < std::numeric_limits<char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<char>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator const unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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
};

class int32bearer_t {
  protected:
    int32_t data;
  public:    
  int32bearer_t( int32_t i ) : data(i) {}
    explicit inline operator char () const {
      if (data < std::numeric_limits<char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<char>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator const unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed short() const {
      if (data < std::numeric_limits<signed short>::min())
        throw &underflow;
      if (data > std::numeric_limits<signed short>::max())
        throw &overflow;
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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
public:    
    explicit operator signed int() const {
      return data;
    }
};

class int64bearer_t {
  protected:
    int64_t data;
  public:
  int64bearer_t( int64_t i ) : data(i) {}
    explicit inline operator char () const {
      if (data < std::numeric_limits<char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<char>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator const unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator const unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned short>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed short() const {
      if (data < std::numeric_limits<signed short>::min())
        throw &underflow;
      if (data > std::numeric_limits<signed short>::max())
        throw &overflow;
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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
};

class fcs64_t : public int64bearer_t {
  typedef fcs64_t thistype;
  typedef fcs64_t sumtype;
  typedef fcs64_t producttype;
  static void valid_class() {
    // do nothing
  }
  public:
#if __GNUG__
    fcs64_t(const __int128_t x) : int64bearer_t((int64_t)x)  {
      valid_class();
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
#else
    fcs64_t(const intmax_t x) : int64bearer_t((signed char)x)  {
        valid_class();
        if (x > max()) throw &overflow;
        if (x < min()) throw &underflow;
    }
#endif
  static intbiggest_t max() {
    return std::numeric_limits<int64_t>::max();
  }
  static intbiggest_t min() {
    return std::numeric_limits<int64_t>::min();
  } 
  fcs64_t operator - () const {
    if (data == std::numeric_limits<int64_t>::min()) {
      throw &overflow;
    }
    fcs64_t s(-data);
    return s;
  }
#define implementUnaryOps \
    thistype& operator = (const thistype& that) {\
        data = that.data;\
        return *this;\
    }\
    thistype operator ++ () {\
        if (data == max()) {\
            throw &overflow;\
        }\
        data += 1;\
        return *this;\
    }\
    // post
    thistype operator ++ (int) {\
        if (data >= max()) {\
            throw &overflow;\
        }\
        thistype save(*this);\
        data += 1;\
        return save;\
    }\
    thistype operator --() {\
        if (data <= min()) {\
            throw &underflow;\
        }\
        --data;\
        return *this;\
    }\
    thistype operator --(int) {\
        thistype saved(*this);\
        if (data <= min()) {\
            throw &underflow;\
        }\
        --data;\
        return saved;\
    }

    implementUnaryOps
};


template <int n>
class ecs646464i : public int64bearer_t {
    typedef ecs646464i<n> thistype;
    typedef ecs646464i<n+1> sumtype;
    typedef ecs646464i<64> producttype;
    static void valid_class() {
      if (n < 1 || n > 63) {
        throw &invalid_class;
      }
    }
    public:
    #define implementExtremeOps(k) \
    static intbiggest_t max() { \
      valid_class();\
      return (1LL << (k-1)) - 1;\
    }\
    static intbiggest_t min() {\
      valid_class();\
      return -(1LL << (k - 1));\
    }
    implementExtremeOps(n)
#if __GNUG__
    ecs646464i(const __int128_t x) : int64bearer_t((int64_t)x)  {
      valid_class();
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
#else
    ecs646464i(const intmax_t x) : int64bearer_t((int64_t)x)  {
        valid_class();
        if (x > max()) throw &overflow;
        if (x < min()) throw &underflow;
    }
#endif
    ecs646464i(const thistype& that) : int64bearer_t(that.data)  {
    }
    template <int m>
    ecs646464i(const ecs646464i<m>& that ) : int64bearer_t((signed char)that) {
      valid_class();
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    implementUnaryOps
    sumtype operator - () const {\
        sumtype s(this);\
        return -s;\
    }
};


template <int n>
class ecs323232i : public int32bearer_t {
    typedef ecs323232i<n> thistype;
    typedef ecs323232i<n+1> sumtype;
    typedef ecs323232i<2*n> producttype;
    static void valid_class() {
      if (n < 1 || n > 32) {
        throw &invalid_class;
      }
    }
    public:
    static intbiggest_t max() {
      valid_class();
      return (1LL << n) - 1;
    }
    static intbiggest_t min() {
      valid_class();
      return -(1LL << (n - 1));
    }
#if __GNUG__
    ecs323232i(const __int128_t x) : int32bearer_t((int32_t)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
#else
    ecs323232i(const intmax_t x) : int32bearer_t((int32_t)x)  {
        if (x > max()) throw &overflow;
        if (x < min()) throw &underflow;
    }
#endif
    ecs323232i(const thistype& that) : int32bearer_t(that.data)  {
    }
    template <int m>
    ecs323232i(const ecs323232i<m>& that ) : int32bearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    implementUnaryOps
    sumtype operator - () const {      
        sumtype s(-data);
        return s;
    }
};



template <int n>
class ecssssi : public shortbearer_t {
    typedef ecssssi<n> thistype;
    typedef ecssssi<n+1> sumtype;
    typedef ecssssi<2*n> producttype;
    static void valid_class() {
      if (n < 1 || n > 8) {
        throw &invalid_class;
      }
    }
    public:
    implementExtremeOps(n)
#if __GNUG__
    ecssssi(const __int128_t x) : shortbearer_t((signed char)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
#else
    ecssssi(const intmax_t x) : shortbearer_t((signed char)x)  {
        if (x > max()) throw &overflow;
        if (x < min()) throw &underflow;
    }
#endif
    ecssssi(const thistype& that) : shortbearer_t(that.data)  {
    }
    template <int m>
    ecssssi(const ecssssi<m>& that ) : shortbearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    thistype& operator = (const thistype& that) {
        data = that.data;
        return *this;
    }
    // pre
    thistype operator ++ () {
        if (data == max()) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    thistype operator ++ (int) {
        if (data >= max()) {
            throw &overflow;
        }
        thistype save(*this);
        data += 1;
        return save;
    }
    thistype operator --() {
        if (data <= min()) {
            throw &underflow;
        }
        --data;
        return *this;
    }
    thistype operator --(int) {
        thistype saved(*this);
        if (data <= min()) {
            throw &underflow;
        }
        --data;
        return saved;
    }

    explicit inline operator char () const {
      if (data < std::numeric_limits<char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<char>::max())
        throw &overflow;
      return data;
    }
    explicit inline operator signed char () const {
      if (data < std::numeric_limits<signed char>::min())
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<signed char>::max())
        throw &overflow;
      return (signed char)data;
    }
    explicit inline operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
      if (data > std::numeric_limits<unsigned char>::max())
        throw &overflow;
      return (unsigned char)data;
    }
    explicit inline operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
      return data;
    }
    explicit operator signed short() const {
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
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
    sumtype operator - () const {      
        sumtype s(this);
        return -s;
    }
};

template <int n>
class ecsbbbi : public bytebearer_t {
    typedef ecsbbbi<n> thistype;
    typedef ecsbbbi<n+1> sumtype;
    typedef ecsbbbi<2*n> producttype;
    public:
    static void valid_class() {
      if (n < 1 || n > 4) {
        throw &invalid_class;
      }
    }

    static intbiggest_t max() {
      if (n <= 8)
        return (1LL << n) - 1;
      else
        throw &overflow;

    }
    static intbiggest_t min() {
      if (n <= 8)
        return -(1LL << (n - 1));
      else
        throw &underflow;
    }
#if __GNUG__
    ecsbbbi(const __int128_t x) : bytebearer_t((signed char)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
#else
    ecsbbbi(const intmax_t x) : bytebearer_t((signed char)x)  {
        if (x > max()) throw &overflow;
        if (x < min()) throw &underflow;
    }
#endif
    ecsbbbi(const thistype& that) : bytebearer_t(that.data)  {
    }
    template <int m>
    ecsbbbi(const ecsbbbi<m>& that ) : bytebearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    thistype& operator = (const thistype& that) {
        data = that.data;
        return *this;
    }
    // pre
    thistype operator ++ () {
        if (data == max()) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    thistype operator ++ (int) {
        if (data >= max()) {
            throw &overflow;
        }
        thistype save(*this);
        data += 1;
        return save;
    }
    thistype operator --() {
        if (data <= min()) {
            throw &underflow;
        }
        --data;
        return *this;
    }
    thistype operator --(int) {
        thistype saved(*this);
        if (data <= min()) {
            throw &underflow;
        }
        --data;
        return saved;
    }
    sumtype operator - () const {      
        sumtype s(-data);        
        return s;
    }
};



typedef ecsbbbi<1> csint1_t;
typedef ecsbbbi<2> csint2_t;
typedef ecsbbbi<3> csint3_t;
typedef ecsbbbi<4> csint4_t;

template <int n>
class ecsbbsi : public bytebearer_t {
    typedef ecsbbsi<n> thistype;
    typedef ecsbbsi<n+1> sumtype;
    typedef ecssssi<2*n> producttype;
  public:
    static void valid_class() {
      if (n < 1 || n > 8) {
        throw &invalid_class;
      }
    }
    implementExtremeOps(n)
    ecsbbsi(const intmax_t x) : bytebearer_t((signed char)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
    ecsbbsi(const thistype& that) : bytebearer_t(that.data)  {
    }
    template <int m>
    ecsbbsi(const ecsbbsi<m>& that ) : bytebearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    template <int m>
    ecsbbsi(const ecsbbbi<m>& that ) : bytebearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    implementUnaryOps
    sumtype operator - () const {
        sumtype s(-data);
        return s;
    }

};
template <int n>
ostream& operator << (ostream& out, const ecsbbsi<n>& i);

typedef ecsbbsi<5> csint5_t;
typedef ecsbbsi<6> csint6_t;
typedef ecsbbsi<7> csint7_t;


class ecsint8_t : public bytebearer_t {
    typedef ecsint8_t thistype;
    typedef ecssssi<9> sumtype;
    typedef ecssssi<16> producttype;
  public:
    static void valid_class() {
    }
    implementExtremeOps(8)
    ecsint8_t(const intmax_t x) : bytebearer_t((signed char)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
    ecsint8_t(const thistype& that) : bytebearer_t(that.data)  {
    }
    template <int m>
    ecsint8_t(const ecsbbbi<m>& that ) : bytebearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    template <int m>
    ecsint8_t(const ecsbbsi<m>& that ) : bytebearer_t((signed char)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    implementUnaryOps
    sumtype operator - () const {
        sumtype s(-data);
        return s;
    }
};


template <int n>
class ecsss32i : public shortbearer_t {
    typedef ecsss32i<n> thistype;
    typedef ecssssi<n+1> sumtype;
    typedef ecssssi<2*n> producttype;
  public:
    static void valid_class() {
      if (n < 1 || n > 15)
        throw &invalid_class;
    }
    implementExtremeOps(n)
    ecsss32i(const intmax_t x) : shortbearer_t((signed short)x)  {
        if (x > thistype::max()) throw &overflow;
        if (x < thistype::min()) throw &underflow;
    }
    ecsss32i(const thistype& that) : shortbearer_t(that.data)  {
    }
    template <int m>
    ecsss32i(const ecsss32i<m>& that ) : shortbearer_t((signed short)that) {
      if (data > thistype::max()) throw &overflow;
      if (data < thistype::min()) throw &underflow;
    }
    sumtype operator - () const {
        sumtype s(-data);
        return s;
    }    
    implementUnaryOps
};
typedef ecsint8_t csint8_t;
typedef ecsss32i<9> csint9_t;
typedef ecsss32i<10> csint10_t;
typedef ecsss32i<11> csint11_t;
typedef ecsss32i<12> csint12_t;
typedef ecsss32i<13> csint13_t;
typedef ecsss32i<14> csint14_t;
typedef ecsss32i<15> csint15_t;

typedef ecs323232i<16> csint16_t;

typedef ecs646464i<17> csint17_t;
typedef ecs646464i<18> csint18_t;
typedef ecs646464i<19> csint19_t;
typedef ecs646464i<20> csint20_t;
typedef ecs646464i<21> csint21_t;
typedef ecs646464i<22> csint22_t;
typedef ecs646464i<23> csint23_t;
typedef ecs646464i<24> csint24_t;
typedef ecs646464i<25> csint25_t;
typedef ecs646464i<26> csint26_t;
typedef ecs646464i<27> csint27_t;
typedef ecs646464i<28> csint28_t;
typedef ecs646464i<29> csint29_t;
typedef ecs646464i<30> csint30_t;
typedef ecs646464i<31> csint31_t;
typedef ecs646464i<32> csint32_t;
typedef ecs646464i<33> csint33_t;
typedef ecs646464i<34> csint34_t;
typedef ecs646464i<35> csint35_t;
typedef ecs646464i<36> csint36_t;
typedef ecs646464i<37> csint37_t;
typedef ecs646464i<38> csint38_t;
typedef ecs646464i<39> csint39_t;
typedef ecs646464i<40> csint40_t;
typedef ecs646464i<41> csint41_t;
typedef ecs646464i<42> csint42_t;
typedef ecs646464i<43> csint43_t;
typedef ecs646464i<44> csint44_t;
typedef ecs646464i<45> csint45_t;
typedef ecs646464i<46> csint46_t;
typedef ecs646464i<47> csint47_t;
typedef ecs646464i<48> csint48_t;
typedef ecs646464i<49> csint49_t;
typedef ecs646464i<50> csint50_t;
typedef ecs646464i<51> csint51_t;
typedef ecs646464i<52> csint52_t;
typedef ecs646464i<53> csint53_t;
typedef ecs646464i<54> csint54_t;
typedef ecs646464i<55> csint55_t;
typedef ecs646464i<56> csint56_t;
typedef ecs646464i<57> csint57_t;
typedef ecs646464i<58> csint58_t;
typedef ecs646464i<59> csint59_t;
typedef ecs646464i<60> csint60_t;
typedef ecs646464i<61> csint61_t;
typedef ecs646464i<62> csint62_t;
typedef ecs646464i<63> csint63_t;
typedef fcs64_t csint64_t;



template <int n, int m>
bool operator != (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) != (signed char)(b));  
}
template <int n, int m>
bool operator == (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) == (signed char)(b));  
}
template <int n, int m>
bool operator < (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) < (signed char)(b));  
}
template <int n, int m>
bool operator > (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) > (signed char)(b));  
}
template <int n, int m>
bool operator <= (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) <= (signed char)(b));  
}
template <int n, int m>
bool operator >= (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  return ((signed char)(a) >= (signed char)(b));  
}


// Output
// ecsbbbi<1>..<4> t_csint1_t..t_csint4_t
template <int n>
ostream& operator << (ostream& out, const ecsbbbi<n>& i) {
  out << (int)(signed char)i;
  return out;
}
// ecsbbsi<5>..<7> t_csint5_t..t_csint7_t
template <int n>
ostream& operator << (ostream& out, const ecsbbsi<n>& i) {
  out << (int)(signed char)i;
  return out;
}
inline ostream& operator << (ostream& out, const csint8_t i) {
  out << (int)(signed char)i;
  return out;
}
// csint9_t..csint15_t
template <int n>
ostream& operator << (ostream& out, const ecsss32i<n>i) {
  out << (signed short)i;
  return out;
}
inline ostream& operator << (ostream& out, const csint16_t& i) {
  out << (signed int)i;
  return out;
}
// csint17_t..csint63_t
template <int n>
ostream& operator << (ostream& out, const ecs646464i<n>& i) {
  out << (int64_t)i;
  return out;
}
inline ostream& operator << (ostream& out, const csint64_t& i) {
  out << (int64_t)i;
  return out;
}



// Input

#define writeFromStreamTo(templateName) \
template <int n>\
istream& operator >> (istream& in, templateName<n>& i) {\
  intmax_t x;\
  in >> x;\
  i = templateName<n>(x);\
  return in;\
}
writeFromStreamTo(ecsbbbi)
// ecsbbsi<5>..<7> t_csint5_t..t_csint7_t
writeFromStreamTo(ecsbbsi)

inline istream& operator >> (istream& in, csint8_t& i) {
  intmax_t s;
  in >> s;
  csint8_t x((signed char)s);
  i = x;
  return in;
}

// csint9_t..csint15_t
writeFromStreamTo(ecsss32i)

inline istream& operator >> (istream& in, csint16_t& i) {
  intmax_t s;
  in >> s;
  csint16_t x(s);
  i = x;
  return in;
}
// csint17_t..csint63_t
writeFromStreamTo(ecs646464i)

inline istream& operator >> (istream& in, csint64_t& i) {
  intmax_t s;
  in >> s;
  csint64_t x(s);
  i = x;
  return in;
}



template <int n, int m>
ecssssi<std::max(n,m)+1> operator + (const ecsbbbi<n> a, const ecsbbbi<m> b) {
  if (std::max(n,m)+1 > 16) throw &overflow;
  ecssssi<std::max(n,m)+1> c((signed short)(signed char)a + (signed short)(signed char)b);
  return c;
}

ecsbbbi<2> operator + (const ecsbbbi<1> a, const ecsbbbi<1> b);
static inline ecsbbbi<3> operator + (const ecsbbbi<2> a, const ecsbbbi<1> b) {
  return ecsbbbi<3>((signed char)a + (signed char)b);
}
static inline ecsbbbi<3> operator + (const ecsbbbi<1> a, const ecsbbbi<2> b) {
  return ecsbbbi<3>((signed char)a + (signed char)b);
}
static inline ecsbbbi<3> operator + (const ecsbbbi<2> a, const ecsbbbi<2> b) {
  return ecsbbbi<3>((signed char)a + (signed char)b);
}