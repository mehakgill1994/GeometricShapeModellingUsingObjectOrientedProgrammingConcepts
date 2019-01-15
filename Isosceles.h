//-----------------------------------------------
/**
*	The is the header file for Isosceles class.
It inherits all its functionalities from the
Shape class.

This is an abstract class.

The header file contains the description of functions
to represent the isosceles object on screen, calculate
geometric and screen area, geometric and screen perimeter
and draw it on canvas at given x and y values.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Shape.h"
#include <string>
#include <iostream>
#include <typeinfo>
#include <iomanip>

using namespace std;

class Isosceles : public Shape {
private:
	int height, base;
public:
	Isosceles(const string&, const string&);
	virtual string toString() const override;
	virtual int getHeight() const override = 0;
	virtual int getWidth() const override = 0;
	virtual double area() const override = 0;
	virtual double perimeter() const override = 0;
	virtual int screenArea() const override = 0;
	virtual int screenPerimeter() const override = 0;
	virtual void draw(Canvas&, int, int, char = '*', char = ' ') const override = 0;
};

#endif // !ISOSCELES_H
