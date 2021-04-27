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

    do {
        std::cout << "Is it a full matrix? (y/n)\t";
        std::cin >> choice;
    } while (choice!='y' && choice!='n');

    if (choice=='n') {
        Matrix A(nr, nc);
        Matrix B(A);
        Matrix C(A);
        Matrix D(A);
        Matrix E(A);
        A.Print();
        Fraction det;
        std::cout << "\n\n";
        std::cout << "Norm 1 is: ";
        A.Norm1().Print();
        std::cout << "\n";
        std::cout << "Infinite norm is: ";
        A.NormInf().Print();
        std::cout << "\n";
        if (E.Determinant(det)){
            std::cout << "Determinant: ";
            det.Print();
        } else std::cout << "NO DETERMINANT!\n";
        std::cout << "\n";
        std::cout << "\nGauss:";
        if (A.Gauss()) {
            A.Print();
            std::cout << "\n";
        } else std::cout << "\tNOT APPLICABLE!\n";
        std::cout << "\nGauss with Partial Pivoting:";
        if (B.GaussPP()) {
            B.Print();
            std::cout << "\n";
        } else std::cout << "NOT APPLICABLE!\n";
        std::cout << "\nTransposed matrix:";
        C.Transpose();
        C.Print();
        std::cout << "\n";
        if (D.Inversion()) {
            std::cout << "\nInverted matrix:";
            D.Print();
            std::cout << "\n";
        } else std::cout << "\nNOT INVERTIBLE!\n";
    }
    else {
        fullMatrix A(nr, nc);
        fullMatrix B(A);
        A.Print();
        std::cout << "\n\n";
        std::cout << "Norm 1 is: ";
        A.Norm1().Print();
        std::cout << "\n";
        std::cout << "Infinite norm is: ";
        A.NormInf().Print();
        std::cout << "\n";
        std::cout << "\nGauss:";
        if (A.Gauss()) {
            A.Print();
            std::cout << "\nSolutions:\n";
            A.Back_Substitution();
        } else std::cout << "\tNOT APPLICABLE!\n";
        std::cout << "\nGauss with Partial Pivoting:";
        if (B.GaussPP()) {
            B.Print();
            std::cout << "\nSolutions:\n";
            B.Back_Substitution();
        } else std::cout << "NOT APPLICABLE!\n";
    }

    return 0;
}