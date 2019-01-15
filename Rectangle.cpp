//-----------------------------------------------
/**
*	This is the implementation file for "Rectangle.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#include "Rectangle.h"


//-----------------------------------------------
/*
The default constructor of the class creates a
rectangle with specified height and width and also
optionally take name and description for the object.
*/
//-----------------------------------------------
Rectangle::Rectangle(int width, int height, const string& description, const string& name) 
	: Shape(description, name) 
{	
	this->height = height;
	this->width = width;
}

//-----------------------------------------------
/*
This function returns the string representation of
the shape object specifying its name, description,
id, width, height, area and perimeter.
*/
//-----------------------------------------------
string Rectangle::toString() const {
	
	Shape::toString();

	cout << fixed << setprecision(2);
	cout << setw(15) << left << "Shape name: " << this->getName() << "\n";
	cout << setw(15) << left << "Description: " << this->getDescription() << "\n";
	cout << setw(15) << left << "id: " << this->getId() << "\n";
	cout << setw(15) << left << "B. box width: " << this->width << "\n";
	cout << setw(15) << left << "B. box height: " << this->height << "\n";
	cout << setw(15) << left << "Scr area: " << this->screenArea() << "\n";
	cout << setw(15) << left << "Geo area: " << this->area() << "\n";
	cout << setw(15) << left << "Scr perimeter: " << this->screenPerimeter() << "\n";
	cout << setw(15) << left << "Geo perimeter: " << this->perimeter() << "\n";
	return "";
}

//-----------------------------------------------
/*
This function returns the height of the bounding
box of the shape
*/
//-----------------------------------------------
int Rectangle::getHeight() const {
	return this->height;
}
//-----------------------------------------------
/*
This function returns the width of the bounding
box of the shape
*/
//-----------------------------------------------
int Rectangle::getWidth() const {
	return this->width;
}
//-----------------------------------------------
/*
This function returns the geometric area of the 
shape
*/
//-----------------------------------------------
double Rectangle::area() const {
	return this->height*this->width;
}
//-----------------------------------------------
/*
This function returns the screen area of the
shape
*/
//-----------------------------------------------
int Rectangle::screenArea() const {
	return this->height*this->width;
}
//-----------------------------------------------
/*
This function returns the geometric perimeter of
the shape
*/
//-----------------------------------------------
double Rectangle::perimeter() const {
	return 2*(this->height+this->width);
}
//-----------------------------------------------
/*
This function returns the screen perimeter of the
shape
*/
//-----------------------------------------------
int Rectangle::screenPerimeter() const {
	return (2*(this->height+this->width))-4;
}

//-----------------------------------------------
/*
This function draws the shape on the canvas
@param  canvas, canvas object
@param  row,	row number where the shape is to be drawn
@param  row,	column number where the shape is to be drawn
@param  fchar,	character representing the shape
@param  bchar,	character representing the background
*/
//-----------------------------------------------
void Rectangle::draw(Canvas& canvas, int row, int col, char fChar, char bChar) const {
	for (int r = 0; r < this->getHeight(); r++) {
		for (int c = 0; c < this->getWidth(); c++) {
			canvas[row + r][col + c] = fChar;		//unchecked by vector
			//canvas.put(row + r, col + c, fChar);	//checked by Canvas
		}
	}
}

//-----------------------------------------------
/*
overloaded insertion operator to write string
representation of object to console
*/
//-----------------------------------------------
ostream& operator<<(ostream& out, const Rectangle& r) {
	//out << "hi";
	r.toString();
	return out;
}