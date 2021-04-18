//
// Created by leonardo on 08/04/21.
//

#include "Vector.h"

void Vector::Print(){
    for (int i=0; i<size; i++){
        values[i].Print();
    }
    std::cout << std::endl;
}

Fraction Vector::findMax() {
    Fraction max = values[0];
    for (int i=1; i<size; i++) {
        if (values[i] > max)
            max = values[i];
    }
    return max;
}

