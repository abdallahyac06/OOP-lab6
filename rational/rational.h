#ifndef rational_H
#define rational_H

#include <iostream>


class Rational {
    private:
        int numerator;
        int denominator;
        int gcd() const;
        void reduce();

    public:
        Rational(int = 0, int = 1);
        void setRational(int, int);
        int getNumerator() const;
        int getDenominator() const;
        
        Rational &operator=(const Rational &);
        Rational operator+(const Rational &) const;
        Rational operator-(const Rational &) const;
        Rational operator-() const;
        Rational operator*(const Rational &) const;
        Rational operator/(const Rational &) const;

        Rational &operator+=(const Rational &other) {return this->operator=(this->operator+(other));}
        Rational &operator-=(const Rational &other) {return this->operator=(this->operator-(other));}
        Rational &operator*=(const Rational &other) {return this->operator=(this->operator*(other));}
        Rational &operator/=(const Rational &other) {return this->operator=(this->operator/(other));}

        Rational &operator++();
        Rational operator++(int);
        Rational &operator--();
        Rational operator--(int);
        bool operator!() const;

        bool operator==(const Rational &) const;
        bool operator!=(const Rational &) const;
        bool operator<(const Rational &) const;
        bool operator>(const Rational &) const;
        bool operator>=(const Rational &) const;
        bool operator<=(const Rational &) const;

        operator bool() const;
        operator int() const;
        operator double() const;
        operator std::string() const;

    friend std::ostream &operator<<(std::ostream &, const Rational &);
    friend std::istream &operator>>(std::istream &, Rational &);
};

#endif