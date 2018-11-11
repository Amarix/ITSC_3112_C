#include <iostream>
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Ellipse.h"
#include "Ellipsoid.h"

using namespace std;

int main()
{
	cout << "Testing Inheritance.." << endl;
	cout << "**********************" << endl;
	Square *sq = new Square();
	sq->printSquare();

	Square *sq2 = new Square(10);
	sq2->printSquare();

	Rectangle *rect = new Rectangle();
	rect->setColor ("cyan");
	rect->printDims();

	Rectangle *rect2 = new Rectangle(5, 10);
	rect2->setColor ("green");
	rect2->printDims();

	Cube *c = new Cube(5, "blue");
	c->printDims();

	Circle *circ = new Circle(10, "pink");
	circ->printDims();

	Ellipse *ellipse = new Ellipse (5, 3, "magenta");
	ellipse->printDims();

	Ellipsoid *ellipsoid = new Ellipsoid (4, 8, 3, "purple");
	ellipsoid->printDims();

							// test polymorphism
	cout << "Testing Polymorphism.." << endl;
	cout << "**********************" << endl;
	Shape *shape;
	shape = sq2;
	cout << "Testing Polymorphism.." << endl;
	shape->printDims();

	cout << "Name:" << shape->getName() << endl;

	ellipse = ellipsoid;
	ellipse->printDims();

	cout << "Name: " << ellipse->getName() << endl;

	Cube *cube = new Cube(10);
	sq2 = cube;
	sq2->printDims();
	cout << "Name: " << sq2->getName() << endl;

	circ = ellipse;
	circ->printDims();
	cout << "Name: " << circ->getName() << endl;

}
