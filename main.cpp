#include <iostream>
#include "Matrix.h"

int main() {
    char choice, augmented;

    do {
        std::cout << "Do you want to import from file? (y/n)";
        std::cin >> choice;
    } while (choice!='y' && choice!='n');

    if (choice=='y') {
        do {
            std::cout << "Is it an augmented matrix? (y/n)";
            std::cin >> augmented;
        } while (augmented!='y' && augmented!='n');
        if (augmented=='y') {
            std::string fileName;
            AugmentedMatrix test(1, 1, 1);
            do {
                std::cout << "\n\nInsert file name:";
                std::cin >> fileName;
            } while (!test.importFile(fileName));
            test.print();
            std::cout << std::endl;
            test.exportFile("out.txt");
        } else {
            std::string fileName;
            Matrix test(1, 1, 1);
            do {
                std::cout << "\n\nInsert file name:";
                std::cin >> fileName;
            } while (!test.importFile(fileName));
            test.print();
            std::cout << std::endl;
            test.exportFile("out.txt");
        }

    } else {

        int nr, nc;

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
        } while (choice != 'y' && choice != 'n');

        if (choice == 'n') {
            Matrix A(nr, nc);
            Matrix B(A);
            Matrix C(A);
            Matrix D(A);
            Matrix E(A);
            Matrix F(A);
            A.print();
            A.exportFile("input.txt");
            Fraction det;
            std::cout << "\n\n";
            std::cout << "Norm 1 is: ";
            A.norm1().print();
            std::cout << "\n";
            std::cout << "Infinite norm is: ";
            A.normInf().print();
            std::cout << "\n";
            if (E.determinant(det)) {
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
            B.exportFile("gaussPP.txt");
        } else {
            AugmentedMatrix A(nr, nc);
            AugmentedMatrix B(A);
            A.print();
            A.exportFile("input.txt");
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
            B.exportFile("gaussPP.txt");
        }

    }
    return 0;
}