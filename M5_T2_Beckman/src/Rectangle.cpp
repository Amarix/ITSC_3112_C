#include "Rectangle.h"

/**
    Due to having a second variable the Rectangle class is
    derived directly from the shape class.
    The Cuboid class is derived from the Rectangle class
    so the Rectangle class has definitions for the Cuboid class.
**/
Rectangle::Rectangle():Shape()
{

}

Rectangle::Rectangle(int length, int width):Shape(length, width)
{

}

Rectangle::Rectangle(int length, int width, std::string color):Shape(length, width, color)
{

}

Rectangle::Rectangle(int length, int width, int height):Shape(length, width, height)
{

}

Rectangle::Rectangle(int length, int width, int height, std::string color):Shape(length, width, height, color)
{

}

void Rectangle::printRectangle()
{

}

// print the object details
void Rectangle::printDims()
{
    std::cout << std::endl;
    std::cout << "Printing Dims: " << Rectangle::setName() << std::endl;
    std::cout << "Length: " << Rectangle::X << std::endl;
    std::cout << "Width: " << Rectangle::Y << std::endl;
    std::cout << "Color: " << Rectangle::color << std::endl;
    std::cout << "Area: " << Rectangle::getArea() << std::endl;
    std::cout << std::endl;
}

Rectangle::~Rectangle()
{
    //dtor
}
