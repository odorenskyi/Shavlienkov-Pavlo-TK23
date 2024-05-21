#ifndef MODULESSHAVLIENKOV_H_INCLUDED
#define MODULESSHAVLIENKOV_H_INCLUDED

#include <cmath>

using namespace std;

class ClassLab12_Shavlienkov {
    private:
        double a;
        double b;

    public:

        ClassLab12_Shavlienkov(double a, double b) {
            setA(a);
            setB(b);
        }

        double getA() {
            return a;
        }

        double getB() {
            return b;
        }

        void setA(double newA) {
            if (newA > 0) {
                a = newA;
            } else {
                throw invalid_argument("FAILED");
            }
        }

        void setB(double newB) {
            if (newB > 0) {
                b = newB;
            } else {
                 throw invalid_argument("FAILED");
            }
        }

        double getArea() {
            return M_PI * a * b;
        }
};

#endif // MODULESSHAVLIENKOV_H_INCLUDED
