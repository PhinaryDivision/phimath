#include <iostream>

#include <phimath/vec3.hpp>

int main(void) {
    std::cout << "Output works\n";
    phimath::vec3<double> v(1.1, 2.1, 3.1);
    phimath::vec3<double> u(4.5, 2.8, 9.8);
    std::cout << "v.x() v.y() v.z()\n" << v.x() << v.y() << v.z() << "\n";
    v -= u;
    std::cout << v << "\n";
    v += u;
    std::cout << v << "\n";
    v *= u;
    std::cout << v << "\n";
    v /= u;
    std::cout << v << "\n";
    std::cout << u + v << "\n";
    std::cout << u - v << "\n";
    std::cout << u * v << "\n" << u * 5.0 << '\n' << 5.0 * u << '\n' << u / v << '\n' << u / 5.0 << '\n';
    std::cout << phimath::dot(u, v) << '\n' << phimath::cross(u, v) << '\n' << phimath::unit_vector(u) << '\n';

    return 0;
}
