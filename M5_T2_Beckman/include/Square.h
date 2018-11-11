#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"


class Square: public Shape
{
    public:

        // object definitions
        Square();

        Square(int x);

        Square(int x, std::string color);

        // setters
        std::string setName(){
            name = "Square";
            return name;
        }

        int getArea(){
            area = (X*X);
            return (area);
        }

        // void functions
        void printDims();

        void printSquare();

        ~Square();

    protected:


    private:
};

#endif // SQUARE_H
