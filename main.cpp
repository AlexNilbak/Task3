#include "Fabric.h"
#include "time.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>

class Fabric;
class FabricHori;
class FabricVert;

int main() {
    try {
        //AutoTest();
        const int n = 100000;
        double p;
        vector<double> a;
        vector<double> b;
        for (int i = 0; i < n; i++){
            a.push_back(1);
            b.push_back(1);
        }
        VectorHori A(a, n);
        VectorHori B(b, n);
        VectorHori C = A + B;
        p = A * B;
    }
    catch (exception &ex) {
        cerr << "Exception: " << ex.what() << '\n';
    }
    return 0;
}
