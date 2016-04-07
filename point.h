#ifndef __TRIINT_POINT_H__
#define __TRIINT_POINT_H__

namespace triint {

struct point {
    const double x, y, z;
    point(const double x, const double y, const double z) : x(x), y(y), z(z) { }
    point(const point &p) : x(p.x), y(p.y), z(p.z) { }
    double dot(const point &p) const {
        return x * p.x + y * p.y + z * p.z;
    }
    const point cross(const point &p) const {
        return point(
                y * p.z - p.y * z,
                z * p.x - p.z * x,
                x * p.y - p.x * y
            );
    }
    const point operator-(const point &p) const {
        return point(
                x - p.x,
                y - p.y,
                z - p.z
            );
    }
    const point operator+(const point &p) const {
        return point(
                x + p.x,
                y + p.y,
                z + p.z
            );
    }
    const double norm() const {
        return std::sqrt(dot(*this));
    }
    const point operator*(const double m) const {
        return point(m * x, m * y, m * z);
    }
};

}

#endif
