#pragma once
#include "Vector.h"
#include "Temp.h"

class Vector;

class VectorHori : public Vector{
public:
	using Vector::operator=;
	VectorHori(){}
	~VectorHori() {}
	VectorHori(const Vector& b) : Vector(b) {}
	VectorHori(const vector<double> b, int n) : Vector(b, n) {}
	friend VectorHori operator+(const Vector& a, const Vector& b);
	friend VectorHori operator-(const Vector& a, const Vector& b);
	int output(const string FileName) override;
};

