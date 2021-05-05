#include "Vector.h"
#include "Temp.h"
#include <chrono>
#include <omp.h>

class Temp;

void Vector::Clean(){ 
	SetZero(); 
}
void Vector::SetZero(){ 
	v.clear(); n = 0; 
}

Vector::Vector(const Vector& b){ 
	CopyOnly(b); 
}

Vector& Vector::operator=(const Vector& b){
	if (this != &b){
		Clean(); 
		CopyOnly(b);
	}
	return *this;
}

Vector::Vector(const vector < double> b, int n){
	this->n = n;
	v = b;
}

void Vector::CopyOnly(const Vector& b){
	n = b.n;
	v = b.v;
}

void Vector::print(){
	for (auto i = v.begin(); i != v.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

int Vector::length()const{ 
	return n; 
}

vector<double> Vector::SeeVector()const{ 
	return v; 
}


const double& Vector::operator[](int i) const{
	return v[i];
}

double Vector::operator*(const Vector& b){
	if (n != b.n) {
		printf("Error. Incorrect length\n");
		return 0;
	}
	else {
		double res=0;
		double tmp = 0;
		const int N = n;
		auto start = std::chrono::system_clock::now();
#pragma omp parallel shared(res) private(tmp)
{
#pragma omp for reduction(+:res)
		for (int i = 0; i < N; i++) {
			tmp = v[i] * b[i];
			res += tmp;
		}
}
		auto end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Mult operator runtime is " << elapsed_ms << " ms\n";
		return res;
	}
}

Temp Vector::operator[](int i) {
	return Temp(this, i);
}
