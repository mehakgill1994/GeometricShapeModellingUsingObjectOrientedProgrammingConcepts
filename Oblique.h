//-----------------------------------------------
/**
*	The is the header file for Oblique class.
This file describes all the functions required
for the working of Oblique object.
It inherits all its functionalities from the
Shape and Isosceles class.

The default constructor of the class creates a
Oblique with specified height and width and also
optionally take name and description for the object.

The header file contains the description of functions
to represent the Oblique object on screen, calculate
geometric and screen area, geometric and screen perimeter
and draw it on canvas at given x and y values.

*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------
#ifndef OBLIQUE_H
#define OBLIQUE_H

#include "Isosceles.h"

class Oblique :public Isosceles {
private:
	int base, height;
	vector<vector<bool>> foreground;
	void setForeground();
public:
	Oblique(int, const string& = "Class Oblique", const string& = "Oblique");
	virtual int getHeight() const override;
	virtual int getWidth() const override;
	virtual double area() const override;
	virtual string toString() const override;
	virtual double perimeter() const override;
	virtual int screenArea() const override;
	virtual int screenPerimeter() const override;
	virtual void draw(Canvas&, int, int, char = '*', char = ' ') const override;
	friend ostream& operator<<(ostream&, const Oblique&);
};
#endif // OBLIQUE_H
