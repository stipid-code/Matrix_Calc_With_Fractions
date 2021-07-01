//
// Created by leonardo on 09/04/21.
//

#include "Numbers.h"
#include <iostream>

void Fraction::simplify() {
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
                count = 2; // first attempt to find a divider
                found = false;
                while (count < std::abs(den) && found == false){
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
                while (count < std::abs(num) && found == false){
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

void Fraction::input() {
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
            makeFraction(first);
        }
        else {
            ss1 << first;
            ss1 >> num;
            den = 1;
        }
    }
    simplify();
}

void Fraction::print() const{
    if (den > 1)
        std::cout << num << "/" << den;
    else if (den == 1){
        std::cout << num;
    }
    else if (den == 0){
        std::cout << "nan";
    }
    else if (den < 0 && den != -1) {
        std::cout << -num << "/" << -den;
    } else {
        std::cout << -num;
    }
}

float Fraction::floatify() const {
    return (float)num/(float)den;
}

Fraction Fraction::operator+(const Fraction& right) const{
    Fraction Result;
    int new_den;
    new_den = den * right.den;
    if(den != 0 && right.den != 0) {
        Result.num = num * (new_den / den) + right.num * (new_den / right.den);
        Result.den = new_den;
    }
    Result.simplify();
    return Result;
}

Fraction Fraction::operator-(const Fraction& right) const{
    Fraction Result;
    int new_den;
    new_den = den * right.den;
    if(den != 0 && right.den != 0) {
        Result.num = num * (new_den / den) - right.num * (new_den / right.den);
        Result.den = new_den;
    }
    Result.simplify();
    return Result;
}

Fraction Fraction::operator*(const Fraction &right) const{
    Fraction Result;
    Result.num = num * right.num;
    Result.den = den * right.den;
    Result.simplify();
    return Result;
}

Fraction Fraction::operator/(const Fraction& right) const{
    Fraction Result;
    Result.num = num * right.den;
    Result.den = den * right.num;
    Result.simplify();
    return Result;
}

Fraction& Fraction::operator=(const Fraction& right){
    num = right.num;
    den = right.den;
    return *this;
}

bool Fraction::operator>(const Fraction &right) const{
    bool isMajor = false;
    if ((double)num/den > (double)right.num/right.den){
        isMajor = true;
    }
    return isMajor;
}

bool Fraction::operator>=(const Fraction &right) const{
    bool isMajor = false;
    if ((double)num/den >= (double)right.num/right.den){
        isMajor = true;
    }
    return isMajor;
}

bool Fraction::operator<(const Fraction &right) const{
    bool isMinor = false;
    if ((double)num/den < (double)right.num/right.den){
        isMinor = true;
    }
    return isMinor;
}

bool Fraction::operator<=(const Fraction &right) const{
    bool isMinor = false;
    if ((double)num/den <= (double)right.num/right.den){
        isMinor = true;
    }
    return isMinor;
}

bool Fraction::operator==(const double& right) const{
    double fraction;
    fraction = (float)num/(float)den;
    if(fraction == right)
        return true;
    else
        return false;
}

bool Fraction::operator!=(const double& right) const{
    double fraction;
    fraction = (float)num/(float)den;
    if(fraction != right)
        return true;
    else
        return false;
}

Fraction Fraction::abs() const{
    Fraction output;
    if (num<0) {
        output.num = -num;
    }
    else output.num = num;
    if (den<0) {
        output.den = -den;
    }
    else output.den = den;
    return output;
}

void Fraction::makeFraction(std::string input) {
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
        simplify();
    }
}