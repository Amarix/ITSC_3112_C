#ifndef CUBOID_H
#define CUBOID_H
#include "Rectangle.h"


class Cuboid: public Rectangle
{
    public:

        // object definitions
        Cuboid();

        Cuboid(int length, int width, int height);

        Cuboid(int length, int width, int height, std::string color);

        // setters
        std::string setName(){
            name = "Cuboid";
            return name;
        }

        int getArea(){
            area = (X*Y*Z);
            return area;
        }

        // void functions
        void printCuboid();

        void printDims();

        ~Cuboid();

    protected:


    private:
};

#endif // CUBOID_H
