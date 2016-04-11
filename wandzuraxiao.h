#ifndef __IEQUAD_WANDZURAXIAO_H__
#define __IEQUAD_WANDZURAXIAO_H__

namespace iequad {

template <class Function, typename Ret>
struct TriQuadHelper {
    static Ret pointA(const double w, const Function &f) {
        return f(1. / 3, 1. / 3) * w;
    }
    static Ret pointB(const double w, const Function &f, const double x) {
        const double y = 0.5 * (1 - x);
        return (f(x, y) + f(y, x) + f(y, y)) * w;
    }
    static Ret pointC(const double w, const Function &f, const double x, const double y) {
        const double z = 1 - x - y;
        return (f(x, y) + f(x, z) + f(y, x) + f(y, z) + f(z, x) + f(z, y)) * w;
    }
};

template <int n, class Function, typename Ret>
struct TriQuad {
    static Ret eval(const Function &f);
};

#include "wxcoeff.h"

template <int n, class Function>
auto triint(const Function &f) -> decltype(f(0, 0)) {
    typedef decltype(f(0, 0)) Ret;
    return TriQuad<n, Function, Ret>::eval(f);
}

}

#endif
