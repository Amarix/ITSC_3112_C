#include "Shape.h"

// shape definitions
/**
    Definitions of the shape hierarchy.
    The shape class has a definition of all possible shapes.
    It is used to set the paramaters and dimensions of all other shapes.
    All other shapes are derived from it.
**/

Shape::Shape()
{

}

Shape::Shape(int x)
{
    Shape::X = x;
    Shape::Y = x;
}

Shape::Shape(int x, std::string color)
{
    Shape::X = x;
    Shape::color = color;
}

Shape::Shape(int x, int y)
{
    Shape::X = x;
    Shape::Y = y;
}

Shape::Shape(int x, int y, std::string color)
{
    Shape::X = x;
    Shape::Y = y;
    Shape::color = color;
}

Shape::Shape(int x, int y, int z)
{
    Shape::X = x;
    Shape::Y = y;
    Shape::Z = z;
}

Shape::Shape(int x, int y, int z, std::string color)
{
    Shape::X = x;
    Shape::Y = y;
    Shape::Z = z;
    Shape::color = color;
}

// getters

int Shape::getX()
{
    return Shape::X;
}

int Shape::getY()
{
    return Shape::Y;
}

int Shape::getZ()
{
    return Shape::Z;
}

std::string Shape::getName()
{
    return Shape::name;
}

std::string Shape::getColor()
{
    return Shape::color;
}

int Shape::getArea()
{
    return area;
}

// setters

void Shape::setName(std::string nm)
{
    Shape::name = nm;
}

void Shape::setColor(std::string clr)
{
    Shape::color = clr;
}

// void functions

void Shape::printShape()
{

}

void Shape::printDims()
{

}

Shape::~Shape()
{

}
