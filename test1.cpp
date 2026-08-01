#include "safeint.h"
#include <iostream>

int main() {

   safeint<1> a(-1);
   a++;   // okay.
   try {
     a++;   // exception thrown.
     cerr << "Error.  An exception should have been thrown here." << endl;
   } catch (overflow_error* e) {
     // good
   } catch (...) {
     // overflow exception
   }

   safeint<2> b(-2);
   ++b;
   b++;
   ++b;
   try {
    ++b;
    cerr << "Error.  An exception should have been thrown here." << endl;
   } catch (...) {

   }

   b = a;

   // // error
   // a = b;

    safeint<1> c(0);
    safeint<1> d(0);

    // returns a safeint<2>
    b = c+d;

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