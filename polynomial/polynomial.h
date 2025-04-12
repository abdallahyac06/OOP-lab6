#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {
    private:
        double coefficients[100] = {0};
        int exponents[100] = {0};
        int size;
        void polynomialCombine();;

    public:
        Polynomial();
        void enterTerms();
        void printPolynomial();

        Polynomial operator+(const Polynomial &);
        Polynomial operator -(const Polynomial &);
        Polynomial operator*(const Polynomial &);
        const Polynomial operator=(const Polynomial &);
        Polynomial& operator +=(const Polynomial &);
        Polynomial& operator -=(const Polynomial &);
        Polynomial& operator *=(const Polynomial &);
};


#endif