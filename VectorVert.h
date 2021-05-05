#pragma once
#include "Vector.h"
#include "Temp.h"

class VectorVert : public Vector{
public:
	using Vector::operator=;
	VectorVert() {}
	~VectorVert() {}
	VectorVert(const Vector& b) : Vector(b) {}
	VectorVert(const vector<double> b, int n) :Vector(b, n) {}
	int output(const string FileName) override;
};

