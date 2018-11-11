#include "Square.h"

/**
    The square class is derived from the shape class.
    However, the cube class is derived from square.
    Square class will have definitions for cube class
    which are also derived from the shape class.
**/
Square::Square():Shape()
{

}

Square::Square(int x):Shape(x)
{

}

Square::Square(int x, std::string color):Shape(x, color)
{

}

// prints a square using the X value to determine the length and height
void Square::printSquare()
{
    std::cout << "Printing Square: " << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < Square::X; i++)
    {
        for (int k = 0; k < Square::X; k++)
        {
            std::cout << "XX";
        }
        std::cout << std::endl;
    }
    std::cout << "___Square End___" << std::endl;
}

// print the object details
void Square::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Square::setName() << std::endl;
    std::cout << "x: " << Square::X << std::endl;
    std::cout << "y: " << Square::X << std::endl;
    std::cout << "Color: " << Square::color << std::endl;
    std::cout << "Area: " << Square::getArea() << std::endl;
    std::cout << std::endl;
}

Square::~Square()
{
    //dtor
}
