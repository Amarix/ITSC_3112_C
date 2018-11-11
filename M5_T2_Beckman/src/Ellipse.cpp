#include "Ellipse.h"

/**
    Ellipse is derived from the Circle class and also
    inherits the definitions for the Ellipsoid class.
**/

Ellipse::Ellipse():Circle()
{

}

Ellipse::Ellipse(int rMax, int rMin):Circle(rMax, rMin)
{

}

Ellipse::Ellipse(int rMax, int rMin, std::string color):Circle(rMax, rMin, color)
{

}

Ellipse::Ellipse(int aAx, int bAx, int cAx):Circle(aAx, bAx, cAx)
{

}

Ellipse::Ellipse(int aAx, int bAx, int cAx, std::string color):Circle(aAx, bAx, cAx, color)
{

}

void Ellipse::printEllipse()
{

}

// print the object details
void Ellipse::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Ellipse::setName() << std::endl;
    std::cout << "Axis Major: " << Ellipse::X << std::endl;
    std::cout << "Axis Minor: " << Ellipse::Y << std::endl;
    std::cout << "Color: " << Ellipse::color << std::endl;
    std::cout << "Area: " << Ellipse::getArea() << std::endl;
    std::cout << std::endl;
}

Ellipse::~Ellipse()
{
    //dtor
}
