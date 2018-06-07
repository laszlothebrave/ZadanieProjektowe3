//
// Created by laszlothebrave on 6/4/2018.
//

#ifndef ZADANIEPROJEKTOWE3_POLYNOMIAL_H
#define ZADANIEPROJEKTOWE3_POLYNOMIAL_H


class Polynomial {
public:

    double a, b, c, d, e, f, g, h, i, j, min, max;

    Polynomial(const double &a,
               const double &b,
               const double &c,
               const double &d,
               const double &e,
               const double &f,
               const double &g,
               const double &h,
               const double &i,
               double j);

    Polynomial getEuklides();

    double getJ();

    double getMax();

    void setMax();

    void setJ();

    void calculatePoints();

    void calculateLines();

    void calculateAreas();

    void calculateVolume();

    void checkExtr(double maxProp);

    double getValue(double x, double y, double z);

    bool isInDomain(double x, double y, double z);
};


#endif //ZADANIEPROJEKTOWE3_POLYNOMIAL_H