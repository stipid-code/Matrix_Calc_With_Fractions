//
// Created by Leonardo on 21/10/2021.
//

#include "gtest/gtest.h"
#include "../Numbers.h"
#include "../Numbers.cpp"

TEST(Fractions, Simplifier) {
    Fraction F(2,4);
    ASSERT_EQ(F.num,1);
    ASSERT_EQ(F.den,2);

    F.num = 99;
    F.den = 36;
    F.simplify();
    ASSERT_EQ(F.num,11);
    ASSERT_EQ(F.den,4);
}

TEST(Fractions, Sum) {
    Fraction F(13,4);
    Fraction G(12,3);
    Fraction result = F + G;
    ASSERT_EQ(result.num, 29);
    ASSERT_EQ(result.den, 4);
}

TEST(Fractions, Sub) {
    Fraction F(13,4);
    Fraction G(12,3);
    Fraction result = F - G;
    ASSERT_EQ(result.num, -3);
    ASSERT_EQ(result.den, 4);
}

TEST(Fractions, Mult) {
    Fraction F(13,4);
    Fraction G(-12,3);
    Fraction result = F * G;
    ASSERT_EQ(result.num, -13);
    ASSERT_EQ(result.den, 1);
}

TEST(Fractions, Div) {
    Fraction F(13,4);
    Fraction G(-12,3);
    Fraction result = F / G;
    ASSERT_EQ(result.num, -13);
    ASSERT_EQ(result.den, 16);
}