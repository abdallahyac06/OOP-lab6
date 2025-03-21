#include "polynomial.h"

int main() {
    Polynomial p1, p2;
    p1.enterTerms();
    p2.enterTerms();
    p1.printPolynomial();
    p2.printPolynomial();
    (p1 + p2).printPolynomial();
    (p1 - p2).printPolynomial();
    (p1 * p2).printPolynomial();
    return 0;
}