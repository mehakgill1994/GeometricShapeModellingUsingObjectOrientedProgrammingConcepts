//-----------------------------------------------
/**
*	This is the implementation file for "RightTriangle.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#include "RightTriangle.h"

//-----------------------------------------------
/*
The default constructor of the class creates a
rectangle with specified base and also
optionally take name and description for the object.
*/
//-----------------------------------------------
RightTriangle::RightTriangle(int base, const string& description, const string& name)
	: Isosceles(description, name)
{
	this->base = base;
	this->height = base;
	setForeground();
}

//-----------------------------------------------
/*
This function returns the string representation of
the shape object specifying its name, description,
id, width, height, area and perimeter.
*/
//-----------------------------------------------
string RightTriangle::toString() const {
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
int RightTriangle::getHeight() const {
	return this->height;
}
//-----------------------------------------------
/*
This function returns the width of the bounding
box of the shape
*/
//-----------------------------------------------
int RightTriangle::getWidth() const {
	return this->base;
}
//-----------------------------------------------
/*
This function returns the geometric area of the
shape
*/
//-----------------------------------------------
double RightTriangle::area() const {
	return static_cast<double>(getHeight()*getWidth()) / 2;
}
//-----------------------------------------------
/*
This function returns the screen area of the
shape
*/
//-----------------------------------------------
int RightTriangle::screenArea() const {
	return (height*(height + 1)) / 2;
}
//-----------------------------------------------
/*
This function returns the geometric perimeter of
the shape
*/
//-----------------------------------------------
double RightTriangle::perimeter() const {
	return (2 + static_cast<double>(sqrt(2)))*height;
}
//-----------------------------------------------
/*
This function returns the screen perimeter of the
shape
*/
//-----------------------------------------------
int RightTriangle::screenPerimeter() const {
	return 3 * (height - 1);
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
void RightTriangle::draw(Canvas& canvas, int row, int col, char fChar, char bChar) const {
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
ostream& operator<<(ostream& out, const RightTriangle& r) {
	r.toString();
	return out;
}


//Helper function
void RightTriangle::setForeground() {
	//initialize foreground vector to false
	vector<bool> temp;
	for (int i = 0; i < getWidth(); i++) {
		temp.push_back(false);
	}
	for (int j = 0; j < getHeight(); j++) {
		foreground.push_back(temp);
	}

	//setting the foreground to true
	for (int k = 0; k < getHeight(); k++) {
		for (int l = 0; l < k; l++) {
			foreground[k][l] = true;
		}
	}
}