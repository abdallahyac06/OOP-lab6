#include "polynomial.h"
#include <iostream>

Polynomial::Polynomial() {
    size = 0;
}


void Polynomial::polynomialCombine() {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (exponents[i] == exponents[j]) {
                coefficients[i] += coefficients[j];
                coefficients[j] = 0;
            }
        }
    }

    int nonZeroIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (coefficients[i] != 0) {
            coefficients[nonZeroIndex] = coefficients[i];
            exponents[nonZeroIndex] = exponents[i];
            ++nonZeroIndex;
        }
    }
    size = nonZeroIndex;
}

void Polynomial::enterTerms() {
    std::cout << "Enter the size of the polynomial: ";
    std::cin >> size;
    std::cout << "Enter the coefficients and exponents of the polynomial: ";
    for (int i = 0; i < size; i++) {
        std::cin >> coefficients[i];
        std::cin >> exponents[i];
    }
    polynomialCombine();
}

void Polynomial::printPolynomial() {
    if (size == 0) {
        std::cout << "0" << std::endl;
        return;
    }

    double absCoefficient;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            if (coefficients[i] < 0) {
                std::cout << '-';
            }
        } else {
            if (coefficients[i] > 0) {
                std::cout << " + ";
            } else {
                std::cout << " - ";
            }
        }

        absCoefficient = std::abs(coefficients[i]);
        if (!(absCoefficient == 1 && exponents[i] != 0)) {
            std::cout << absCoefficient;
        }

        if (exponents[i] > 0) {
            std::cout << 'x';
            if (exponents[i] > 1) {
                std::cout << '^' << exponents[i];
            }
        }
    }

    std::cout << std::endl;
}

Polynomial Polynomial::operator+(const Polynomial &p) {
    Polynomial result = *this;
    for (int i = 0; i < p.size; i++) {
        result.coefficients[result.size] = p.coefficients[i];
        result.exponents[result.size] = p.exponents[i];
        result.size++;
    }
    result.polynomialCombine();
    return result;
}

Polynomial Polynomial::operator-(const Polynomial &p) {
    Polynomial result = *this;
    for (int i = 0; i < p.size; i++) {
        result.coefficients[result.size] = -p.coefficients[i];
        result.exponents[result.size] = p.exponents[i];
        result.size++;
    }
    result.polynomialCombine();
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &p) {
    Polynomial result;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < p.size; j++) {
            result.coefficients[result.size] = coefficients[i] * p.coefficients[j];
            result.exponents[result.size] = exponents[i] + p.exponents[j];
            result.size++;
        }
    }
    result.polynomialCombine();
    return result;
}

const Polynomial Polynomial::operator=(const Polynomial &p) {
    size = p.size;
    for (int i = 0; i < size; i++) {
        coefficients[i] = p.coefficients[i];
        exponents[i] = p.exponents[i];
    }
    return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &p) {
    *this = *this + p;
    polynomialCombine();
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial &p) {
    *this = *this - p;
    polynomialCombine();
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial &p) {
    *this = *this * p;
    polynomialCombine();
    return *this;
}