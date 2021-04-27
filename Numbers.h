//
// Created by leonardo on 09/04/21.
//

#ifndef MATRIX_CALC_NUMBERS_H
#define MATRIX_CALC_NUMBERS_H

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>

void Round_zero(float& a, float epsilon); // if the float number is too near to 0, a becomes 0
void Round_zero(double& a, double epsilon); // if the double number is too near to 0, a becomes 0
bool Almost_equal(double a, double b, double epsilon);

class Fraction {
public:
    Fraction(int numerator, int denominator) : num(numerator), den(denominator) {
        Simplify();
    }

    Fraction() : num(1), den(1) {}

    Fraction operator+(const Fraction& right);
    Fraction operator-(const Fraction& right);
    Fraction operator*(const Fraction& right);
    Fraction operator/(const Fraction& right);
    Fraction& operator=(const Fraction& right);
    bool operator>(const Fraction& right);
    bool operator>=(const Fraction& right);
    bool operator<(const Fraction& right);
    bool operator<=(const Fraction& right);
    bool operator==(const double& right);
    bool operator!=(const double& right);

    Fraction abs(const Fraction& input);

    void Simplify();
    void Input();

    void Print() {
        if (den > 1)
            std::cout << num << "/" << den;
        else if (den < 1){
            std::cout << -num << "/" << -den;
        }
        else std::cout << num;
    }

    void MakeFraction(std::string input); // attempts to return a fraction given a double

public:
    int num;
    int den;
};

#endif //MATRIX_CALC_NUMBERS_H