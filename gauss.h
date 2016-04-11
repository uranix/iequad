#ifndef __IEQUAD_GAUSS_H__
#define __IEQUAD_GAUSS_H__

namespace iequad {

template <int n, int i> struct GaussQuadCoeff;

#include "gausscoeff.h"

template <int n, int i, class Function, typename Ret>
struct QuadEval {
    static Ret eval(const Function &f) {
        return QuadEval<n, i-1, Function, Ret>::eval(f, f(GaussQuadCoeff<n, i-1>::node) * GaussQuadCoeff<n, i-1>::weight);
    }
    static Ret eval(const Function &f, const Ret s) {
        return QuadEval<n, i-1, Function, Ret>::eval(f, s + f(GaussQuadCoeff<n, i-1>::node) * GaussQuadCoeff<n, i-1>::weight);
    }
};

template <int n, class Function, typename Ret>
struct QuadEval<n, 0, Function, Ret> {
    static Ret eval(const Function &f, const Ret s) {
        return s;
    }
};

template <int n, class Function>
auto quad(const Function &f) -> decltype(f(0)) {
    typedef decltype(f(0)) Ret;
    return QuadEval<n, n, Function, Ret>::eval(f);
}

};

#endif
