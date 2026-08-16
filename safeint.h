#include <limits>
#include <stdexcept>


static std::overflow_error overflow("larger than type");
static std::domain_error divide_by_zero("divide by zero");

using namespace std;
#include <exception>
template <int n> class safeint {
    public:
    safeint(int);
    safeint(const safeint<n>& that);
    safeint<n>& operator = (const safeint<n>& that);
};

template<>
class safeint<1> {
    public:
      signed char data;
    public:

    static signed char min();
    static signed char max();
    safeint() {
    }
    safeint(int x) {
        if (x != 0 && x != -1) throw &overflow;
        data = (signed char)x;
    }

    safeint(safeint<2>& that);
    safeint(const safeint<1>& that) {
        data = that.data;
    }

    safeint<1>& operator = (const safeint<1>& that) {
        data = that.data;
        return *this;
    }
    // pre
    safeint operator ++ () {
        if (data == 0) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    safeint operator ++ (int) {
        if (data == 0) {
            throw &overflow;
        }
        safeint<1> save(*this);
        data += 1;
        return save;
    }
    operator int64_t() const {
      return data;
    }

    friend class safeint<2>;
    friend class safeint<7>;
    friend safeint<2> operator + (safeint<1> a, safeint<1> b);
    friend safeint<2> operator - (safeint<1> a, safeint<1> b);
    friend safeint<2> operator * (safeint<1> a, safeint<1> b);
    friend safeint<2> operator / (safeint<1> a, safeint<1> b);
};

template<>
class safeint<2> {
    public:
      signed char data;
    public:
    static signed char max();
    static signed char min();

    safeint(int x) {
        if (x > max() || x < -2) throw &overflow;
        data = (unsigned char)x;
    }
    safeint(const safeint<1>& that) {
        data = that.data;
    }

    safeint<2>& operator = (const safeint<1>& that) {
        data = that.data;
        return *this;
    }
    safeint<2>& operator = (const safeint<2>& that) {
        data = that.data;
        return *this;
    }
    // pre
    safeint operator ++ () {
        if (data == 1) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    safeint operator ++ (int) {
        if (data == 1) {
            throw &overflow;
        }
        safeint<2> save(*this);
        data += 1;
        return save;
    }

    operator int64_t() const {
      return data;
    }

    friend safeint<1>::safeint(safeint<2>& that);
};

template<>
class safeint<3> {
    public:
      signed char data;
    public:
    static signed char max() {
        return 3;
    }
    static signed char min() {
        return -4;
    }

    safeint(int x) {
        if (x > max() || x < min()) throw &overflow;
        data = (unsigned char)x;
    }
    safeint(const safeint<1>& that) {
        data = that.data;
    }
    safeint(const safeint<2>& that) {
        data = that.data;
    }
    safeint(const safeint<3>& that) {
        data = that.data;
    }

    safeint<3>& operator = (const safeint<3>& that) {
        data = that.data;
        return *this;
    }
    safeint<3>& operator = (const safeint<2>& that) {
        data = that.data;
        return *this;
    }
    safeint<3>& operator = (const safeint<1>& that) {
        data = that.data;
        return *this;
    }
    // pre
    safeint operator ++ () {
        if (data == max()) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    safeint operator ++ (int) {
        if (data == max()) {
            throw &overflow;
        }
        safeint<3> save(*this);
        data += 1;
        return save;
    }
};


template<>
class safeint<7> {
    public:
      signed char data;
    public:
    static signed char max() {
        return 63;
    }

    safeint(int x) {
        if (x > 63 || x < -64) throw &overflow;
        data = (unsigned char)x;
    }
    safeint(const safeint<1>& that) {
        data = that.data;
    }
    safeint(const safeint<2>& that) {
        data = that.data;
    }
    safeint(const safeint<7>& that) {
        data = that.data;
    }

    safeint<7>& operator = (const safeint<7>& that) {
        data = that.data;
        return *this;
    }
    safeint<7>& operator = (const safeint<2>& that) {
        data = that.data;
        return *this;
    }
    // pre
    safeint operator ++ () {
        if (data == 63) {
            throw &overflow;
        }
        data += 1;
        return *this;
    }
    // post
    safeint operator ++ (int) {
        if (data == 63) {
            throw &overflow;
        }
        safeint<7> save(*this);
        data += 1;
        return save;
    }
};


extern bool operator == (safeint<2> si, int64_t i);
extern bool operator == (int64_t i, safeint<2> si);