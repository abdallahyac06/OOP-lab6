#include "rational.h"
#include <iostream>

int main() {
    Rational p, q;
    std::cout << "Enter the first rational number." << std::endl;
    std::cin >> p;
    std::cout << "Enter the second rational number." << std::endl;
    std::cin >> q;

    std::cout << "p + q = " << p + q << std::endl;
    std::cout << "p - q = " << p - q << std::endl;
    std::cout << "p * q = " << p * q << std::endl;
    std::cout << "p / q = " << p / q << std::endl;

    std::cout << "p < q : " << (p < q) << std::endl;
    std::cout << "p >= q : " << (p >= q) << std::endl;
    std::cout << "p == q : " << (p == q) << std::endl;

    std::cout << "int(p) " << static_cast<int>(p + q) << std::endl;
    std::cout << "double(p) " << static_cast<double>(p + q) << std::endl;
    std::cout << "string(p) " << static_cast<std::string>(p + q) << std::endl;

    q += p;
    std::cout << "p + q = " << p + q << std::endl;
    std::cout << "-p = " << p + q << std::endl;
    std::cout << "++p = " << ++p << std::endl;
    std::cout << "q++ = " << q++ << std::endl;

    return 0;
}