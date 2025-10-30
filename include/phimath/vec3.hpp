#ifndef PHIMATH_VEC3_H
#define PHIMATH_VEC3_H

#include <iostream>
#include <arithmetic.hpp>

namespace phimath {

template <typename T>
requires arithmetic<T>
class vec3 {
    public:
        T e[3];

        vec3() : e{0, 0, 0} {};
        vec3(T e0, T e1, T e2) : e{e0, e1, e2} {};

        T x() const { return e[0]; };
        T y() const { return e[1]; };
        T z() const { return e[2]; };

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); };
};

}

#endif
