#include "safeint.h"
safeint<1>::safeint(safeint<2>& that) : safeint(that.data) {
}

signed char safeint<1>::max() {
    return '\000';
}

signed char safeint<1>::min() {
    return -1;
}