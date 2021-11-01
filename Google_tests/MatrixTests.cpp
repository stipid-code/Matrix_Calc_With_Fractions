//
// Created by Leonardo on 21/10/2021.
//

#include "gtest/gtest.h"
#include "../Matrix.h"
#include "../Matrix.cpp"
#include "../Vector.h"
#include "../Vector.cpp"

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
    ASSERT_EQ(A.normInf().num, 14);
    ASSERT_EQ(A.normInf().den, 1);
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
    ASSERT_EQ(A.norm1().num, 40);
    ASSERT_EQ(A.norm1().den, 3);
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
    ASSERT_EQ(A.normInf().num, 14);
    ASSERT_EQ(A.normInf().den, 1);
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
    ASSERT_EQ(A.norm1().num, 40);
    ASSERT_EQ(A.norm1().den, 3);
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
    ASSERT_EQ(A.condNorm1().num, 4400);
    ASSERT_EQ(A.condNorm1().den, 29);
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
    ASSERT_EQ(A.condNormInf().num, 6426);
    ASSERT_EQ(A.condNormInf().den, 29);
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