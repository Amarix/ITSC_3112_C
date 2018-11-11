#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cstring>


class Shape
{
    public:

        // shape definitions

        Shape();

        Shape(int x);

        Shape(int x, std::string color);

        Shape(int x, int y);

        Shape(int x, int y, std::string color);

        Shape(int x, int y, int z);

        Shape(int x, int y, int z, std::string color);

        // getters

        int getX();

        int getY();

        int getZ();

        std::string getName();

        std::string getColor();

        int getArea();

        // setters

        void setName(std::string nm);

        void setColor(std::string clr);

        // void functions

        virtual void printDims();

        virtual void printShape();


        ~Shape();

    protected:

        int X;

        int Y;

        int Z;

        std::string name;

        std::string color;

        int area;

    private:
};

#endif // SHAPE_H
