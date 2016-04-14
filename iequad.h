#ifndef __IEQUAD_QUAD_H__
#define __IEQUAD_QUAD_H__

#include <cmath>
#include <type_traits>

#include "point.h"
#include "gauss.h"
#include "wandzuraxiao.h"

namespace iequad {

template<class Kernel, int quadPoints>
auto integrate_segment(const point &pa, const point &pb, const point &x, const Kernel &f) -> decltype (f(point(0, 0, 0), 0)) {
    const point &rprime = pb - pa;

    return iequad::quad<quadPoints>([&] (const double t) {
        const point &y = pa * (1 - t) + pb * t;
        const point &y_x = y - x;
        double R = y_x.norm();
        const point &surf = y_x.cross(rprime);
        if (Kernel::strongSingular)
            return f(y_x, R) * std::log(R) * surf.norm();
        else
            return f(y_x, R) * surf.norm();
    });
}

template<class Ret, int quadPoints, class Kernel>
Ret chew_singular(const Ret ret, const Kernel &k, const point &x, const point &p1, const point &pnm1, const point &pn) {
    return ret
        + integrate_segment<Kernel, quadPoints>(pnm1, pn, x, k)
        + integrate_segment<Kernel, quadPoints>(pn, p1, x, k);
}

template<class Ret, int quadPoints, class Kernel, typename... Points>
Ret chew_singular(const Ret ret, const Kernel &k, const point &x, const point &p1, const point &pk, const point &pk1, const Points&... pts) {
    return chew_singular<Ret, quadPoints>(
            ret + integrate_segment<Kernel, quadPoints>(pk, pk1, x, k),
            k, x, p1, pk1, pts...
        );
}

//
// Integrate a singular kernel over a polygon p1, ..., pn
// Polygon should be flat
// x should not lie in p1, ..., pn
// Kernel should be a homogenous function of y-x of degree
//  * -1 if Kernel::strongSignular = false
//  * -2 if Kernel::strongSignular = true
//
template<int quadPoints, class Kernel, typename... Points>
auto singular(
        const Kernel &k,
        const point &x,
        const point &p1,
        const point &p2,
        const Points&... pts
    ) -> decltype(k(point(0, 0, 0), 0))
{
    auto ret = integrate_segment<Kernel, quadPoints>(p1, p2, x, k);
    return chew_singular<decltype(ret), quadPoints>(ret, k, x, p1, p2, pts...);
}

template<class Kernel, int quadPoints>
auto integrate_triangle(const point &pa, const point &pb, const point &pc, const point &x, const Kernel &f) -> decltype (f(point(0, 0, 0), 0)) {
    double S = (pb - pa).cross(pc - pa).norm() * 0.5;
    return iequad::triint<quadPoints>([&] (const double xi, const double eta) {
        const point &y = pa * xi + pb * eta + pc * (1 - xi - eta);
        const point &y_x = y - x;
        double R = y_x.norm();
        return f(y_x, R);
    }) * S;
}

template<class Ret, int quadPoints, class Kernel>
Ret chew_regular(const Ret ret, const Kernel &k, const point &x, const point &p1, const point &pnm1, const point &pn) {
    return ret + integrate_triangle<Kernel, quadPoints>(p1, pnm1, pn, x, k);
}

template<class Ret, int quadPoints, class Kernel>
Ret chew_regular(const Kernel &k, const point &x, const point &p1, const point &pnm1, const point &pn) {
    return integrate_triangle<Kernel, quadPoints>(p1, pnm1, pn, x, k);
}

template<class Ret, int quadPoints, class Kernel, typename... Points>
Ret chew_regular(const Ret ret, const Kernel &k, const point &x, const point &p1, const point &pk, const point &pk1, const Points&... pts) {
    return chew_regular<Ret, quadPoints>(
            ret + integrate_triangle<Kernel, quadPoints>(p1, pk, pk1, x, k),
            k, x, p1, pk1, pts...
        );
}

template<class Ret, int quadPoints, class Kernel, typename... Points>
Ret chew_regular(const Kernel &k, const point &x, const point &p1, const point &pk, const point &pk1, const Points&... pts) {
    return chew_regular<Ret, quadPoints>(
            integrate_triangle<Kernel, quadPoints>(p1, pk, pk1, x, k),
            k, x, p1, pk1, pts...
        );
}

//
// Integrate a regular kernel over a polygon p1, ..., pn
// Polygon should be flat
// x should not lie in p1, ..., pn
//
template<int quadPoints, class Kernel, typename... Points>
auto regular(
        const Kernel &k,
        const point &x,
        const point &p1,
        const point &p2,
        const Points&... pts
    ) -> decltype(k(point(0, 0, 0), 0))
{
    typedef decltype(k(point(0, 0, 0), 0)) Ret;
    return chew_regular<Ret, quadPoints>(k, x, p1, p2, pts...);
}

// Non-decltype, non-variadic version for cython
template<typename RetType, int quadPoints, class Kernel>
RetType singular_tri(
        const Kernel &k,
        const point &x,
        const point &p1,
        const point &p2,
        const point &p3
    )
{
    typedef decltype(k(point(0, 0, 0), 0)) Ret;
    static_assert(std::is_same<Ret, RetType>::value, "RetType does not match Kernel::operator() return type");
    return singular<quadPoints>(k, x, p1, p2, p3);
}

// Non-decltype, non-variadic version for cython
template<typename RetType, int quadPoints, class Kernel>
RetType regular_tri(
        const Kernel &k,
        const point &x,
        const point &p1,
        const point &p2,
        const point &p3
    )
{
    typedef decltype(k(point(0, 0, 0), 0)) Ret;
    static_assert(std::is_same<Ret, RetType>::value, "RetType does not match Kernel::operator() return type");
    return regular<quadPoints>(k, x, p1, p2, p3);
}

}

#endif
