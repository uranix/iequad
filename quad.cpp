#include "gauss.h"

#include <iostream>
#include <cmath>

int main() {
    const double pi = 3.14159265358979323;
    std::cout << iequad::quad<1>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<2>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<3>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<4>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<5>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<6>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<7>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<8>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<9>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<10>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<11>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<12>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<13>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<14>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<15>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<16>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<17>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<18>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<19>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    std::cout << iequad::quad<20>([pi] (const double x) { return std::sin(pi * x); }) * pi - 2 << std::endl;
    return 0;
}
