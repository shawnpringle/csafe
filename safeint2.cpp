#include "safeint.h"
// generally speaking aritmetic should add one to the highest 
// order template.
// safeint<p> + safeint<q> => safeint<max(p,q)+1>
// And multiply should give us a sum type
// safeint<p> * safeint<q> => safeint<p+q>
// however this is so long as p+q does not exceed 8 bits
// because the implementation of using a single byte type.
// Now division only makes things smaller normally but 
// with the case of ::min() / -1 you would get something bigger
// thna the original type.  So in this case it is 
// safeint<p> / safeint<q> => safeint<p+1>

safeint<2> operator + (safeint<1> a, safeint<1> b) {
    // ramge is [-2, 0]
    safeint<2> c( a.data + b.data ); 
    return c;
}

safeint<2> operator - (safeint<1> a, safeint<1> b) {
    // domain [-1,0]x[-1,0] .  Range: [-1,1]
    safeint<2> c( a.data - b.data ); 
    return c;
}

safeint<2> operator * (safeint<1> a, safeint<1> b) {
    // domain [-1,0]x[-1,0] .  Range: [0,1]
    safeint<2> c( a.data * b.data ); 
    return c;
}

safeint<2> operator / (safeint<1> a, safeint<1> b) {
    // domain [-1,0]x[-1] .  Range: [0,1]
    if (b.data == 0) throw divide_by_zero;
    safeint<2> c( a.data / b.data ); 
    return c;
}

signed char safeint<2>::max() {
    return 1;
}

signed char safeint<2>::min() {
    return -2;
}

bool operator == (safeint<2> si, int64_t i) {
  return si.data == i;
}

bool operator == (int64_t i, safeint<2> si) {
  return i == si.data;
}