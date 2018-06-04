#include <bits/stdc++.h>
#include "Polynomial.h"

using namespace std;

const double obszar_lower = 1/4.;
const double obszar_upper = 3/4.;
const double obszar_jump = 1/4.;
const double zakres = 1;
double counter = 0;

void checkPoint(double a, double d, double c);

void checkPolynomial(int a, int b, int c, int d, int e, int f, double g, double h, double i);

int main() {
    //orginalny punkt x=1/2 y=1/4 z=1/4
    freopen("test2", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (double a=obszar_lower ; a<=obszar_upper ; a+=obszar_jump) {
        for (double b=obszar_lower ; b<=obszar_upper ; b+=obszar_jump) {
            for (double c=obszar_lower ; c<=obszar_upper ; c+=obszar_jump) {
                checkPoint(a, b, c);
            }
        }
    }
    return 0;
}

void checkPoint(double v1, double v2, double v3) {
    for (int a=-zakres ; a<=zakres ; a++) {
        for (int b=-zakres ; b<=zakres ; b++) {
            for (int c=-zakres ; c<=zakres ; c++) {
                for (int d=-zakres ; d<=zakres ; d++) {
                    for (int e=-zakres ; e<=zakres ; e++) {
                        for (int f=-zakres ; f<=zakres ; f++) {
                            checkPolynomial(a, b, c, d, e, f, -v1*2*a,-v2*2*b,-v3*2*c);
                        }
                    }
                }
            }
        }
    }
}

void checkPolynomial(int a, int b, int c, int d, int e, int f, double g, double h, double i) {
    Polynomial polynomial(a,b,c,d,e,f,g,h,i);
    Polynomial euklidesSquare = polynomial.getEuklides();
    polynomial.setMax();
    euklidesSquare.setMax();
    polynomial.setJ();
    int j = polynomial.getJ();
    int euklidesSquareMax = euklidesSquare.getMax();
    int maxAbs = 2;
    if(euklidesSquareMax/(maxAbs*maxAbs) > 323/1.5625) {
        cout << "Wielomian numer " << counter++ << endl;
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << endl;
        cout << sqrt(euklidesSquareMax/(maxAbs*maxAbs)) << endl << endl;
    }
}