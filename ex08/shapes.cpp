#include "shapes.h"
#include <cmath>
#include <algorithm>

using namespace std;

Rectangle::Rectangle(double height, double width) : _height(height), _width(width) {}
Square::Square(double side) : _side(side) {}
Circle::Circle(double radius) : _radius(radius) {}

double Rectangle::area() const { return _height * _width; }
double Rectangle::perimeter() const { return 2 * (_height + _width); }
double Rectangle::height() const { return _height; }
double Rectangle::width() const { return _width; }
void Rectangle::rotate() { swap(_height, _width); }

double Square::area() const { return _side * _side; }
double Square::perimeter() const { return 4 * _side; }
double Square::height() const { return _side; }
double Square::width() const { return _side; }
void Square::rotate() { swap (_side, _side); }

double Circle::area() const { return M_PI * _radius * _radius; }
double Circle::perimeter() const { return 2 * M_PI * _radius; }
double Circle::height() const { return 2 * _radius; }
double Circle::width() const { return 2 * _radius; }
void Circle::rotate() { swap (_radius, _radius); }
