//-----------------------------------------------
/**
*	This is the implementation file for "Oblique.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#include "Oblique.h"

//-----------------------------------------------
/*
The default constructor of the class creates a
Oblique triangle with specified base and also
optionally take name and description for the object.
*/
//-----------------------------------------------
Oblique::Oblique(int base, const string& description, const string& name) 
:	Isosceles(description, name)
{
	if (base % 2 == 0)
		this->base = base + 1;
	else
		this->base = base;

	this->height = (this->base + 1) / 2;

	setForeground();
}

//-----------------------------------------------
/*
This function returns the string representation of
the shape object specifying its name, description,
id, width, height, area and perimeter.
*/
//-----------------------------------------------
string Oblique::toString() const {
	Isosceles::toString();

	cout << fixed << setprecision(2);

	cout << setw(15) << left << "Shape name: " << this->getName() << "\n";
	cout << setw(15) << left << "Description: " << this->getDescription() << "\n";
	cout << setw(15) << left << "id: " << this->getId() << "\n";
	cout << setw(15) << left << "B. box width: " << this->base << "\n";
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
int Oblique::getHeight() const {
	return this->height;
}
//-----------------------------------------------
/*
This function returns the width of the bounding
box of the shape
*/
//-----------------------------------------------
int Oblique::getWidth() const {
	return this->base;
}
//-----------------------------------------------
/*
This function returns the geometric area of the
shape
*/
//-----------------------------------------------
double Oblique::area() const {
	return static_cast<double>(getHeight()*getWidth()) / 2;
}
//-----------------------------------------------
/*
This function returns the screen area of the
shape
*/
//-----------------------------------------------
int Oblique::screenArea() const {
	return getHeight()*getHeight();
}
//-----------------------------------------------
/*
This function returns the geometric perimeter of
shape
*/
//-----------------------------------------------
double Oblique::perimeter() const {
	return static_cast<double>(base + (2 * sqrt((0.25*base*base) + (height*height))));
}
//-----------------------------------------------
/*
This function returns the screen perimeter of the
shape
*/
//-----------------------------------------------
int Oblique::screenPerimeter() const {
	return 4 * (height - 1);
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
void Oblique::draw(Canvas& canvas, int row, int col, char fChar, char bChar) const {
	for (int r = 0; r < this->getHeight(); r++) {
		for (int c = 0; c < this->getWidth(); c++) {
			
			if (foreground[r][c])
				canvas[row + r][col + c] = fChar;
			else
				canvas[row + r][col + c] = bChar;
		}
	}
}

//-----------------------------------------------
/*
overloaded insertion operator to write string
representation of object to console
*/
//-----------------------------------------------
ostream& operator<<(ostream& out, const Oblique& o) {
	o.toString();
	return out;
}


//Helper Function
void Oblique::setForeground() {

	for (int i = 0; i <= height; i++) {
		vector<bool> temp;
		for (int k = height - i; k > 1; k--) {
			temp.push_back(false);
		}
		for (int j = 1; j <= (2 * i) + 1; j++) {
			temp.push_back(true);
		}
		for (int k = height - i; k > 1; k--) {
			temp.push_back(false);
		}
		foreground.push_back(temp);
	}
}