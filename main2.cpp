#include "iequad.h"
#include <iostream>

using namespace iequad;

struct Theocaris17 {
    constexpr static bool strongSingular = true;
    Theocaris17() { }
    double operator()(const point &y_x, const double r) const {
        return y_x.x / (r * r * r);
    }
};

double exact(double x0, double y0) {
    double r1 = std::sqrt(std::pow(1 + x0, 2) + std::pow(1 - y0, 2));
    double r2 = std::sqrt(std::pow(1 - x0, 2) + std::pow(1 + y0, 2));
    double r3 = std::sqrt(std::pow(1 + x0, 2) + std::pow(1 + y0, 2));
    double r4 = std::sqrt(std::pow(1 - x0, 2) + std::pow(1 - y0, 2));
    return std::log((1 - y0 + r1) * (-1 - y0 + r2) / (-1 - y0 + r3) / (1 - y0 + r4));
}

template<class Kernel>
void run(const Kernel &kernel, const point &y,
        const point &p1, const point &p2, const point &p3, const point &p4)
{
    double e = exact(y.x, y.y);
    std::cout << "For y = (" << y.x << ", " << y.y << ")" << std::endl;
    std::cout << "Points : " << 1  << ", error = " << iequad::singular<1 >(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 5  << ", error = " << iequad::singular<5 >(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 10 << ", error = " << iequad::singular<10>(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 20 << ", error = " << iequad::singular<20>(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 30 << ", error = " << iequad::singular<30>(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 40 << ", error = " << iequad::singular<40>(kernel, y, p1, p2, p3, p4) + e << std::endl;
    std::cout << "Points : " << 50 << ", error = " << iequad::singular<50>(kernel, y, p1, p2, p3, p4) + e << std::endl;
}

int main() {
    const point p1( 1, -1, 0);
    const point p2( 1,  1, 0);
    const point p3(-1,  1, 0);
    const point p4(-1, -1, 0);

    Theocaris17 kernel;

    run(kernel, point(.4, .1, 0), p1, p2, p3, p4);
    run(kernel, point(.6, .2, 0), p1, p2, p3, p4);
    run(kernel, point(.8, .4, 0), p1, p2, p3, p4);
    run(kernel, point(.1, .0, 0), p1, p2, p3, p4);
    run(kernel, point(.9, .0, 0), p1, p2, p3, p4);

    return 0;
}
