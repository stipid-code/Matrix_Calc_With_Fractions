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
#include <vector>

template <typename T>
void roundZero(T& a, T& epsilon){ // if the T number is too near to 0, a becomes 0
    if (fabs(a)<epsilon)
        a = 0;
}

template <typename T>
bool almostEqual(T& a, T& b, T& epsilon){
    T& diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    T& largest = a > b ? a : b;
    if (diff * largest < epsilon)
        return true;
    else
        return false;
}

template <typename T>
T findMax(std::vector<T> V) {
    T max = *(V.begin());
    for (auto itr : V) {
        if (itr > max)
            max = itr;
    }
    return max;
}

class Fraction {
public:
    Fraction(int numerator, int denominator) : num(numerator), den(denominator) {
        simplify();
    }

    Fraction() : num(1), den(1) {}

    int getNum() const {
        return num;
    }

    void setNum(int num) {
        Fraction::num = num;
    }

    int getDen() const {
        return den;
    }

    void setDen(int den) {
        Fraction::den = den;
    }

    Fraction operator+(const Fraction& right) const;
    Fraction operator-(const Fraction& right) const;
    Fraction operator*(const Fraction& right) const;
    Fraction operator/(const Fraction& right) const;
    Fraction& operator=(const Fraction& right);
    bool operator>(const Fraction& right) const;
    bool operator>=(const Fraction& right) const;
    bool operator<(const Fraction& right) const;
    bool operator<=(const Fraction& right) const;
    bool operator==(const Fraction& right) const;
    bool operator!=(const Fraction& right) const;
    bool operator==(const double& right) const;
    bool operator!=(const double& right) const;

    Fraction abs() const;

    void simplify();
    void input();
    std::string toString() const; // toString() replaces print() and eventually makes std::cout print the fraction
    float toFloat() const;
    void fromString(std::string const input);

    void makeFraction(std::string input); // creates a fraction given a string

private:
    int num;
    int den;
};

#endif //MATRIX_CALC_NUMBERS_H