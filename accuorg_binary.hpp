// Modified from:
// https://accu.org/journals/overload/11/55/kuehl_350/

#include <iostream>
#include <locale>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cstdint>

template <typename cT, typename OutIt>
class bin_num_put: public
std::num_put<cT, OutIt> {
  OutIt do_put(OutIt to,
               std::ios_base& fmt,
               cT fill,
               std::intmax_t v) const;

  OutIt do_put(OutIt to,
               std::ios_base& fmt,
               cT fill,
               std::uintmax_t v) const;
};


namespace accu_org {
  template <typename T,
    int sz> T* begin(T (&a)[sz]){
    return a;
  }

  template <typename T,
            int sz> T* end(T (&a)[sz]) {
    return a + sz;
  }
}

static int base_index =
                std::ios_base::xalloc();
                

template <typename cT, typename OutIt>
OutIt
bin_num_put<cT, OutIt>::do_put(OutIt to,
                  std::ios_base& fmt,
                  cT fill,
                  std::uintmax_t v) const {
  char narrow[] = "0123456789abcdef";
  cT wide[16] = { 0 };
  std::use_facet<std::ctype<cT> >(
        fmt.getloc()).widen(std::begin(narrow),
        std::end(narrow) - 1, accu_org::begin(wide));
  cT buffer[sizeof(v)*8];
  std::fill(accu_org::begin(buffer), accu_org::end(buffer),
                                fill);
  int base = fmt.iword(base_index);
  for (cT* it = buffer + sizeof(v)*8
       ; v != 0
       ; v /= base)
    *--it = wide[v % base];
  auto minWidth = fmt.width();
  fmt.width(0);
  if (minWidth < 1) minWidth = 1;
  if (minWidth > sizeof(v)*8)
    minWidth = sizeof(v)*8;    
    
  auto firstPositive = accu_org::begin(buffer);
  while (*firstPositive == fill && firstPositive <  accu_org::end(buffer)-minWidth) {
    ++firstPositive;
  }
  return std::copy(firstPositive,
    accu_org::end(buffer), to);
}


template <typename cT, typename OutIt>
OutIt
bin_num_put<cT, OutIt>::do_put(OutIt to,
                               std::ios_base& fmt,
                               cT fill,
                               std::intmax_t v) const {

  char narrow[] = "0123456789abcdef";
  cT wide[16] = { 0 };
  std::use_facet<std::ctype<cT> >(
        fmt.getloc()).widen(accu_org::begin(narrow),
        accu_org::end(narrow) - 1, accu_org::begin(wide));
  cT buffer[sizeof(v)*8+1];
  std::fill(accu_org::begin(buffer), accu_org::end(buffer),
                                fill);
  int base = fmt.iword(base_index);
  if (v > 0) for (cT* it = accu_org::end(buffer)
       ; v != 0
       ; v /= base)
    *--it = wide[v % base];
  else if (std::numeric_limits<std::intmax_t>::min() == v) {
    std::uintmax_t z = std::numeric_limits<std::intmax_t>::min();
    const char minus[1] = { '-' };
    to = std::copy(&minus[0], &minus[1], to);    
    return do_put(to, fmt, fill, z);
  } else {
    v = -v;
    for (cT* it = accu_org::end(buffer)
       ; (*--it = '-'),(v != 0)
       ; v /= base)
    *it = wide[v % base];
  }
  auto minWidth = fmt.width();
  fmt.width(0);
  if (minWidth < 1) minWidth = 1;
  if (minWidth > sizeof(v)*8+1)
    minWidth = sizeof(v)*8+1;
  
  auto firstPositive = accu_org::begin(buffer);
  while (*firstPositive == fill && firstPositive <  accu_org::end(buffer)-minWidth) {
    ++firstPositive;
  }
  std::copy(firstPositive,
    accu_org::end(buffer), to);
  return to;
}

template <typename cT, typename traits>
std::basic_ios<cT, traits>&
install_bin(std::basic_ios<cT,traits>& ios,
            int base) {
  ios.iword(base_index) = base;
  typedef std::ostreambuf_iterator<cT>
                                iterator;
  if(!dynamic_cast
      <bin_num_put<cT, iterator> const*>(
        &std::use_facet<std::num_put<cT,
          iterator> >(ios.getloc())))
    ios.imbue(std::locale(ios.getloc(),
    new bin_num_put<cT, iterator>()));
  return ios;
}


template <typename cT, typename traits>
std::basic_ios<cT, traits>&
bin(std::basic_ios<cT, traits>& ios) {
  return install_bin(ios, 2);
}

template <typename cT, typename traits>
std::basic_ios<cT, traits>&
oct(std::basic_ios<cT, traits>& ios) {
  return install_bin(ios, 8);
}

template <typename cT, typename traits>
std::basic_ios<cT, traits>&
dec(std::basic_ios<cT, traits>& ios) {
  return install_bin(ios, 10);
}

template <typename cT, typename traits>
std::basic_ios<cT, traits>&
hex(std::basic_ios<cT, traits>& ios) {
  return install_bin(ios, 16);
}
