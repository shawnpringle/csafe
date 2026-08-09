#include <stdexcept>
#include "csint.hpp"
#include <iostream>
#define generateBasicOps(T1, T2, T3) 0;

csint2_t operator - (csint1_t a, csint1_t b) {
    return (signed char)a - (signed char)b;
}
csint2_t operator / (csint1_t a, csint1_t b) {
    return (signed char)a / (signed char)b;
}
csint2_t operator * (csint1_t a, csint1_t b) {
    return (signed char)a * (signed char)b;
}

ostream& operator << (ostream& out, const csint1_t x) {
    return out << (const signed char)x;
}
ostream& operator << (ostream& out, const csint8_t& x) {
    return out << (signed char)x;
}
void nyi() {
    std::cerr << "Not yet implemented\n";
}

istream& operator >> (istream& in, csint1_t& x) {
    signed short c;
    in >> c;
    x = c;
    return in;
}

bool operator != (const csint1_t a, const csint1_t b) {
    return (signed char)a != (signed char)b;
}
bool operator == (const csint1_t a, const csint1_t b) {
    return (signed char)a == (signed char)b;
}
bool operator < (const csint1_t a, const csint1_t b) {
    return (signed char)a < (signed char)b;
}
bool operator <= (const csint1_t a, const csint1_t b) {
    return (signed char)a <= (signed char)b;
}
bool operator > (const csint1_t a, const csint1_t b) {
    return (signed char)a > (signed char)b;
}
bool operator >= (const csint1_t a, const csint1_t b) {
    return (signed char)a >= (signed char)b;
}

/*
#define implementBinaryByteBackedOps(T1, T2, T3) T3 operator + (T1 a, T2 b) {\
    csint2_t c(a);\
    csint2_t d(b);\
    return (a.data+b.data);\
}

implementBinaryByteBackedOps(csint1_t, csint1_t, csint2_t)
csint2_t operator - (csint1_t a, csint1_t b) {
    csint2_t c(a);
    csint2_t d(b);
    return (c-d);
}

csint2_t operator * (csint1_t a, csint1_t b);
csint2_t operator / (csint1_t a, csint1_t b);

     ostream& operator << (ostream& out, const csint1_t& i);
     istream& operator >> (istream& in, csint1_t& i);

     bool operator != (const csint1_t &a, const csint1_t& b);
     bool operator == (const csint1_t &a, const csint1_t& b);
     bool operator <= (const csint1_t &a, const csint1_t& b);
     bool operator >= (const csint1_t &a, const csint1_t& b);
     bool operator < (const csint1_t &a, const csint1_t& b);
     bool operator > (const csint1_t &a, const csint1_t& b);
*/


template<>
intbiggest_t csint1_t::max() {
  return 0;  
}
template<>
intbiggest_t csint2_t::max() {
  return 1;
}
template<>
intbiggest_t csint3_t::max() {
  return 3;
}
template<>
intbiggest_t csint4_t::max() {
  return 7;
}

template<>
intbiggest_t csint9_t::max() {
  return 255;
}

template<>
intbiggest_t csint1_t::min() {
  return -1;
}

template<>
intbiggest_t csint2_t::min() {
  return -2;
}
template<>
intbiggest_t csint3_t::min() {
  return -4;
}
template<>
intbiggest_t csint4_t::min() {
  return -8;
}


