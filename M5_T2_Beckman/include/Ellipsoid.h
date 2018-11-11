#ifndef ELLIPSOID_H
#define ELLIPSOID_H
#include "Ellipse.h"
#include <math.h>

class Ellipsoid: public Ellipse
{
    public:

        // object definitions
        Ellipsoid();

        Ellipsoid(int aAx, int bAx, int cAx);

        Ellipsoid(int aAx, int bAx, int cAx, std::string color);

        // setters
        int getArea(){
            // Area variables
            int pwrAB = pow((X*Y), 1.6);
            int pwrAC = pow((X*Z), 1.6);
            int pwrBC = pow((Y*Z), 1.6);
            int dvdThree = (pwrAB+pwrAC+pwrBC)/3;
            int pwrAll = pow(dvdThree, (1/1.6));

            // final equation
            int area = (4*M_PI)*pwrAll;

            return area;
        };

        std::string setName(){
            name = "Ellipsoid";
            return name;
        }

        // void functions
        void printEllipsoid();

        void printDims();

        ~Ellipsoid();

    protected:

    private:
};

#endif // ELLIPSOID_H
