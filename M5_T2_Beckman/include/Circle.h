#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <math.h>


class Circle: public Shape
{
    public:

        // object definitions
        Circle();

        Circle(int r);

        Circle(int r, std::string color);

        Circle(int aAx, int bAx);

        Circle(int aAx, int bAx, std::string color);

        Circle(int aAx, int bAx, int cAx);

        Circle(int aAx, int bAx, int cAx, std::string color);

        // setters
        std::string setName(){
            name = "Circle";
            return name;
        }

        int getArea(){
            area = (M_PI*X*X);
            return area;
        }

        // void functions
        void printCircle();

        void printDims();

        ~Circle();

    protected:

    private:
};

#endif // CIRCLE_H
