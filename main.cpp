#include <iostream>
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
        std::cout << "Is it an augmented matrix? (y/n)\t";
        std::cin >> choice;
    } while (choice!='y' && choice!='n');

    if (choice=='n') {
        Matrix A(nr, nc);
        Matrix B(A);
        Matrix C(A);
        Matrix D(A);
        Matrix E(A);
        Matrix F(A);
        A.print();
        Fraction det;
        std::cout << "\n\n";
        std::cout << "Norm 1 is: ";
        A.norm1().print();
        std::cout << "\n";
        std::cout << "Infinite norm is: ";
        A.normInf().print();
        std::cout << "\n";
        if (E.determinant(det)){
            std::cout << "Determinant: ";
            det.print();
        } else std::cout << "NO DETERMINANT!\n";
        std::cout << "\nNorm 1 condition index: ";
        std::cout << F.condNorm1().floatify();
        std::cout << "\n";
        std::cout << "Infinite norm condition index: ";
        std::cout << F.condNormInf().floatify();
        std::cout << "\n";
        std::cout << "\nGauss:";
        if (A.gauss()) {
            A.print();
            std::cout << "\n";
        } else std::cout << "\tNOT APPLICABLE!\n";
        std::cout << "\nGauss with Partial Pivoting:";
        if (B.gaussPP()) {
            B.print();
            std::cout << "\n";
        } else std::cout << "NOT APPLICABLE!\n";
        std::cout << "\nTransposed matrix:";
        C.transpose();
        C.print();
        std::cout << "\n";
        if (D.inversion()) {
            std::cout << "\nInverted matrix:";
            D.print();
            std::cout << "\n";
        } else std::cout << "\nNOT INVERTIBLE!\n";
    }
    else {
        AugmentedMatrix A(nr, nc);
        AugmentedMatrix B(A);
        A.print();
        std::cout << "\n\n";
        std::cout << "Norm 1 is: ";
        A.norm1().print();
        std::cout << "\n";
        std::cout << "Infinite norm is: ";
        A.normInf().print();
        std::cout << "\n";
        std::cout << "Conditioning index (norm 1): ";
        A.condNorm1().print();
        std::cout << "\n";
        std::cout << "Conditioning index (norm infinite): ";
        A.condNormInf().print();
        std::cout << "\n";
        std::cout << "\nGauss:";
        if (A.gauss()) {
            A.print();
            std::cout << "\nSolutions:\n";
            A.backSubstitution();
        } else std::cout << "\tNOT APPLICABLE!\n";
        std::cout << "\nGauss with Partial Pivoting:";
        if (B.gaussPP()) {
            B.print();
            std::cout << "\nSolutions:\n";
            B.backSubstitution();
        } else std::cout << "NOT APPLICABLE!\n";
    }

    return 0;
}