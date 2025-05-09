#include "rational.h"
#include <iostream>
#include <cmath>

Rational::Rational(int num, int denom): numerator(num), denominator(denom) {
    reduce();
}

int Rational::gcd() const {
    int a = abs(numerator), b = denominator, r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void Rational::reduce() {
    if (denominator == 0) {
        std::cerr << "Devision by Zero Error." << std::endl;
        exit(1);
    }

    numerator = (denominator > 0)? numerator: -numerator;
    denominator = abs(denominator);
    int n = gcd();
    numerator /= n;
    denominator /= n;
}

void Rational::setRational(int num, int denom) {
    numerator = num;
    denominator = denom;
    reduce();
}

int Rational::getNumerator() const {
    return numerator;
}

int Rational::getDenominator() const {
    return denominator;
}

Rational &Rational::operator=(const Rational &other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Rational Rational::operator+(const Rational &other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-(const Rational &other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Rational Rational::operator-() const {
    return Rational(-numerator, denominator);
}

Rational Rational::operator*(const Rational &other) const {
    return Rational(numerator * other.numerator,
                    denominator * other.denominator);
}

Rational Rational::operator/(const Rational &other) const {
    return Rational(numerator * other.denominator,
                    denominator * other.numerator);
}

Rational& Rational::operator++() {
    numerator += denominator;
    return *this;
}

Rational Rational::operator++(int) {
    Rational tmp = *this;
    numerator += denominator;
    return tmp;
}

Rational& Rational::operator--() {
    numerator -= denominator;
    return *this;
}

Rational Rational::operator--(int) {
    Rational tmp = *this;
    numerator -= denominator;
    return tmp;
}

bool Rational::operator!() const {
    return numerator == 0;
}

bool Rational::operator==(const Rational &other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

bool Rational::operator!=(const Rational &other) const {
    return (numerator != other.numerator || denominator != other.denominator);
}

bool Rational::operator<(const Rational &other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator>(const Rational &other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<=(const Rational &other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Rational::operator>=(const Rational &other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

Rational::operator bool() const {
    return numerator != 0;
}

Rational::operator int() const {
    return numerator / denominator;
}

Rational::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

Rational::operator std::string() const {
    return std::to_string(operator double());
}

std::ostream &operator<<(std::ostream &output, const Rational &rational) {
    output << rational.numerator << "/" << rational.denominator;
    return output;
}

std::istream &operator>>(std::istream &input, Rational &rational) {
    input >> rational.numerator >> rational.denominator;
    rational.reduce();
    return input;
}