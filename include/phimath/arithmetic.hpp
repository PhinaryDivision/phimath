#ifndef PHIMATH_ARITHMETIC_H
#define PHIMATH_ARITHMETIC_H

namespace phimath {

template <typename T>
concept arithmetic = requires(T a, T b) {
    { a + b} -> std::same_as<T>;
    { a - b} -> std::same_as<T>;
    { a * b} -> std::same_as<T>;
    { a / b} -> std::same_as<T>;
    { -a } -> std::same_as<T>;
    { -b } -> std::same_as<T>;
};

}

#endif
