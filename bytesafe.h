/*******************************

The library would give you 64 safe types.  In order to get binary operations working, 49 implementations for +,-, and / needed to be added to the header file:  These are all such operations that result in some value between -128 and 127 inclusive.  These correspond to all ordered numeric pairs where neither value exceeds 7.

Next, there would have to be a *shortsafe*, and similar implementations where all ordered numeric pairs where neither exceed 15 but where one of them does exceed 7.  This will be 98 such pairs and thus 98 implementations.

Then there would be a in32safe, 15*31 pairs to count the number of implementations for most binary operations.  This is already in the hundreds, and I haven't covered the cases that run up to 64 bits. 

For example: ```
bytesafe<3> a;
bytesafe<5> b;

// assignments to these go here.

a+b; // this is a bytesafe<6>.
a-b; // this also a bytesafe<6>.
a/b; // even this is a bytesafe<6>!


a*b; // this would be a btyesafe<8>.

```

There is no runtime checking needed in sums in the operations in bytesafe.  Although there is checking zero for division and for conversions into the other types.

A template is a mistake for sum, because it would allow for erroneous code.  So all of the binary operations have to implemented for all of the class combinations to return some kind of bytesafe object.

***********************************************/
#include <limits>
#include <stdexcept>


class overflow_error_with_short : public std::overflow_error {
public:
  signed short answer;  
  overflow_error_with_short(char * const msg, signed short ans) : overflow_error(msg) {
    answer = ans;
  }
};

static std::overflow_error overflow("larger than type");
static std::overflow_error negative_to_unsigned("negative to unsigned");
static std::domain_error divide_by_zero("divide by zero");

using namespace std;
#include <exception>
template <int n> class bytesafe {
    signed char data;
  public:
    inline static unsigned long int max() {
      return 1 << (n-1) - 1;
    }
    inline static signed long int min() {
      return - 1 << (n-1);
    }
    bytesafe(int);
    bytesafe(const bytesafe<n>& that);
    bytesafe<n>& operator = (const bytesafe<n>& that);
    explicit operator char () const {
      if (data < 0)
        throw &negative_to_unsigned;
    }
    explicit operator unsigned char() const {
      if (data < 0)
        throw &negative_to_unsigned;
    }
    explicit operator unsigned short() const {
      if (data < 0)
        throw &negative_to_unsigned;
    }
    operator signed short() const {
      return (signed short)data;
    }
    explicit operator unsigned int() const {
      if (data < 0)
        throw &negative_to_unsigned;
    }
    signed short operator - () const {
      return -(signed short)(data);
    }    
    template <int p, int m>
    friend bytesafe<((p > m ? p : m) + 1)> operator + (bytesafe<p> a, bytesafe<m> b);
};

#define implement_plus_to_safebyte(n,m) \
bytesafe<((n > m ? n : m) + 1)> operator + (bytesafe<n> a, bytesafe<m> b) {\
    signed short q = ((signed short)a)+((signed short)b);\
    bytesafe<((n > m ? n : m) + 1)> p(q);\
    return p;\
}\
bytesafe<((n > m ? n : m) + 1)> operator - (bytesafe<n> a, bytesafe<m> b) {\
    signed short q = ((signed short)a)-((signed short)b);\
    bytesafe<((n > m ? n : m) + 1)> p(q);\
    return p;\
}\
bytesafe<((n > m ? n : m) + 1)> operator / (bytesafe<n> a, bytesafe<m> b) {\
    signed short q = ((signed short)a)-((signed short)b);\
    bytesafe<((n > m ? n : m) + 1)> p(q);\
    return p;\
}

// template <int n, int m>
// signed short operator + (bytesafe<n> a, bytesafe<m> b) {
//     signed short q = ((signed short)a)+(signed short)b;
//     bytesafe<((n > m ? n : m) + 1)> p(q);
//     return p;
// }

// neither parameters greater than 7 
implement_plus_to_safebyte(1,1)
implement_plus_to_safebyte(1,2)
implement_plus_to_safebyte(1,3)
implement_plus_to_safebyte(1,4)
implement_plus_to_safebyte(1,5)
implement_plus_to_safebyte(1,6)
implement_plus_to_safebyte(1,7)

implement_plus_to_safebyte(2,1)
implement_plus_to_safebyte(2,2)
implement_plus_to_safebyte(2,3)
implement_plus_to_safebyte(2,4)
implement_plus_to_safebyte(2,5)
implement_plus_to_safebyte(2,6)
implement_plus_to_safebyte(2,7)


implement_plus_to_safebyte(3,1)
implement_plus_to_safebyte(3,2)
implement_plus_to_safebyte(3,3)
implement_plus_to_safebyte(3,4)
implement_plus_to_safebyte(3,5)
implement_plus_to_safebyte(3,6)
implement_plus_to_safebyte(3,7)

implement_plus_to_safebyte(4,1)
implement_plus_to_safebyte(4,2)
implement_plus_to_safebyte(4,3)
implement_plus_to_safebyte(4,4)
implement_plus_to_safebyte(4,5)
implement_plus_to_safebyte(4,6)
implement_plus_to_safebyte(4,7)

implement_plus_to_safebyte(5,1)
implement_plus_to_safebyte(5,2)
implement_plus_to_safebyte(5,3)
implement_plus_to_safebyte(5,4)
implement_plus_to_safebyte(5,5)
implement_plus_to_safebyte(5,6)
implement_plus_to_safebyte(5,7)


implement_plus_to_safebyte(6,1)
implement_plus_to_safebyte(6,2)
implement_plus_to_safebyte(6,3)
implement_plus_to_safebyte(6,4)
implement_plus_to_safebyte(6,5)
implement_plus_to_safebyte(6,6)
implement_plus_to_safebyte(6,7)

implement_plus_to_safebyte(7,1)
implement_plus_to_safebyte(7,2)
implement_plus_to_safebyte(7,3)
implement_plus_to_safebyte(7,4)
implement_plus_to_safebyte(7,5)
implement_plus_to_safebyte(7,6)
implement_plus_to_safebyte(7,7)
/*
template <int n, int m>
bytesafe<((n > m ? n : m) + 1)> operator + (bytesafe<n> a, bytesafe<m> b) {
    signed short q = ((signed short)a.data)+b.data;
    // this happens if we may overflow a signed byte
    if (n+m > 7) {
      if (q > 0x007f)
        throw new overflow_error_with_short("sum exceeds largest possible byte", q);
      else if (q < -0x0080)
        throw new overflow_error_with_short("sum is less than lowest possible byte", q);
    }    
    
    bytesafe<((n > m ? n : m) + 1)> p(q);
    return p;
}
*/
template <int n, int m>
bytesafe<((n > m ? n : m) + 1)> operator - (bytesafe<n> a, bytesafe<m> b) {
    signed short q = ((signed short)a.data)-b.data;
    // this happens if we may overflow a signed byte
    if (n+m > 7) {
      if (q > 0x007f)
        throw new overflow_error_with_short("difference exceeds largest possible byte", q);
      else if (q < -0x0080)
        throw new overflow_error_with_short("difference is less than lowest possible byte", q);
    }    
    
    bytesafe<((n > m ? n : m) + 1)> p(q);
    return p;
}




