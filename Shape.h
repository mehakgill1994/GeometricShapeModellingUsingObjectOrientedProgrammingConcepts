//-----------------------------------------------
/**
*	The is the header file for shape class.
It inherits all its functionalities from the
Shape class.

This is an abstract class.

The header file contains the description of functions
to represent the shape object on screen, calculate
geometric and screen area, geometric and screen perimeter
and draw it on canvas at given x and y values.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Canvas.h"
using namespace std;

class Shape {
private:
	static int count;
	int id;
	string name;
	string description;
public:
	Shape(const string &, const string &);
	virtual ~Shape() = default;

	int getId() const;

	void setName(const string &);
	string getName() const;

	void setDescription(const string &);
	string getDescription() const;

	virtual string toString() const;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual int screenArea() const = 0;
	virtual int screenPerimeter() const = 0;
	virtual void draw(Canvas& canvas, int row, int col, char foreChar = '*', char backChar = ' ') const = 0;
	virtual int getHeight() const = 0;
	virtual int getWidth() const = 0;
};

#endif // !SHAPE_H
