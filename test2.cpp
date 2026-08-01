#include "safeint.h"
#include <iostream>

int main() {

   safeint<2> a(-1);
   a++;   // okay.
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
   } catch (overflow_error* e) {
     // good
   }

   b = a;

   // // error
   // a = b;

    safeint<1> c(0);
    safeint<1> d(-1);

    // cast to safeint<2> (no check)
    b = c;
}