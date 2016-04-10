#include "iequad.h"
#include <iostream>

struct DoubleLayer {
    const iequad::point n;
    constexpr static bool strongSingular = true;
    DoubleLayer(const iequad::point &n) : n(n) { }
    double operator()(const iequad::point y_x, const double r) const {
        return 1. / (4 * 3.14159265358979323) * y_x.dot(n) / (r * r * r);
    }
};

int main() {
    const iequad::point p1(1, 0, 0);
    const iequad::point p2(0, 1, 0);
    const iequad::point p3(0, 0, 1);
    const iequad::point y(1. / 3, 1. / 3, 1. / 3);

    const iequad::point &n = (p2 - p1).cross(p3 - p1);
    DoubleLayer kernel(n * (1. / n.norm()));

    double v = iequad::singular<10>(kernel, y, p1, p2, p3);
    std::cout << v << std::endl;
    return 0;
}
