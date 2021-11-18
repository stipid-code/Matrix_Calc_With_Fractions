//
// Created by Leonardo on 21/10/2021.
//

#include "gtest/gtest.h"
#include "../Matrix.h"
#include "../Matrix.cpp"

TEST(Matrix, Sum) {
    bool check = false;
    Matrix A(2,3,1);
    A.insertValue(0, new Fraction(-12, 10));
    A.insertValue(1, new Fraction(1, 3));
    A.insertValue(2, new Fraction(-1, 6));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(13, 4));
    A.insertValue(5, new Fraction(2, 1));

    Matrix B(2,3,1);
    B.insertValue(0, new Fraction(12, 10));
    B.insertValue(1, new Fraction(-1, 3));
    B.insertValue(2, new Fraction(1, 6));
    B.insertValue(3, new Fraction(-2, 1));
    B.insertValue(4, new Fraction(-13, 4));
    B.insertValue(5, new Fraction(-2, 1));

    Matrix Zero(2,3,0);
    Matrix Result = A + B;
    if (Result == Zero)
        check = true;
    ASSERT_EQ(check,true);

    Matrix C(2,3,1);
    Matrix D(3,3,1);

    ASSERT_THROW(C+D,std::invalid_argument);
}

TEST(Matrix, Subtraction) {
    bool check = false;
    Matrix A(2,3,1);
    A.insertValue(0, new Fraction(-12, 10));
    A.insertValue(1, new Fraction(1, 3));
    A.insertValue(2, new Fraction(-1, 6));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(13, 4));
    A.insertValue(5, new Fraction(2, 1));

    Matrix B(2,3,1);
    B.insertValue(0, new Fraction(-12, 10));
    B.insertValue(1, new Fraction(1, 3));
    B.insertValue(2, new Fraction(-1, 6));
    B.insertValue(3, new Fraction(2, 1));
    B.insertValue(4, new Fraction(13, 4));
    B.insertValue(5, new Fraction(2, 1));

    Matrix Zero(2,3,0);
    Matrix Result = A - B;
    if (Result == Zero)
        check = true;
    ASSERT_EQ(check,true);

    Matrix C(2,3,1);
    Matrix D(3,3,1);

    ASSERT_THROW(C-D,std::invalid_argument);
}

TEST(Matrix, Multiplication) {
    bool check = false;
    Matrix A(2,3,1);
    A.insertValue(0, new Fraction(-2, 1));
    A.insertValue(1, new Fraction(5, 2));
    A.insertValue(2, new Fraction(1, 1));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(1, 1));
    A.insertValue(5, new Fraction(-6, 5));

    Matrix B(3,2,1);
    B.insertValue(0, new Fraction(7, 1));
    B.insertValue(1, new Fraction(6, 1));
    B.insertValue(2, new Fraction(1, 1));
    B.insertValue(3, new Fraction(2, 1));
    B.insertValue(4, new Fraction(-3, 1));
    B.insertValue(5, new Fraction(-8, 3));

    Matrix Expected(2,2,0);
    Expected.insertValue(0, new Fraction(-29, 2));
    Expected.insertValue(1, new Fraction(-29, 3));
    Expected.insertValue(2, new Fraction(93, 5));
    Expected.insertValue(3, new Fraction(86, 5));

    Matrix Result = A * B;
    if (Result == Expected)
        check = true;
    ASSERT_EQ(check,true);

    Matrix C(2,3,1);
    Matrix D(2,3,1);

    ASSERT_THROW(C*D,std::invalid_argument);
}

TEST(Matrix, MakeIdentity) {
    Matrix check(3,3,1);
    check.insertValue(0, new Fraction(1,1));
    check.insertValue(1, new Fraction(0,1));
    check.insertValue(2, new Fraction(0,1));
    check.insertValue(3, new Fraction(0,1));
    check.insertValue(4, new Fraction(1,1));
    check.insertValue(5, new Fraction(0,1));
    check.insertValue(6, new Fraction(0,1));
    check.insertValue(7, new Fraction(0,1));
    check.insertValue(8, new Fraction(1,1));

    Matrix A(3,3,1);
    A.makeIdentity();
    ASSERT_EQ(A==check, true);

    Matrix B(3,4,1);
    ASSERT_THROW(B.makeIdentity(), std::invalid_argument);
}

TEST(Matrix, NormInf) {
    Matrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    Fraction normInf = A.normInf();
    ASSERT_EQ(normInf.getNum(), 14);
    ASSERT_EQ(normInf.getDen(), 1);
}

TEST(Matrix, Norm1) {
    Matrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    Fraction norm1 = A.norm1();
    ASSERT_EQ(norm1.getNum(), 40);
    ASSERT_EQ(norm1.getDen(), 3);
}

TEST(Matrix, CondNorm1) {
    Matrix A(2,2,1);
    A.insertValue(0, new Fraction(2,1));
    A.insertValue(1, new Fraction(-1,1));
    A.insertValue(2, new Fraction(3,1));
    A.insertValue(3, new Fraction(-500,1));
    Fraction condNorm1 = A.condNorm1();
    ASSERT_EQ(condNorm1.getNum(), 252003);
    ASSERT_EQ(condNorm1.getDen(), 997);
}

TEST(Matrix, CondNormInf) {
    Matrix A(2,2,1);
    A.insertValue(0, new Fraction(2,1));
    A.insertValue(1, new Fraction(-1,1));
    A.insertValue(2, new Fraction(3,1));
    A.insertValue(3, new Fraction(-500,1));
    Fraction condNormInf = A.condNormInf();
    ASSERT_EQ(condNormInf.getNum(), 252003);
    ASSERT_EQ(condNormInf.getDen(), 997);
}

TEST(Matrix, ImportExportFile) {
    bool check = false;
    Matrix Check(3, 3, 1);
    Matrix Test(3, 3, 1);
    Check.insertValue(0, new Fraction(-12, 10));
    Check.insertValue(1, new Fraction(1, 3));
    Check.insertValue(2, new Fraction(-1, 6));
    Check.insertValue(3, new Fraction(2, 1));
    Check.insertValue(4, new Fraction(4, 1));
    Check.insertValue(5, new Fraction(2, 1));
    Check.insertValue(6, new Fraction(1, 1));
    Check.insertValue(7, new Fraction(9, 1));
    Check.insertValue(8, new Fraction(4, 1));
    Check.exportFile("check.txt");
    ASSERT_EQ(Test.importFile("check.txt"), true);
    if (Test == Check)
        check = true;
    ASSERT_EQ(check, true);
}

TEST(Matrix, Inversion) {
    bool check = false;
    Matrix A(3, 3, 1);
    A.insertValue(0, new Fraction(-12, 10));
    A.insertValue(1, new Fraction(1, 3));
    A.insertValue(2, new Fraction(-1, 6));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(4, 1));
    A.insertValue(5, new Fraction(2, 1));
    A.insertValue(6, new Fraction(1, 1));
    A.insertValue(7, new Fraction(9, 1));
    A.insertValue(8, new Fraction(4, 1));
    Matrix Inv = A;
    Inv.inversion();
    Matrix Identity(3,3,0);
    Identity.makeIdentity();
    if (A*Inv == Identity)
        check = true;
    ASSERT_EQ(check, true);
}

TEST(Matrix, Determinant) {
    bool check = false;
    Matrix A(3, 3, 1);
    A.insertValue(0, new Fraction(-12, 10));
    A.insertValue(1, new Fraction(1, 3));
    A.insertValue(2, new Fraction(-1, 6));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(4, 1));
    A.insertValue(5, new Fraction(2, 1));
    A.insertValue(6, new Fraction(1, 1));
    A.insertValue(7, new Fraction(9, 1));
    A.insertValue(8, new Fraction(4, 1));
    Fraction d;
    Fraction correctDeterminant(-29, 15);
    A.determinant(d);
    if (d == correctDeterminant)
        check = true;
    ASSERT_EQ(check, true);

    A.insertValue(0, new Fraction(-12, 10));
    A.insertValue(1, new Fraction(1, 3));
    A.insertValue(2, new Fraction(-1, 6));
    A.insertValue(3, new Fraction(2, 1));
    A.insertValue(4, new Fraction(13, 4));
    A.insertValue(5, new Fraction(2, 1));
    A.insertValue(6, new Fraction(1, 1));
    A.insertValue(7, new Fraction(9, 1));
    A.insertValue(8, new Fraction(-4, 6));
    correctDeterminant.setNum(8227);
    correctDeterminant.setDen(360);
    A.determinant(d);
    if (d == correctDeterminant)
        check = true;
    ASSERT_EQ(check, true);
}

TEST(Matrix, InsertValue) {
    Matrix A(2,3,1);
    ASSERT_EQ(A.insertValue(5, new Fraction(13, 4)), true);
    ASSERT_EQ(A.insertValue(6, new Fraction(13, 4)), false); // invalid position
}

TEST(AugmentedMatrix, NormInf) {
    AugmentedMatrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    A.insertKnownTerm(0,new Fraction(3,1));
    A.insertKnownTerm(1,new Fraction(24,1));
    A.insertKnownTerm(2,new Fraction(12,1));
    ASSERT_EQ(A.normInf().getNum(), 14);
    ASSERT_EQ(A.normInf().getDen(), 1);
}

TEST(AugmentedMatrix, Norm1) {
    AugmentedMatrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    A.insertKnownTerm(0,new Fraction(3,1));
    A.insertKnownTerm(1,new Fraction(24,1));
    A.insertKnownTerm(2,new Fraction(12,1));
    ASSERT_EQ(A.norm1().getNum(), 40);
    ASSERT_EQ(A.norm1().getDen(), 3);
}

TEST(AugmentedMatrix, CondNorm1) {
    AugmentedMatrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    A.insertKnownTerm(0,new Fraction(3,1));
    A.insertKnownTerm(1,new Fraction(24,1));
    A.insertKnownTerm(2,new Fraction(12,1));
    ASSERT_EQ(A.condNorm1().getNum(), 4400);
    ASSERT_EQ(A.condNorm1().getDen(), 29);
}

TEST(AugmentedMatrix, CondNormInf) {
    AugmentedMatrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    A.insertKnownTerm(0,new Fraction(3,1));
    A.insertKnownTerm(1,new Fraction(24,1));
    A.insertKnownTerm(2,new Fraction(12,1));
    ASSERT_EQ(A.condNormInf().getNum(), 6426);
    ASSERT_EQ(A.condNormInf().getDen(), 29);
}

TEST(AugmentedMatrix, PartialPivoting) {
    AugmentedMatrix A(3,3,1);
    A.insertValue(0, new Fraction(-12,10));
    A.insertValue(1, new Fraction(1,3));
    A.insertValue(2, new Fraction(-1,6));
    A.insertValue(3, new Fraction(2,1));
    A.insertValue(4, new Fraction(4,1));
    A.insertValue(5, new Fraction(2,1));
    A.insertValue(6, new Fraction(1,1));
    A.insertValue(7, new Fraction(9,1));
    A.insertValue(8, new Fraction(4,1));
    A.insertKnownTerm(0,new Fraction(3,1));
    A.insertKnownTerm(1,new Fraction(24,1));
    A.insertKnownTerm(2,new Fraction(12,1));
    A.gaussPP();

    AugmentedMatrix B(3,3,1);
    B.insertValue(0, new Fraction(2,1));
    B.insertValue(1, new Fraction(4,1));
    B.insertValue(2, new Fraction(2,1));
    B.insertValue(3, new Fraction(0,1));
    B.insertValue(4, new Fraction(7,1));
    B.insertValue(5, new Fraction(3,1));
    B.insertValue(6, new Fraction(0,1));
    B.insertValue(7, new Fraction(0,1));
    B.insertValue(8, new Fraction(-29,210));
    B.insertKnownTerm(0,new Fraction(24,1));
    B.insertKnownTerm(1,new Fraction(0,1));
    B.insertKnownTerm(2,new Fraction(87,5));

    bool check = false;
    if (A == B) {
        check = true;
    }
    ASSERT_EQ(check, true);

}

TEST(AugmentedMatrix, ImportExportFile) {
    bool check = false;
    AugmentedMatrix Check(6, 4, 1);
    AugmentedMatrix Test(6, 4, 1);
    Check.insertValue(0, new Fraction(-12, 10));
    Check.insertValue(1, new Fraction(1, 3));
    Check.insertValue(2, new Fraction(-1, 6));
    Check.insertValue(3, new Fraction(2, 1));
    Check.insertValue(4, new Fraction(4, 1));
    Check.insertValue(5, new Fraction(2, 1));
    Check.insertValue(6, new Fraction(1, 1));
    Check.insertValue(7, new Fraction(9, 1));
    Check.insertValue(8, new Fraction(4, 1));
    Check.insertValue(9, new Fraction(6, 5));
    Check.insertValue(10, new Fraction(-4, 1));
    Check.insertValue(11, new Fraction(4, 1));
    Check.insertValue(12, new Fraction(4, 1));
    Check.insertValue(13, new Fraction(4, 1));
    Check.insertValue(14, new Fraction(-12, 10));
    Check.insertValue(15, new Fraction(1, 3));
    Check.insertValue(16, new Fraction(-1, 6));
    Check.insertValue(17, new Fraction(2, 1));
    Check.insertValue(18, new Fraction(4, 1));
    Check.insertValue(19, new Fraction(2, 1));
    Check.insertValue(20, new Fraction(1, 1));
    Check.insertValue(21, new Fraction(9, 1));
    Check.insertValue(22, new Fraction(4, 1));
    Check.insertValue(23, new Fraction(4, 1));
    Check.insertKnownTerm(0,new Fraction(3,1));
    Check.insertKnownTerm(1,new Fraction(24,1));
    Check.insertKnownTerm(2,new Fraction(12,1));
    Check.insertKnownTerm(3,new Fraction(3,1));
    Check.insertKnownTerm(4,new Fraction(24,1));
    Check.insertKnownTerm(5,new Fraction(12,1));
    Check.exportFile("check.txt");
    ASSERT_EQ(Test.importFile("check.txt"), true);
    if (Test == Check)
        check = true;
    ASSERT_EQ(check, true);
}