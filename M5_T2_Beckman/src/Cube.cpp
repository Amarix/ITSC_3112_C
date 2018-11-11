#include "Cube.h"

/**
    Derived from the square class.
**/

Cube::Cube():Square()
{

}

Cube::Cube(int x):Square(x)
{

}

Cube::Cube(int x, std::string color):Square(x, color)
{

}

void Cube::printCube()
{

}

// print the object details
void Cube::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Cube::setName() << std::endl;
    std::cout << "Length: " << Cube::X << std::endl;
    std::cout << "Width: " << Cube::X << std::endl;
    std::cout << "Height: " << Cube::X << std::endl;
    std::cout << "Color: " << Cube::color << std::endl;
    std::cout << "Area: " << Cube::getArea() << std::endl;
    std::cout << std::endl;
}

Cube::~Cube()
{
    //dtor
}
