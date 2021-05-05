#include "Vector.h"
#include "VectorHori.h"

void AutoTest() {
    vector<double>a(1);
    vector<double>b(1);
    a[0] = 0;
    b[0] = 1;
    VectorHori A(a, 1);
    VectorHori B(b, 1);
    VectorHori C;
    C = A + B;
    if (C.SeeVector()[0] == 1) {
        printf("Autotest passed\n");
    }
    else {
        printf("Autotest failed\n");
    }
}
