//
// Created by leonardo on 09/04/21.
//

#include "Numbers.h"
#include <iostream>
const double epsilon = 0.000001;

void Round_zero(float& a, float epsilon){
    if (fabs(a)<epsilon)
        a = 0;
}

void Round_zero(double& a, double epsilon){
    if (fabs(a)<epsilon)
        a = 0;
}

bool Almost_equal(double a, double b, double epsilon){
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double largest = a > b ? a : b;
    if (diff * largest < epsilon)
        return true;
    else
        return false;
}

void Fraction::Simplify() {
    if (num != 0 && den % num == 0){
        den = den/num;
        num = 1;
    }
    else if (num % den == 0){
        num = num/den;
        den = 1;
    }

    int count, div;
    bool found;
    if (den != 1 && num != 1) {
        do {
            if (std::abs(num) > std::abs(den)) {
                count = 2;
                found = false;
                while (count < den && found == false){
                    if (num % count == 0 && den % count == 0) {
                        div = count;
                        found = true;
                    }
                    count++;
                }
                if (found == true) {
                    num = num / div;
                    den = den / div;
                }
            } else {
                count = 2;
                found = false;
                while (count < num && found == false){
                    if (num % count == 0 && den % count == 0) {
                        div = count;
                        found = true;
                    }
                    count++;
                }
                if (found == true) {
                    num = num / div;
                    den = den / div;
                }
            }
        } while (found == true);
    }
}

void Fraction::Input() {
    bool isFloat = false;
    std::cout << "Insert num/den (int) or num (int or float): ";
    std::string input;
    std::string first, second;
    std::stringstream ss1, ss2;
    std::cin >> input;
    int j = 0;
    while (input[j] != '/' && j != input.length()){
        j++;
    }

    if (j != input.length()) {
        for (int i = 0; i < j; i++){
            first += input[i];
        }
        for (int k = j+1; k < input.length(); k++){
            if (input[k] != ' '){
                second += input[k];
            }
        }
        ss1 << second;
        ss1 >> den;
        ss2 << first;
        ss2 >> num;
    }
    else {
        for (int i = 0; i < input.length(); i++){
            first += input[i];
            if (isFloat == false && input[i] == '.')
                isFloat = true;
        }
        if (isFloat) {
            MakeFraction(first);
        }
        else {
            ss1 << first;
            ss1 >> num;
            den = 1;
        }
    }
    Simplify();
}

Fraction Fraction::operator+(const Fraction& right) {
    Fraction Result;
    int new_den;
    new_den = den * right.den;
    if(den != 0 && right.den != 0) {
        Result.num = num * (new_den / den) + right.num * (new_den / right.den);
        Result.den = new_den;
    }
    Result.Simplify();
    return Result;
}

Fraction Fraction::operator-(const Fraction& right) {
    Fraction Result;
    int new_den;
    new_den = den * right.den;
    if(den != 0 && right.den != 0) {
        Result.num = num * (new_den / den) - right.num * (new_den / right.den);
        Result.den = new_den;
    }
    Result.Simplify();
    return Result;
}

Fraction Fraction::operator*(const Fraction &right) {
    Fraction Result;
    Result.num = num * right.num;
    Result.den = den * right.den;
    Result.Simplify();
    return Result;
}

Fraction Fraction::operator/(const Fraction& right) {
    Fraction Result;
    Result.num = num * right.den;
    Result.den = den * right.num;
    Result.Simplify();
    return Result;
}

Fraction& Fraction::operator=(const Fraction& right) {
    num = right.num;
    den = right.den;
    return *this;
}

bool Fraction::operator>(const Fraction &right) {
    bool isMajor = false;
    if ((double)num/den > (double)right.num/right.den){
        isMajor = true;
    }
    return isMajor;
}

bool Fraction::operator>=(const Fraction &right) {
    bool isMajor = false;
    if ((double)num/den >= (double)right.num/right.den){
        isMajor = true;
    }
    return isMajor;
}

bool Fraction::operator<(const Fraction &right) {
    bool isMinor = false;
    if ((double)num/den < (double)right.num/right.den){
        isMinor = true;
    }
    return isMinor;
}

bool Fraction::operator<=(const Fraction &right) {
    bool isMinor = false;
    if ((double)num/den <= (double)right.num/right.den){
        isMinor = true;
    }
    return isMinor;
}

bool Fraction::operator==(const double& right) {
    double fraction;
    fraction = (float)num/den;
    if(fraction == right)
        return true;
    else
        return false;
}

bool Fraction::operator!=(const double& right) {
    double fraction;
    fraction = (float)num/den;
    if(fraction != right)
        return true;
    else
        return false;
}

Fraction Fraction::abs(const Fraction& input) {
    Fraction output;
    output.num = std::abs(num);
    output.den = std::abs(den);
    return output;
}

void Fraction::MakeFraction(std::string input) {
    std::string s_num;
    std::string s_den;
    bool dot_found = false;
    int pos_dot = -1;

    for (int i = 0; i < input.length() && dot_found== false; i++) {
        if (input[i] == '.') {
            dot_found = true;
        }
        pos_dot++;
    }

    if (dot_found) {
        s_den = '1';
        for (int k = 0; k < pos_dot; k++) {
            s_num += input[k];
        }
        for (int i = pos_dot+1; i < input.length(); i++) {
            s_num += input[i];
            s_den += '0';
        }
        num = std::stoi(s_num);
        den = std::stoi(s_den);
        Simplify();
    }
}