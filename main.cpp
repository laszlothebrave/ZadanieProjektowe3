#include <bits/stdc++.h>
#include "Polynomial.h"

using namespace std;

double limit = 323./1.5625;

const double obszar_lower1 = 50/100.;
const double obszar_upper1 = 50/100.;
const double obszar_lower2 = -1/6.;
const double obszar_upper2 = -1/6.;
const double obszar_lower3 = -1/12.;
const double obszar_upper3 = -1/12.;
const double obszar_jump = 1/100.;
const double zakres = 10;

int counter = 0;
long nrPoly = 0;


void checkPoint(double a, double d, double c);

void checkPolynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f, const double& g, const double& h, const double& i);

int main() {
    //orginalny punkt x=1/2 y=1/4 z=1/4
    //nowy punkt x=1/2 y=0 z=0

    //freopen("test2", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //checkPolynomial(9 ,-4 ,-4 ,9, 9, -9, -9 ,2, 2  );

    auto start = std::chrono::system_clock::now();

    //checkPoint( 0.5,0.25,0.25 );

    //checkPolynomial( -12 ,-12 ,24 ,-24 ,24 ,24 ,6 ,6 ,-24 );

   for (double a=obszar_lower1 ; a<=obszar_upper1 ; a+=obszar_jump) {
        for (double b=obszar_lower2 ; b<=obszar_upper2 ; b+=obszar_jump) {
            for (double c=obszar_lower3 ; c<=obszar_upper3 ; c+=obszar_jump) {

                checkPoint(a, b, c);
            }
        }

        std::cout << a<<"................................................................\n";

    }


    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double>elapsed = end - start;

    double average = nrPoly/elapsed.count();

    cout << elapsed.count()<<"\n";

    cout << "average (mil/s) =" << average/1.0e+06 << "\n";

    return 0;


}

void checkPoint(double v1, double v2, double v3) {


    for (int a=-zakres ; a<=zakres ; a+=1) {
        for (int b=-zakres ; b<=zakres ; b+=1) {
            for (int c=-zakres ; c<=zakres ; c+=1) {
                for (int d=-zakres ; d<=zakres ; d+=1) {
                    for (int e=-zakres ; e<=zakres ; e+=1) {
                        for (int f=-zakres ; f<=zakres ; f+=1) {
                            checkPolynomial(a, b, c, d, e, f, -v1*2*a,-v2*2*b,-v3*2*c);
                            nrPoly++;
                        }
                    }
                }
            }
        }

        std::cout << a << "\n";

    }
}

void checkPolynomial(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f, const double& g, const double& h, const double& i) {

    Polynomial polynomial(a,b,c,d,e,f,g,h,i,0);

    Polynomial euklidesSquare = polynomial.getEuklides();

    polynomial.setMax();

    euklidesSquare.setMax();

    polynomial.setJ();

    //double j = polynomial.getJ();

    //double euklidesSquareMax = euklidesSquare.getMax();

    //double maxAbs = polynomial.getMax();

    if( (euklidesSquare.getMax() / ( polynomial.getMax() * polynomial.getMax() )) > limit  ) {

        //limit = (euklidesSquare.getMax() / (polynomial.getMax() * polynomial.getMax()))+0.01;

        cout << "Wielomian numer " << counter++ << endl;
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " "
             << polynomial.getJ() << "\n";
        cout << sqrt(euklidesSquare.getMax() / (polynomial.getMax() * polynomial.getMax())) << "\n" << "\n";
    }
}