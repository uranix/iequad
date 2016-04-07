#include "quad.h"
#include <iostream>

struct DoubleLayer {
    const triint::point n;
    constexpr static bool strongSingular = true;
    DoubleLayer(const triint::point &n) : n(n) { }
    double operator()(const triint::point y_x, const double r) const {
        return 1. / (4 * 3.14159265358979323) * y_x.dot(n) / (r * r * r);
    }
};

int main() {
    const triint::point p1(1, 0, 0);
    const triint::point p2(0, 1, 0);
    const triint::point p3(0, 0, 1);
    const triint::point y(1. / 3, 1. / 3, 1. / 3);

    const triint::point &n = (p2 - p1).cross(p3 - p1);
    DoubleLayer kernel(n * (1. / n.norm()));

    double v = triint::triint<10>(kernel, y, p1, p2, p3);
    std::cout << v << std::endl;
    return 0;
}
