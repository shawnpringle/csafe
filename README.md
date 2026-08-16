
== Installation.

If you use GNU, set the locations of boost in some profile (.bashrc) file like this:

```
export CPLUS_INCLUDE_PATH=/opt/boost_1_91_0/:/opt/libcsafe_0_0_0
export LIBRARY_PATH=/opt/boost_1_91_0/stage/lib:/opt/libcsafe_0_0_0
export LD_LIBRARY_PATH=/opt/boost_1_91_0/stage/lib:/opt/libcsafe_0_0_0
```
It will save you from always specifiying -I, and -L.
Build the libcsafe_0_0_0 library.  You should put that in some directory.  The directory /opt/libcsafe_0_0_0
might not be a bad choice.  You should put the header files in the same directory if you use
the configuration above. 

== The overflow problem in C++

Depending on your type and value of a variable or variables, the result may be mathematically incorrect.
```
int a = std::numeric_limits<int>::max();  
// a is a very large positive number

++a;
// now it is a very large negative number
```

The idea is that numbers should throw an exception should this happen.  Stop what you're doing, and fail.


== Safe64

Safe64 prevent overflows from being used as correct values.  If you the CPU will give you some mathematically incorrect result, the library will throw an exception.  Unlike the 
the larger project, ByteSafe, Safe64 uses a signed 64 bit number underneath and throws exceptions when a new value to be assigned is impossible.  

For example
```
// okay.
safe64_t c = std::numeric_limits<int64_t>::min();

// throws an exception.
-c;
```

```
// okay.
c = -1;

// throws an exception.
(uint64_t)c;
```

```
// okay.
c = safe64_t( std::numeric_limits<int64_t>::max() );
// okay
-c;
```

Design decisions:  operator - () can be made to always suceed if it returns a int128_t.  In fact, if that was the 
return type for all operations then we don't need exceptions but we would need safe128_t to protect from being implicitly cast to smaller sized values and passing truncated values.


== Correct Signed Integer types.

Instead of only a single type we have csint1_t all the way up to csint64_t.  These are all signed integers
but behave like integers with that many bits except you will get an exception rather than an wraparound .

csint64_t is like safe64_t:
```
#include "csint.hpp"
csint64_t a, b;
a = 5;
b = 6;

a+b; // evaluates to a csint64_t (or throws exception if too large in either positive or negative)
a/b; // csint64_t
a*b; // csint64_t
a-b; // csint64_t
```

These results fit in a csint64_t, but when results are too high or too low for a variable to hold,
an exception is thrown.


```
#include "csint.hpp"
// a holds between -2^22 and 2^22-1.
csint23_t a = 3'231'231;
// a holds between -2^33 and 2^33-1.
csint33_t b = 65'231'123'671;

a+b; // is of type csint34_t.  There is no possibility of throwing exceptions here.
-a; // returns a csint24_t;

a*a; // returns a csint46_t !
a/a; // returns a csint24_t 
```

In these examples since they are not 64 bit themselves, the result will return a type big enough to hold it in the worst case scenario.  So by starting with types which are tiny enough you can throw exceptions where the erroneous data is entered.   I suggest you sanitize inputs as well though.  
```
#include <iostream>
#include <iomanip>
#include "csint.hpp"
using namespace std;
int main() {
  const csint12_t current_year = 2026;
  csint12_t yob; // allows -2048 (2049 BC) <= yob < 2048
  std::cout << "Enter your year of birth:" << flush; 
  std::cin >> yob;

  auto age = current_year - yob;   
  std::cout << "Your age is " << age << endl;   
}
```

Underneath, csint1_t to csint8_t use signed char
