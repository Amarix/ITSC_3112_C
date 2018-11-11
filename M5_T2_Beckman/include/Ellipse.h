#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Circle.h"
#include <math.h>

class Ellipse: public Circle
{
    public:

        // object definitions
        Ellipse();

        Ellipse(int rMax, int rMin);

        Ellipse(int rMax, int rMin, std::string color);

        Ellipse(int aAx, int bAx, int cAx);

        Ellipse(int aAx, int bAx, int cAx, std::string color);

        // setters
        std::string setName(){
            name = "Ellipse";
            return name;
        }

        int getArea(){
            area = (M_PI*X*Y);
            return area;
        }

        // void functions
        void printEllipse();

        void printDims();

        ~Ellipse();

    protected:

    private:
};

#endif // ELLIPSE_H
