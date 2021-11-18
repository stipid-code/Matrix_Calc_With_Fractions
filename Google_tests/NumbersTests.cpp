//
// Created by Leonardo on 21/10/2021.
//

#include "gtest/gtest.h"
#include "../Numbers.h"
#include "../Numbers.cpp"

TEST(Fractions, Simplifier) {
    Fraction F(2,4);
    ASSERT_EQ(F.getNum(),1);
    ASSERT_EQ(F.getDen(),2);

    F.setNum(99);
    F.setDen(36);
    F.simplify();
    ASSERT_EQ(F.getNum(),11);
    ASSERT_EQ(F.getDen(),4);
}

TEST(Fractions, Sum) {
    Fraction F(13,4);
    Fraction G(12,3);
    Fraction result = F + G;
    ASSERT_EQ(result.getNum(), 29);
    ASSERT_EQ(result.getDen(), 4);
}

TEST(Fractions, Sub) {
    Fraction F(13,4);
    Fraction G(12,3);
    Fraction result = F - G;
    ASSERT_EQ(result.getNum(), -3);
    ASSERT_EQ(result.getDen(), 4);
}

TEST(Fractions, Mult) {
    Fraction F(13,4);
    Fraction G(-12,3);
    Fraction result = F * G;
    ASSERT_EQ(result.getNum(), -13);
    ASSERT_EQ(result.getDen(), 1);
}

TEST(Fractions, Div) {
    Fraction F(13,4);
    Fraction G(-12,3);
    Fraction result = F / G;
    ASSERT_EQ(result.getNum(), -13);
    ASSERT_EQ(result.getDen(), 16);
}