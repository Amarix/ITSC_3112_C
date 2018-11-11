#include "Cuboid.h"

/**
    The Cuboid class is derived from the Rectangle class.
**/

Cuboid::Cuboid():Rectangle()
{

}

Cuboid::Cuboid(int length, int width, int height):Rectangle(length, width, height)
{

}

Cuboid::Cuboid(int length, int width, int height, std::string color):Rectangle(length, width, height, color)
{

}

void Cuboid::printCuboid()
{

}

// print the object details
void Cuboid::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Cuboid::setName() << std::endl;
    std::cout << "Length: " << Cuboid::X << std::endl;
    std::cout << "Width: " << Cuboid::Y << std::endl;
    std::cout << "Height: " << Cuboid::Z << std::endl;
    std::cout << "Color: " << Cuboid::color << std::endl;
    std::cout << "Area: " << Cuboid::area << std::endl;
    std::cout << std::endl;
}

Cuboid::~Cuboid()
{
    //dtor
}
