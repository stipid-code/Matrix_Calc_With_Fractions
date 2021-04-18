#include <iostream>
#include <sstream>

#include "Matrix.h"

int main() {
    int nr, nc;
    char choice;

    std::cout << "Insert number of rows: \t";
    do {
        std::cin >> nr;
    } while (nr < 0);
    std::cout << "Insert number of columns (without considering known terms): \t";
    do {
        std::cin >> nc;
    } while (nc < 0);

    Matrix A(nr, nc);
    Matrix B(A);
    Matrix C(A);
    Matrix D(A);
    A.Print();
    std::cout << "\n\n";
    std::cout << "Norm 1 is: ";
    A.Norm1().Print();
    std::cout << "\n";
    std::cout << "Infinite norm is: ";
    A.NormInf().Print();
    std::cout << "\n";
    std::cout << "\nGauss:";
    if(A.Gauss()) {
        A.Print();
        std::cout << "\n";
    } else std::cout << "\tNOT APPLICABLE!\n";
    std::cout << "\nGauss with Partial Pivoting:";
    if(B.GaussPP()) {
        B.Print();
        std::cout << "\n";
    } else std::cout << "NOT APPLICABLE!\n";
    std::cout << "\nTransposed matrix:";
    C.Transpose();
    C.Print();
    std::cout << "\n";
    if(D.Inversion()) {
        std::cout << "\nInverted matrix:";
        D.Print();
        std::cout << "\n";
    } else std::cout << "NOT INVERTIBLE!\n";

    return 0;
}