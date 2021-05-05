#include "VectorHori.h"
#include <chrono>
#include <omp.h>

int VectorHori::output(const string FileName){
	ofstream fout(FileName,ios_base::app);
	for (auto i = v.begin(); i != v.end(); ++i) {
		fout << *i << ' ';
	}
	fout << '\n';
	fout.close();
    return 0;
}

VectorHori operator+(const Vector& a, const Vector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else{
		vector<double>d(a.n);
		auto start = std::chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < a.n; i++){
			d[i] = a.v[i] + b[i];
		}
		auto end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
		VectorHori res(d, a.n);
		return res;
	}
}

VectorHori operator-(const Vector& a, const Vector& b) {
	if (a.n != b.n) {
		printf("Error. Incorrect length\n");
		return a;
	}
	else {
		vector<double>d(a.n);
		auto start = std::chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < a.n; i++) {
			d[i] = a.v[i] - b[i];
		}
		auto end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Subtraction operator runtime is " << elapsed_ms << " ms\n";
		VectorHori res(d, a.n);
		return res;
	}
}
