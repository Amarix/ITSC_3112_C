#include "Ellipsoid.h"

/**
    Derived from the Ellpise class.
**/

Ellipsoid::Ellipsoid():Ellipse()
{

}

Ellipsoid::Ellipsoid(int aAx, int bAx, int cAx):Ellipse(aAx, bAx, cAx)
{

}

Ellipsoid::Ellipsoid(int aAx, int bAx, int cAx, std::string color):Ellipse(aAx, bAx, cAx, color)
{

}

void Ellipsoid::printEllipsoid()
{

}

// print the object details
void Ellipsoid::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Ellipsoid::setName() << std::endl;
    std::cout << "Axis Major: " << Ellipsoid::X << std::endl;
    std::cout << "Axis Minor: " << Ellipsoid::Y << std::endl;
    std::cout << "Z Axis: " << Ellipsoid::Z << std::endl;
    std::cout << "Color: " << Ellipsoid::color << std::endl;
    std::cout << "Area: " << Ellipsoid::getArea() << std::endl;
    std::cout << std::endl;
}

Ellipsoid::~Ellipsoid()
{
    //dtor
}
