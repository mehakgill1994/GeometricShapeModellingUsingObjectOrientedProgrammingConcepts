//-----------------------------------------------
/**
*	The is the header file for Right Triangle class.
This file describes all the functions required
for the working of Right Triangle object.
It inherits all its functionalities from the
Shape and Isosceles class.

The default constructor of the class creates a
Right Triangle with specified height and width and also
optionally take name and description for the object.

The header file contains the description of functions
to represent the Right Triangle object on screen, calculate
geometric and screen area, geometric and screen perimeter
and draw it on canvas at given x and y values.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Isosceles.h"

class RightTriangle :public Isosceles {
private:
	int base, height;
	vector<vector<bool>> foreground;
	void setForeground();
public:
	RightTriangle(int, const string& = "Class RightTriangle", const string& = "RightTriangle");
	virtual int getHeight() const override;
	virtual int getWidth() const override;
	virtual double area() const override;
	virtual string toString() const override;
	virtual double perimeter() const override;
	virtual int screenArea() const override;
	virtual int screenPerimeter() const override;
	virtual void draw(Canvas&, int, int, char = '*', char = ' ') const override;
	friend ostream& operator<<(ostream&, const RightTriangle&);
};

#endif // !RIGHTTRIANGLE_H
