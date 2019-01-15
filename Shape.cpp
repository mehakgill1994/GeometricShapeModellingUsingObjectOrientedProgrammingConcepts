#include "Shape.h"

int Shape::count = 0;

//-----------------------------------------------
/*
The default constructor of the class creates a
shape object with a unique id and also name and 
description for the object.
*/
//-----------------------------------------------
Shape::Shape(const string& description, const string& name) {
	count++;
	this->id = count;
	this->name = name;
	this->description = description;
}
//-----------------------------------------------
/*
This function returns the unique shape id
assigned to each shape
*/
//-----------------------------------------------
int Shape::getId() const {
	return id;
}
//-----------------------------------------------
/*
This function returns the name of the sahpe
*/
//-----------------------------------------------
string Shape::getName() const{
	return name;
}
//-----------------------------------------------
/*
This function returns the description of the sahpe
*/
//-----------------------------------------------
string Shape::getDescription() const {
	return description;
}
//-----------------------------------------------
/*
This function sets the name of the sahpe
*/
//-----------------------------------------------
void Shape::setName(const string& s) {
	this->name = s;
}
//-----------------------------------------------
/*
This function sets the description of the sahpe
*/
//-----------------------------------------------
void Shape::setDescription(const string& s) {
	this->description = s;
}

//-----------------------------------------------
/*
This function returns the string representation of
the shape object specifying its static and synamic
type.
*/
//-----------------------------------------------
string Shape::toString() const {

	cout << "Shape Information\n";
	cout << "-----------------\n";
	cout << setw(15) << left << "Static type: " << typeid(this).name() << "\n";
	cout << setw(15) << left << "Dynamic type: " << typeid(*this).name() << "\n";

	return "";
}