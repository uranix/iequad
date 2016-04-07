#include "quad.h"
#include <iostream>

using namespace triint;

struct Theocaris17 {
    constexpr static bool strongSingular = true;
    Theocaris17() { }
    double operator()(const point y_x, const double r) const {
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

int main() {
    const point p1( 1, -1, 0);
    const point p2( 1,  1, 0);
    const point p3(-1,  1, 0);
    const point p4(-1, -1, 0);

    Theocaris17 kernel;

    std::cout.precision(20);
    const point y1(0.4, 0.1, 0);
    double e1 = exact(y1.x, y1.y);
    std::cout << std::endl;
    std::cout << triint::triint<1 >(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;
    std::cout << triint::triint<5 >(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;
    std::cout << triint::triint<10>(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;
    std::cout << triint::triint<20>(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;
    std::cout << triint::triint<30>(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;
    std::cout << triint::triint<40>(kernel, y1, p1, p2, p3, p4) + e1 << std::endl;

    const point y2(0.6, 0.2, 0);
    double e2 = exact(y2.x, y2.y);
    std::cout << std::endl;
    std::cout << triint::triint<1 >(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;
    std::cout << triint::triint<5 >(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;
    std::cout << triint::triint<10>(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;
    std::cout << triint::triint<20>(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;
    std::cout << triint::triint<30>(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;
    std::cout << triint::triint<40>(kernel, y2, p1, p2, p3, p4) + e2 << std::endl;

    const point y3(0.8, 0.4, 0);
    double e3 = exact(y3.x, y3.y);
    std::cout << std::endl;
    std::cout << triint::triint<1 >(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    std::cout << triint::triint<5 >(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    std::cout << triint::triint<10>(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    std::cout << triint::triint<20>(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    std::cout << triint::triint<30>(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    std::cout << triint::triint<40>(kernel, y3, p1, p2, p3, p4) + e3 << std::endl;
    return 0;
}
