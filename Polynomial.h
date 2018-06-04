//
// Created by laszlothebrave on 6/4/2018.
//

#ifndef ZADANIEPROJEKTOWE3_POLYNOMIAL_H
#define ZADANIEPROJEKTOWE3_POLYNOMIAL_H


class Polynomial {
public:
    double tab[15];
    double a,b,c,d,e,f,g,h,i,j,min,max;
    Polynomial(double a, double b, double c, double d, double e, double f, double g, double h, double i);

    Polynomial getEuklides();

    int getJ();

    int getMax();

    void setMax();

    void setJ();

    void calculatePoints();

    void calculateLines();

    void calculateAreas();

    void calculateVolume();

    double getValue(int x, int y, int z);
};


#endif //ZADANIEPROJEKTOWE3_POLYNOMIAL_H
