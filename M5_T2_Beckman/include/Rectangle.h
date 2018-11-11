#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"


class Rectangle: public Shape
{
    public:

        // object definitions
        Rectangle();

        Rectangle(int length, int width);

        Rectangle(int length, int width, std::string color);

        Rectangle(int length, int width, int height);

        Rectangle(int length, int width, int height, std::string color);

        // setters
        int getArea(){
            area = (X*Y);
            return area;
        }

        std::string setName(){
            name = "Rectangle";
            return name;
        }

        // void functions
        void printRectangle();

        void printDims();

        ~Rectangle();

    protected:

    private:
};

#endif // RECTANGLE_H
