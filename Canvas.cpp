//-----------------------------------------------
/**
*	This is the implementation file for "Canvas.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------


#include "Canvas.h"

//-----------------------------------------------
/*
The default constructor of the class creates a
canvas with specified number of rows and colums and also
optionally taking a user defined character to fill the
the canvas
*/
//-----------------------------------------------
Canvas::Canvas(int rows, int cols, char fillCh) {
	vector<char> temp;
	for (int j = 0; j < cols; j++) {
		temp.push_back(fillCh);
	}
	for (int i = 0; i < rows; i++) {
		canvas.push_back(temp);
	}
}

//-----------------------------------------------
/*
This function returns the height of the canvas
*/
//-----------------------------------------------
int Canvas::getHeight() const {
	return canvas.size();
}
//-----------------------------------------------
/*
This function returns the width of the canvas
*/
//-----------------------------------------------
int Canvas::getWidth() const {
	return canvas[0].size();
}
//-----------------------------------------------
/*
This function checks whether the given row and column
number lies inside the canvas
*/
//-----------------------------------------------
bool Canvas::inBounds(int row, int col) const {
	if (row < getHeight()) {
		if (col < getWidth()) {
			return true;
		}
	}
	return false;
}

//-----------------------------------------------
/*
subscript operator overloaded (constant version)
*/
//-----------------------------------------------
const vector<char>& Canvas::operator[](int row) const{
	return canvas[row];
}
//-----------------------------------------------
/*
subscript operator overloaded (non-constant version)
*/
//-----------------------------------------------
vector<char>& Canvas::operator[](int row) {
	return canvas[row];
}
//-----------------------------------------------
/*
This function overwrites the existing character with
the given character at given row and column on canvas
*/
//-----------------------------------------------
void Canvas::put(int row, int col, char ch) {
	if (inBounds(row, col)) {
		canvas[row][col] = ch;
	}
}
//-----------------------------------------------
/*
This funtion clears the canvas.
It optionally takes in a character with which to
clear the canvas.
(by default it is a space)
*/
//-----------------------------------------------
void Canvas::clear(char ch) {
	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			canvas[i][j] = ch;
		}
	}
}
//-----------------------------------------------
/*
insertion operator overloaded to print the canvas
on the screen
*/
//-----------------------------------------------
ostream& operator<<(ostream& out, Canvas& obj) {
	for (int i = 0; i < obj.getHeight(); i++) {
		for (int j = 0; j < obj.getWidth(); j++) {
			out << obj[i][j];
		}
		out << "\n";
	}
	return out;
}