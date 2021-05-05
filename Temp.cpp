#include "Temp.h"
#include "Vector.h"

class Vector;

Temp& Temp::operator=(double c) {
	if (i >= v->n) {
		v->n = i + 1;
		v->v.resize(i + 1);
	}
	v->v[i] = c;
	return*this;
}

Temp::operator double() {
	if (i >= v->n) {
		return 0;
	}
	return v->v[i];
}
