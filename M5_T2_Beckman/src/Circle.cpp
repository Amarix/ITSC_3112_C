#include "Circle.h"

/**
    The definitions in the Circle class are different than
    the definitions within the Square and Rectangle class
    so the Circle class is derived directly from Shape.
    The Circle class defines the Ellipse and Ellipsoid class
    and so has inherited these definitions from the Shape class.
**/

Circle::Circle():Shape()
{

}

Circle::Circle(int r):Shape(r)
{

}

Circle::Circle(int r, std::string color):Shape(r, color)
{

}

Circle::Circle(int aAx, int bAx):Shape(aAx, bAx)
{

}

Circle::Circle(int aAx, int bAx, std::string color):Shape(aAx, bAx, color)
{

}

Circle::Circle(int aAx, int bAx, int cAx):Shape(aAx, bAx, cAx)
{

}

Circle::Circle(int aAx, int bAx, int cAx, std::string color):Shape(aAx, bAx, cAx, color)
{

}

void Circle::printCircle()
{

}

// print the object details
void Circle::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Circle::setName() << std::endl;
    std::cout << "Radius: " << Circle::X << std::endl;
    std::cout << "Color: " << Circle::color << std::endl;
    std::cout << "Area: " << Circle::getArea() << std::endl;
    std::cout << std::endl;
}

Circle::~Circle()
{
    //dtor
}
