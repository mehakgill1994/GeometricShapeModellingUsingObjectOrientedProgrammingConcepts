//-----------------------------------------------
/**
*	The is the header file for Rectangle class.
This file describes all the functions required
for the working of Rectangle object.
It inherits all its functionalities from the 
Shape class.

The default constructor of the class creates a
rectangle with specified height and width and also
optionally take name and description for the object.

The header file contains the description of functions
to represent the rectangle object on screen, calculate
geometric and screen area, geometric and screen perimeter
and draw it on canvas at given x and y values.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <iomanip>

using namespace std;

class Rectangle : public Shape {
private:
	int height, width;
public:
	Rectangle(int, int, const string& = "Class Rectangle", const string& = "Rectangle");
	virtual string toString() const override;
	virtual int getHeight() const override;
	virtual int getWidth() const override;
	virtual double area() const override;
	virtual double perimeter() const override;
	virtual int screenArea() const override;
	virtual int screenPerimeter() const override;
	virtual void draw(Canvas&, int, int, char = '*', char = ' ') const override;
	friend ostream& operator<<(ostream&, const Rectangle&);
};

#endif // !RECTANGLE_H
