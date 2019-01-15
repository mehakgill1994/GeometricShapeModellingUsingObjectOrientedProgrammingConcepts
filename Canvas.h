//-----------------------------------------------
/**
*	The is the header file for canvas class.
This file describes all the functions required
for the working of canvas object.

The default constructor of the class creates a
canvas with specified height and width and also
optionally take a character with which the canvas
is initialized.
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <vector>
using namespace std;

class Canvas {
private:
	vector<vector<char>> canvas;
public:
	Canvas(int, int, char = ' ');
	const vector<char>& operator[](int) const;
	vector<char>& operator[](int);
	void put(int, int, char);
	int getHeight() const;
	int getWidth() const;
	bool inBounds(int, int) const;
	void clear(char = ' ');

	friend ostream& operator<<(ostream&, Canvas&);
};
#endif // !CANVAS_H