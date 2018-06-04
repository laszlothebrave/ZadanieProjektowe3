//
// Created by laszlothebrave on 6/4/2018.
//

#include <cstdlib>
#include <cfloat>
#include "Polynomial.h"

Polynomial::Polynomial(double a,
                       double b,
                       double c,
                       double d,
                       double e,
                       double f,
                       double g,
                       double h,
                       double i) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {
    j = 0;
    min = DBL_MAX;
    max = DBL_MIN;
}

Polynomial Polynomial::getEuklides() {
    return Polynomial(4*a*a + d*d + e*e, 4*b*b+d*d+f*f, 4*c*c+e*e+f*f, 4 *a *d + 4 *b *d + 2 *e *f, 4 *a *e + 4 *c *e + 2 *d *f, 2 *d *e + 4 *b *f + 4 *c *f, 4 *a *g + 2 *d *h + 2 *e *i, 2 *d *g + 4 *b *h + 2 *f *i, g*g + h*h + i*i);
}

int Polynomial::getJ() {
    return j;
}

int Polynomial::getMax() {
    return abs(max)>abs(min) ? max : min;
}

void Polynomial::setMax() {
    calculatePoints();  // tab - pozycje od 0 do 3
    calculateLines();   // tab - pozycje od 4 do 9
    calculateAreas();   // tab - pozycje od 10 do 13
    calculateVolume();  // tab - pozycja 14
    max = tab[0];
    min = tab[0];
    for (int i=1 ; i<15 ; i++){
        max = max > tab[i] ? max : tab[i];
        min = min < tab[i] ? min : tab[i];
    }
}

void Polynomial::setJ() {
    j = -(min+max)/2;
    max = max + j;
    min = min + j;
}

void Polynomial::calculatePoints() {

}

void Polynomial::calculateLines() {

}

void Polynomial::calculateAreas() {

}

void Polynomial::calculateVolume() {

}
