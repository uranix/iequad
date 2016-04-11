#include "iequad.h"
#include <iostream>
#include <cmath>

struct Newton {
    constexpr static bool strongSingular = false;
    double operator()(const iequad::point y_x, const double r) const {
        return 1. / r;
    }
};

int main() {
    const iequad::point p1(1, 0, 0);
    const iequad::point p2(0, 1, 0);
    const iequad::point p3(0, 0, 1);
    const iequad::point y(1. / 3, 1. / 3, 1. / 3);

    Newton kernel;
    const double e = std::sqrt(1.5) * std::log(7 + 4 * std::sqrt(3));

    std::cout << "Error: " << iequad::singular<1 >(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<2 >(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<5 >(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<10>(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<20>(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<30>(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<40>(kernel, y, p1, p2, p3) - e << std::endl;
    std::cout << "Error: " << iequad::singular<50>(kernel, y, p1, p2, p3) - e << std::endl;
    return 0;
}
