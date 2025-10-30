#ifndef PHIMATH_VEC3_H
#define PHIMATH_VEC3_H

#include <iostream>
#include <cmath>

namespace phimath {

template <typename T>
concept vectorable = requires(T a, T b) {
    { a + b} -> std::same_as<T>;
    { a - b} -> std::same_as<T>;
    { a * b} -> std::same_as<T>;
    { a / b} -> std::same_as<T>;
    { -a } -> std::same_as<T>;
    { (long double)a } -> std::same_as<long double>;
};

template <typename T>
requires vectorable<T>
class vec3 {
    public:
        T e[3];

        vec3() : e{0, 0, 0} {}
        vec3(T e0, T e1, T e2) : e{e0, e1, e2} {}

        T x() const { return e[0]; }
        T y() const { return e[1]; }
        T z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        T operator[](int i) const { return e[i]; }
        T& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        vec3& operator-=(const vec3& v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }
        vec3& operator*=(const vec3& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            return *this;
        }
        vec3& operator/=(const vec3& v) {
            e[0] /= v.e[0];
            e[1] /= v.e[1];
            e[2] /= v.e[2];
            return *this;
        }

        long double length() const {
            return std::sqrtl(length_squared());
        }
        T length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

template <typename T>
requires vectorable<T>
inline std::ostream& operator<<(std::ostream& out, const vec3<T>& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator+(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0]+v.e[0], u.e[1]+v.e[1], u.e[2]+v.e[2]);
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator-(const vec3<T>& u, const vec3<T>& v) {
    return u + -v;
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator*(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0]*v.e[0], u.e[1]*v.e[1], u.e[2]*v.e[2]);
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator*(T u, const vec3<T>& v) {
    return vec3<T>(u*v.e[0], u*v.e[1], u*v.e[2]);
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator*(const vec3<T>& u, T v) {
    return vec3<T>(u.e[0]*v, u.e[1]*v, u.e[2]*v);
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator/(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(u.e[0]/v.e[0], u.e[1]/v.e[1], u.e[2]/v.e[2]);
}

template <typename T>
requires vectorable<T>
inline vec3<T> operator/(const vec3<T>& u, T v) {
    return vec3<T>(u.e[0]/v, u.e[1]/v, u.e[2]/v);
}

template <typename T>
requires vectorable<T>
inline T dot(const vec3<T>& u, const vec3<T>& v) {
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}

template <typename T>
requires vectorable<T>
inline vec3<T> cross(const vec3<T>& u, const vec3<T>& v) {
    return vec3<T>(
        u.e[1]*v.e[2] - u.e[2]*v.e[1],
        u.e[2]*v.e[0] - u.e[0]*v.e[2],
        u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}

template <typename T>
requires vectorable<T>
inline vec3<long double> unit_vector(const vec3<T>& v) {
    vec3<long double> u((long double)v.e[0], (long double)v.e[1], (long double)v.e[2]);
    return u / (u.length());
}

}

#endif
