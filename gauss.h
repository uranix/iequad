#ifndef __IEQUAD_GAUSS_H__
#define __IEQUAD_GAUSS_H__

namespace iequad {

template <int n, int i> struct GaussQuadCoeff;

#include "gausscoeff.h"

template <int n, int i, class Function>
struct QuadEval {
    static double eval(const Function &f) {
        return QuadEval<n, i-1, Function>::eval(f, GaussQuadCoeff<n, i-1>::weight * f(GaussQuadCoeff<n, i-1>::node));
    }
    static double eval(const Function &f, const double s) {
        return QuadEval<n, i-1, Function>::eval(f, s + GaussQuadCoeff<n, i-1>::weight * f(GaussQuadCoeff<n, i-1>::node));
    }
};

template <int n, class Function>
struct QuadEval<n, 0, Function> {
    static double eval(const Function &f, const double s) {
        return s;
    }
};

template <int n, class Function>
double quad(const Function &f) {
    return QuadEval<n, n, Function>::eval(f);
}

};

#endif
