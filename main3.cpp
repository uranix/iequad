#include "iequad.h"
#include <iostream>

using namespace iequad;

struct Tensor {
    const double xx, xy, xz, yy, yz, zz;
    Tensor(double xx, double xy, double xz, double yy, double yz, double zz) :
        xx(xx), xy(xy), xz(xz), yy(yy), yz(yz), zz(zz) { }
    const Tensor operator+(const Tensor &o) const {
        return Tensor(
                xx + o.xx, xy + o.xy, xz + o.xz,
                yy + o.yy, yz + o.yz, zz + o.zz
            );
    }
    const Tensor operator*(const double m) const {
        return Tensor(
                xx * m, xy * m, xz * m,
                yy * m, yz * m, zz * m
            );
    }
};

struct GenSingleLayer {
    constexpr static bool strongSingular = true;
    Tensor operator()(const point &r, const double rnorm) const {
        return Tensor(
                r.x * r.x, r.x * r.y, r.x * r.z,
                r.y * r.y, r.y * r.z, r.z * r.z
            ) * (1 / (rnorm * rnorm * rnorm));
    }
};

template<class Kernel>
void run(const Kernel &kernel, const point &y,
        const point &p1, const point &p2, const point &p3, const point &p4)
{
    const Tensor &ten = iequad::regular<5 >(kernel, y, p1, p2, p3, p4);
    std::cout << "Res" << std::endl;
    std::cout << ten.xx << ", " << ten.xy << ", " << ten.xz << std::endl;
    std::cout << ten.xy << ", " << ten.yy << ", " << ten.yz << std::endl;
    std::cout << ten.xz << ", " << ten.yz << ", " << ten.zz << std::endl;
}

int main() {
    const point p1( 1, -1, 0);
    const point p2( 1,  1, 0);
    const point p3(-1,  1, 0);
    const point p4(-1, -1, 0);

    GenSingleLayer kernel;

    run(kernel, point(0, 0, 1), p1, p2, p3, p4);

    return 0;
}
