//
// Created by laszlothebrave on 6/4/2018.
//

#include <cstdlib>
#include <cfloat>
#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial(const double &a,
                       const double &b,
                       const double &c,
                       const double &d,
                       const double &e,
                       const double &f,
                       const double &g,
                       const double &h,
                       const double &i,
                       double j) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {

    min = DBL_MAX;
    max = -DBL_MAX;
}

Polynomial  Polynomial::getEuklides() {
    return Polynomial(
            4 * a * a + d * d + e * e,

            4 * b * b + d * d + f * f,

            4 * c * c + e * e + f * f,

            4 * a * d + 4 * b * d + 2 * e * f,

            4 * a * e + 4 * c * e + 2 * d * f,

            2 * d * e + 4 * b * f + 4 * c * f,

            4 * a * g + 2 * d * h + 2 * e * i,

            2 * d * g + 4 * b * h + 2 * f * i,

            2 * e * g + 2 * f * h + 4 * c * i,

            g * g + h * h + i * i

    );
}

double Polynomial::getJ() {
    return j;
}

double Polynomial::getMax() {
    return abs(max) > abs(min) ? max : min;
}

void  Polynomial::setMax() {
    calculatePoints();  // tab - pozycje od 0 do 3
    calculateLines();   // tab - pozycje od 4 do 9
    calculateAreas();   // tab - pozycje od 10 do 13
    calculateVolume();  // tab - pozycja 14

}

void  Polynomial::setJ() {
    j = -(min + max) / 2;
    max = max + j;
    min = min + j;
}

void  Polynomial::calculatePoints() {


    checkExtr(getValue(0, 0, 0));
    checkExtr(getValue(0, 0, 1));
    checkExtr(getValue(0, 1, 0));
    checkExtr(getValue(1, 0, 0));


}

void  Polynomial::calculateLines() {

    // x==0 y==0 jednej zmiennej

    if (c != 0 && isInDomain(0, 0, -i / (2 * c)))
        checkExtr(getValue(0, 0, -i / (2 * c)));

    // x=0 z=0

    if (b != 0 && isInDomain(0, -h / (2 * b), 0))
        checkExtr(getValue(0, -h / (2 * b), 0));

    // z= 0 y=0

    if (a != 0 && isInDomain(-g / (2 * a), 0, 0))
        checkExtr(getValue(-g / (2 * a), 0, 0));


    // x= 0 z = 1 - y  z+y-1;

    if (b + c - f != 0) {
        double y = (2 * c - f - h + i) / (2 * (b + c - f));

        if (isInDomain(0, y, 1 - y))
            checkExtr(getValue(0, y, 1 - y));

    }

    // y = 0 ; z =  1 - x
    if (a + c - e != 0) {


        double x = (2 * c - e - g + i) / (2 * (a + c - e));

        if (isInDomain(x, 0, 1 - x)) {

            checkExtr(getValue(x, 0, 1 - x));

        }

    }

    //  z = 0 y = 1 - x

    if (a + b - d != 0) {

        double x = (2 * b - d - g + h) / (2 * (a + b - d));

        if (isInDomain(x, 1 - x, 0)) {
            checkExtr(getValue(x, 1 - x, 0));
        }


    }

    // arena



}

void  Polynomial::calculateAreas() {


    // x = 0

    double W1 = 4 * b * c - f * f;

    if (W1 != 0) {

        double y = (-2 * c * h + f * i) / W1;

        double z = (-2 * b * i + h * f) / W1;

        if (isInDomain(0, y, z))
            checkExtr(
                    getValue(0, y, z)
            );

    }

    // y = 0

    double W2 = 4 * a * c - e * e;
    if (W2 != 0) {

        double x = (-2 * g * c + i * e) / W2;
        double z = (-2 * a * i + g * e) / W2;

        if (isInDomain(x, 0, z))
            checkExtr(getValue(x, 0, z));


    }



    //  y=0 x < 1 -z

    // z = 0

    double W3 = 4 * a * b - d * d;
    if (W3 != 0) {

        double x = (-g * 2 * b + h * d) / W3;

        double y = (-2 * a * h + d * g) / W3;

        if (isInDomain(x, y, 0))
            checkExtr(
                    getValue(x, y, 0)
            );


    }

    // z == 1 - x - y

    double W4 = 4 * a * b + 4 * a * c + 4 * b * c - 4 * c * d - d * d - 4 * b * e + 2 * d * e -
                e * e - 4 * a * f + 2 * d * f + 2 * e * f - f * f;


    if (W4 != 0) {

        double x = 4 * b * c - 2 * c * d - 2 * b * e + d * f + e * f - f * f - 2 * b * g -
                   2 * c * g + 2 * f * g + 2 * c * h + d * h - e * h - f * h + 2 * b * i - d * i +
                   e * i - f * i;

        double y = 4 * a * c - 2 * c * d + d * e - e * e - 2 * a * f + e * f + 2 * c * g + d * g -
                   e * g - f * g - 2 * a * h - 2 * c * h + 2 * e * h + 2 * a * i - d * i - e * i + f * i;

        if (this->isInDomain(x, y, 1 - x - y))
            checkExtr(getValue(x, y, 1 - x - y));


    }


}

void  Polynomial::calculateVolume() {

    //Point (x,y,z) - zerowanie pochodnej

    double x = -(4 * b * c * g - f * f * g - 2 * c * d * h + e * f * h - 2 * b * e * i + d * f * i) /
               (2 * (4 * a * b * c - c * d * d - b * e * e + d * e * f - a * f * f));

    double y = -(2 * c * d * g - e * f * g - 4 * a * c * h + pow(e, 2) * h - d * e * i + 2 * a * f * i) /
               (2. * (-4 * a * b * c + c * pow(d, 2) + b * pow(e, 2) - d * e * f + a * pow(f, 2)));

    double z = -(2 * b * e * g - d * f * g - d * e * h + 2 * a * f * h - 4 * a * b * i + pow(d, 2) * i) /
               (2. * (-4 * a * b * c + c * pow(d, 2) + b * pow(e, 2) - d * e * f + a * pow(f, 2)));

    if (isInDomain(x, y, z)) {

        checkExtr(this->getValue(x, y, z));
    }

}


double Polynomial::getValue(double x, double y, double z) {
    return a * x * x + b * y * y + c * z * z + d * x * y + e * x * z + f * y * z + g * x + h * y + i * z + j;
}

void  Polynomial::checkExtr(double extr) {

    this->max = this->max > extr ? max : extr;

    this->min = this->min < extr ? min : extr;

}

bool Polynomial::isInDomain(double x, double y, double z) {
    return x >= 0 && x <= 1 && y >= 0 && y <= 1 - x && z >= 0 && z <= 1 - x - y;
}