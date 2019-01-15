//-----------------------------------------------
/**
*	This is the implementation file for "Isosceles.h"
*
* @author  Mehakpreet Singh
* @version 1.0
* @since   2018-08-12
*/
//-----------------------------------------------

#include "Isosceles.h"

//-----------------------------------------------
/*
The default constructor takes parameters for name and
description of the shape object and passes it up in the
hierarchy to shape class
*/
//-----------------------------------------------
Isosceles::Isosceles(const string& description, const string& name) 
	: Shape(description, name)
{
	
}

//-----------------------------------------------
/*
This function simply calls the shape class's
toString() method
*/
//-----------------------------------------------

string Isosceles::toString() const {
	Shape::toString();
	return "";
}
