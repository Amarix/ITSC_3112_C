#ifndef CUBE_H
#define CUBE_H
#include "Square.h"


class Cube: public Square
{
    public:

        // object definitions
        Cube();

        Cube(int coord);

        Cube(int coord, std::string color);

        // setters
        std::string setName(){
            name = "Cube";
            return name;
        }

        int getArea(){
            area = (X*X*X);
            return area;
        }

        // void functions
        void printCube();

        void printDims();

        ~Cube();

    protected:


    private:
};

#endif // CUBE_H
