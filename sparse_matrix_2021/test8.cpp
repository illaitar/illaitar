#include "SparseMatrix.hpp"
#include <iostream>

int main () {
    SparseMatrix M1(100,100);
    *(1 + *(1 -M1 + 10) + 5 - 1);
    *(1 + *(1 -(M1 - 1) + 10) + 5 - 1);
    *(1 + *(1 -M1 + 10) - 1 +5);
    *(1 + *((10 + M1) - 1) - 1 +5);
    *(1 - *((10 + M1) - 1) - 1 +5);
    const SparseMatrix M2(100,100);
    *(1 + *(1 -M2 + 10) + 5 - 1);
    *(1 + *(1 -(M2 - 1) + 10) + 5 - 1);
    *(1 + *(1 -M2 + 10) - 1 +5);
    *(1 + 2 - 3 + *(1 -M2 + 10) - 1 +5);
    *(1 + 2 - *(1 -M2 + 10) - 1 +5);
    *(1 + 2 - *((1 -M2) + 10 - 3) - 1 +5);
    *(1 + 2 - *(((1 -M2) - 2)+ 10 - 3) - 1 +5);
    *(1 + 2 - (*(((1 -M2) - 2)+ 10 - 3) - 1) +5);
    *(1 + 2 - (*(((M2 - 1) - 2)+ 10 - 3) - 1) +5);
    *(1 + *(1 +(M2 + 1)) + 5 - 1);
}
