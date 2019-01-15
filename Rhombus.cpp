//-----------------------------------------------
/**
*	This is the implementation file for "Rhombus.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#include "Rhombus.h"

//-----------------------------------------------
/*
The default constructor of the class creates a
rhombus with specified height and width and also
optionally take name and description for the object.
*/
//-----------------------------------------------
Rhombus::Rhombus(int d, const string& description, const string& name)
	: Shape(description, name)
{
	if(d%2 == 0)
		this->d = d+1;
	else
		this->d = d;

	setForeground();
}

//-----------------------------------------------
/*
This function returns the string representation of
the shape object specifying its name, description,
id, width, height, area and perimeter.
*/
//-----------------------------------------------
string Rhombus::toString() const {

	Shape::toString();

	cout << fixed << setprecision(2);

	cout << setw(15) << left << "Shape name: " << this->getName() << "\n";
	cout << setw(15) << left << "Description: " << this->getDescription() << "\n";
	cout << setw(15) << left << "id: " << this->getId() << "\n";
	cout << setw(15) << left << "B. box width: " << this->d << "\n";
	cout << setw(15) << left << "B. box height: " << this->d << "\n";
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
int Rhombus::getHeight() const {
	return this->d;
}
//-----------------------------------------------
/*
This function returns the width of the bounding
box of the shape
*/
//-----------------------------------------------
int Rhombus::getWidth() const {
	return this->d;
}
//-----------------------------------------------
/*
This function returns the geometric area of the
shape
*/
//-----------------------------------------------
double Rhombus::area() const {
	return static_cast<double>(this->d*this->d)/2;
}
//-----------------------------------------------
/*
This function returns the screen area of the
shape
*/
//-----------------------------------------------
int Rhombus::screenArea() const {
	int n = this->d / 2;
	return ((2*n)*(n+1))+1;
}
//-----------------------------------------------
/*
This function returns the screen perimeter of the
shape
*/
//-----------------------------------------------
double Rhombus::perimeter() const {
	return 2*sqrt(2)*this->d;
}
//-----------------------------------------------
/*
This function returns the screen perimeter of the
shape
*/
//-----------------------------------------------
int Rhombus::screenPerimeter() const {
	return 2 * (this->d - 1);
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
void Rhombus::draw(Canvas& canvas, int row, int col, char fChar, char bChar) const {
	for (int r = 0; r < this->getHeight(); r++) {
		for (int c = 0; c < this->getWidth(); c++) {
			if(foreground[r][c])
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
ostream& operator<<(ostream& out, const Rhombus& r) {
	//out << "hi";
	r.toString();
	return out;
}


//Helper Function
void Rhombus::setForeground() {

	for (int i = 0; i <= d / 2; i++) {
		vector<bool> temp;
		for (int k = (d / 2) - i; k > 0; k--) {
			temp.push_back(false);
		}
		for (int j = 1; j <= (2 * i) + 1; j++) {
			temp.push_back(true);
		}
		for (int k = (d / 2) - i; k > 0; k--) {
			temp.push_back(false);
		}
		foreground.push_back(temp);
	}
	for (int i = 1; i <= d / 2; i++) {
		vector<bool> temp;
		for (int k = 0; k < i; k++) {
			temp.push_back(false);
		}
		for (int j = 1; j <= d - (2 * i); j++) {
			temp.push_back(true);
		}
		for (int k = 0; k < i; k++) {
			temp.push_back(false);
		}
		foreground.push_back(temp);
	}
}