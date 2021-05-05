#pragma once
#include <iostream>
#include <fstream>

class Vector;

class Temp{
	Vector* v; 
	int i;
public:
	Temp(Vector* v, int i) { 
		this->v = v; 
		this->i = i; 
	}
	Temp& operator=(double c);
	operator double();
};


