
== Installation.

If you use GNU, set the locations of boost in some profile (.bashrc) file like this:
```
export CPLUS_INCLUDE_PATH=/opt/boost_1_91_0/:/opt/libcsafe_0_0_0
export LIBRARY_PATH=/opt/boost_1_91_0/stage/lib:/opt/libcsafe_0_0_0
export LD_LIBRARY_PATH=/opt/boost_1_91_0/stage/lib:/opt/libcsafe_0_0_0
```



It will save you from always specifiying -I, and -L.



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


== ByteSafe

Use safe64.hpp and safe64.cpp.  The other classes are useful for understanding how operation results bit-lengths releate to the operands and if ever completed.  It helped me figure out how to do safe64. 
