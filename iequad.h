#ifndef __IEQUAD_QUAD_H__
#define __IEQUAD_QUAD_H__

#include <cmath>

#include "point.h"
#include "gauss.h"

namespace iequad {

template<class Kernel, int quadPoints>
double integrate_segment(const point &pa, const point &pb, const point &y, const Kernel &f) {
    const point &rprime = pb - pa;

    return iequad::quad<quadPoints>([&] (const double t) {
        const point &p = pa * (1 - t) + pb * t;
        const point &y_x = y - p;
        double R = y_x.norm();
        const point &surf = y_x.cross(rprime);
        if (Kernel::strongSingular)
            return f(y_x, R) * std::log(R) * surf.norm();
        else
            return f(y_x, R) * surf.norm();
    });
}

//
// Integrate a singular kernel over a polygon p1, ..., pn
// Polygon should be flat
// Kernel should be a homogenous function of y-x of degree
//  * -1 if Kernel::strongSignular = false
//  * -2 if Kernel::strongSignular = true
//
template<int quadPoints, class Kernel>
double singular(
        const Kernel &k,
        const point &y,
        const point &p1,
        const point &p2,
        const point &p3
    )
{
    double ret = integrate_segment<Kernel, quadPoints>(p1, p2, y, k);
    ret += integrate_segment<Kernel, quadPoints>(p2, p3, y, k);
    ret += integrate_segment<Kernel, quadPoints>(p3, p1, y, k);
    return ret;
}

template<int quadPoints, class Kernel>
double singular(
        const Kernel &k,
        const point &y,
        const point &p1,
        const point &p2,
        const point &p3,
        const point &p4
    )
{
    double ret = integrate_segment<Kernel, quadPoints>(p1, p2, y, k);
    ret += integrate_segment<Kernel, quadPoints>(p2, p3, y, k);
    ret += integrate_segment<Kernel, quadPoints>(p3, p4, y, k);
    ret += integrate_segment<Kernel, quadPoints>(p4, p1, y, k);
    return ret;
}

// TODO: add regular functions

}

#endif
