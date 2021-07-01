//
// Created by leonardo on 08/04/21.
//

#include "Matrix.h"

void Matrix::print() const {
    for (int i=0; i<n_row; i++){
        std::cout << "\n";
        for (int j=0; j<n_col; j++) {
            values[i * n_col + j].print();
            std::cout << "\t\t\t";
        }
    }
}

Matrix Matrix::operator+(const Matrix &right) const{
    Matrix Result(n_row, n_col, 0);
    if (n_row == n_col && n_col == right.n_col && n_row == right.n_row) {
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++)
                Result.values[i * n_col + j] = values[i * n_col + j] + right.values[i * n_col + j];
    }
    return Result;
}

Matrix Matrix::operator-(const Matrix &right) const{
    Matrix Result(n_row, n_col, 0);
    if (n_row == n_col && n_col == right.n_col && n_row == right.n_row) {
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++)
                Result.values[i * n_col + j] = values[i * n_col + j] - right.values[i * n_col + j];
    }
    return Result;
}

Matrix Matrix::operator*(const Matrix &right) const{
    Matrix Result(n_row, n_col, 0);
    if (n_row == n_col && n_col == right.n_col && n_row == right.n_row) {
        for (int i = 0; i < n_row; i++) {
            for (int k = 0; k < n_col; k++) {
                Fraction sum(0, 1);
                for (int j = 0; j < n_col; j++) {
                    sum = sum + (values[i * n_col + j] * right.values[j * n_col + k]);
                }
                Result.values[i * n_col + k] = sum;
            }
        }
    }
    return Result;
}

Matrix& Matrix::operator=(const Matrix& right) {
    for (int i=0; i<n_row; i++){
        for (int j=0; j<n_col; j++)
            values[i*n_col+j] = right.values[i*n_col+j];
    }
    return *this;
}

Fraction Matrix::abs(int pos) const {
    Fraction Result;
    Result.num = std::abs(values[pos].num);
    Result.den = std::abs(values[pos].den);
    return Result;
}

bool Matrix::isUpperTriangular() const{
    bool result = false;
    if (n_col == n_row) {
        if (values[0] == 0) // If first value is 0, it cannot be upper triangular!
            result = false;
        else result = true;
        for (int i = 1; i < n_row && result == true; i++) {
            for (int j = 0; j < i; j++)
                if (values[i * n_col + j] != 0)
                    result = false;
            if (values[i * n_col +i] == 0) // Values in the diagonal must not be equal to 0!
                result = false;
        }
    }
    return result;
}

bool Matrix::gauss() {
    bool no_error = true;
    Fraction m;
    for (int i = 0; i < (n_row-1) && no_error; i++){
        if(values[i * n_col + i].num != 0){
            for (int j = i+1; j < n_row; j++) {
                m = values[j * n_col + i]/values[i * n_col + i];
                values[j * n_col + i].num = 0;
                values[j * n_col + i].den = 1;
                for (int k = i+1; k < n_col; k++) {
                    values[j * n_col + k] = values[j * n_col + k] - m * values[i * n_col + k];
                }
            }
        }
        else
            no_error = false;
    }
    return no_error;
}

void Matrix::transpose() {
    Fraction* aux = new Fraction[n_col*n_row];
    int aux2;
    for (int i=0; i<n_row; i++){ // aux becomes the transpose matrix
        for (int j=0; j<n_col; j++){
            aux[j*n_row+i] = values[i*n_col+j];
        }
    }
    for (int i=0; i<n_row; i++){ // aux is copied in the original matrix
        for (int j=0; j<n_col; j++){
            values[i*n_col+j] = aux[i*n_col+j];
        }
    }
    aux2 = n_col;
    n_col = n_row;
    n_row = aux2;
}


bool Matrix::swapRows(int row1, int row2) {
    if (isRow(row1) && isRow(row2)){
        Fraction aux;
        for (int i = 0; i < n_col; i++) {
            aux = values[row1 * n_col + i];
            values[row1 * n_col + i] = values[row2 * n_col + i];
            values[row2 * n_col + i] = aux;
        }
        return true;
    }
    else {
        std::cout << "\nERROR: Illegal row detected for swap!\n";
        return false;
    }
}

bool Matrix::swapColumns(int col1, int col2) {
    if (isCol(col1) && isRow(col2)){
        Fraction aux;
        for (int i = 0; i < n_col; i++) {
            aux = values[i * n_col + col1];
            values[i * n_col + col1] = values[i * n_col + col2];
            values[i * n_col + col2] = aux;
        }
        return true;
    }
    else {
        std::cout << "\nERROR: Illegal column detected for swap!\n";
        return false;
    }
}

bool Matrix::partialPivoting(int firstRow, int firstCol) {
    Fraction max;
    int rowmax = firstRow;
    bool no_error = true;
    if (isRow(firstRow) && isCol(firstCol)) {
        max = values[firstRow * n_col + firstCol];

        for (int i = firstRow + 1; i < n_row; i++) {
            if (values[i * n_col + firstCol] > max) {
                max = values[i * n_col + firstCol];
                rowmax = i;
            }
        }
        if(rowmax != firstRow) {
            swapRows(firstRow, rowmax);
        }
    }
    else no_error = false;

    return no_error;
}

bool Matrix::gaussPP() {
    Fraction m;
    bool no_error = true;
    for (int i = 0; i < (n_row-1) && no_error; i++){
        partialPivoting(i, i);
        if(values[i * n_col + i] != 0){
            for (int j = i+1; j < n_row; j++) {
                m = values[j * n_col + i]/values[i * n_col + i];
                values[j * n_col + i].num = 0;
                values[j * n_col + i].den = 1;
                for (int k = i+1; k < n_col; k++) {
                    values[j * n_col + k] = values[j * n_col + k] - m * values[i * n_col + k];
                }
            }
        }
        else
            no_error = false;
    }
    return no_error;
}

bool Matrix::craftIdentity() {
    bool no_error = true;
    if (n_col == n_row) {
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++)
                if (i == j) {
                    values[i * n_col + j].num = 1;
                    values[i * n_col + j].den = 1;
                }
                else {
                    values[i * n_col + j].num = 0;
                    values[i * n_col + j].den = 1;
                }
    }
    else {
        no_error = false;
        std::cout << "\nERROR: The identity matrix cannot be crafted with dimensions " << n_row << "x" << n_col << "!\n";
    }

    return no_error;
}

bool Matrix::inversion() {
    bool no_error = true;
    bool check;
    Matrix Z(*this);
    Z.gaussPP();
    check = Z.isUpperTriangular(); // checks if the matrix can be inverted
    if (n_col == n_row && check) {
        Fraction m;
        Matrix X(n_row, n_col, 0);
        Matrix I(n_row, n_col, 0);
        I.craftIdentity();

        for (int i = 0; i < (n_row - 1) && no_error; i++) {
            if (values[i * n_col + i] != 0) {
                for (int j = i + 1; j < n_row; j++) {
                    m = values[j * n_col + i] / values[i * n_col + i];
                    values[j * n_col + i].num = 0;
                    values[j * n_col + i].den = 1;
                    for (int k = i + 1; k < n_col; k++) { // this makes the matrix triangular
                        values[j * n_col + k] = values[j * n_col + k] - (m * values[i * n_col + k]);
                    }
                    for (int k = 0; k < I.n_col; k++) { // this transforms the I matrix according to m
                        I.values[j * n_col + k] = I.values[j * n_col + k] - (m * I.values[i * n_col + k]);
                    }
                }
            } else
                no_error = false;
        }

        if (no_error) {
            Fraction sum;
            for (int k = 0; k < n_col; k++) { // initializing last row of the inverted matrix
                X.values[n_col * (n_row - 1) + k] = I.values[n_col * (n_row - 1) + k] / values[n_row * n_col - 1];
            }
            for (int c = 0; c < n_col; c++) { // loop for the columns of the inverted matrix
                for (int i = (n_row - 2); i >= 0; i--) { // loop for the rows of the initial matrix
                    sum = I.values[i * n_col + c];
                    for (int j = i + 1; j < n_col; j++) { // loop for the columns of the initial matrix
                        sum = sum - ((values[i * n_col + j] * X.values[j * n_col + c]));
                    }
                    sum = sum / values[i * n_col + i];
                    X.values[i * n_col + c] = sum;
                    X.values[i * n_col + c].simplify();
                }
            }
            *this = X;
        }
    }
    else no_error = false;
    return no_error;
}

bool Matrix::determinant(Fraction &det) const{
    bool no_error = true;
    Matrix aux(*this);
    if(aux.gaussPP()) {
        Fraction product;
        for (int i = 0; i < n_row && no_error == true; i++) {
            if (aux.values[i * n_col + i].num != 0) {
                product = product * aux.values[i * n_col + i];
            } else no_error = false;
        }
        det = product;
    } else no_error = false;
    return no_error;
}

void Matrix::extractDiag() {
    for (int i = 0; i < n_row; i++)
        for (int j = 0; j < n_row; j++) {
            if (i != j) {
                values[i * n_col + j].num = 0;
                values[i * n_col + j].den = 1;
            }
        }
}

void Matrix::deleteDiag() {
    for (int i = 0; i < n_row; i++) {
        values[i * n_col + i].num = 0;
        values[i * n_col + i].den = 1;
    }
}

void Matrix::extractUpper(){
    for (int i = 0; i < n_row; i++)
        for (int j = 0; j < n_row; j++) {
            if (i > j) {
                values[i * n_col + j].num = 0;
                values[i * n_col + j].den = 1;
            }
        }
}

void Matrix::extractLower(){
    for (int i = 0; i < n_row; i++)
        for (int j = 0; j < n_row; j++) {
            if (i < j) {
                values[i * n_col + j].num = 0;
                values[i * n_col + j].den = 1;
            }
        }
}

bool Matrix::rowMax(int row, Fraction& result) const{
    if (isRow(row)) {
        Fraction max = values[(row-1)*n_col];
        for (int i = 1; i < n_col; i++) {
            if (values[(row-1)*n_col+i]>max)
                max = values[(row-1)*n_col+i];
        }
        result = max;
        return true;
    }
    std::cout << "ERROR: Unable to return max, the inserted row doesn't exist!" << std::endl;
    return false;
}

bool Matrix::colMax(int col, Fraction& result) const{
    if (isCol(col)) {
        Fraction max = values[col];
        for (int i = 1; i < n_row; i++) {
            if (values[i*n_col+col]>max)
                max = values[i*n_col+col];
        }
        result = max;
        return true;
    }
    std::cout << "ERROR: Unable to return max, the inserted column doesn't exist!" << std::endl;
    return false;
}

bool Matrix::absRowSum(int row, Fraction& result) const{
    if(isRow(row)) {
        Fraction sum(0, 1);
        for (int i = 0; i < n_col; i++)
            sum = sum + abs(row * n_col + i);
        result = sum;
        return true;
    }
    std::cout << "ERROR: Unable to return sum, the inserted row doesn't exist!" << std::endl;
    return false;
}

bool Matrix::absColSum(int col, Fraction& result) const{
    if (isCol(col)) {
        Fraction sum(0, 1);
        for (int i = 0; i < n_row; i++)
            sum = sum + abs(i * n_col + col);
        result = sum;
        return true;
    }
    std::cout << "ERROR: Unable to return sum, the inserted column doesn't exist!" << std::endl;
    return false;
}

Fraction Matrix::norm1() const{
    Vector V_Sum(n_col);
    Fraction x;
    for (int i=0; i<n_col; i++){
        absColSum(i, x);
        V_Sum.setValue(i,x);
    }
    return V_Sum.findMax();
}

Fraction Matrix::normInf() const{
    Vector V_Sum(n_row);
    Fraction x;
    for (int i=0; i<n_row; i++){
        absRowSum(i, x);
        V_Sum.setValue(i,x);
    }
    return V_Sum.findMax();
}

Fraction Matrix::condNorm1() const{
    Matrix X(*this);
    Matrix Inv(*this);
    Inv.inversion();
    return X.norm1() * Inv.norm1();
}

Fraction Matrix::condNormInf() const{
    Matrix X(*this);
    Matrix Inv(*this);
    Inv.inversion();
    return X.normInf() * Inv.normInf();
}

// ................ FULL MATRIX: ................

void completeMatrix::print() const{
    for (int i=0; i<(n_row); i++){
        std::cout << "\n";
        for (int j=0; j<n_col; j++) {
            values[i * n_col + j].print();
            std::cout << "\t\t\t";
        }
        std::cout << "|";
        b[i].print();
    }
}

bool completeMatrix::gauss() {
    Fraction m;
    bool no_error = true;
    for (int i = 0; i < (n_row-1) && no_error; i++){
        if(values[i * n_col + i] != 0){
            for (int j = i+1; j < n_row; j++) {
                m = values[j * n_col + i]/values[i * n_col + i];
                values[j * n_col + i].num = 0;
                values[j * n_col + i].den = 1;
                for (int k = i+1; k < n_col; k++) {
                    values[j * n_col + k] = values[j * n_col + k] - m * values[i * n_col + k];
                }
                b[j] = b[j] - m*b[i];
            }
        }
        else
            no_error = false;
    }
    return no_error;
}

bool completeMatrix::gaussPP() {
    Fraction m;
    bool no_error = true;
    for (int i = 0; i < (n_row - 1) && no_error; i++) {
        partialPivoting(i, i);
        if (values[i * n_col + i] != 0) {
            for (int j = i + 1; j < n_row; j++) {
                m = values[j * n_col + i] / values[i * n_col + i];
                values[j * n_col + i].num = 0;
                values[j * n_col + i].den = 1;
                for (int k = i + 1; k < n_col; k++) {
                    values[j * n_col + k] = values[j * n_col + k] - m * values[i * n_col + k];
                }
                b[j] = b[j] - m * b[i];
            }
        } else
            no_error = false;
    }
    return no_error;
}

bool completeMatrix::swapRows(int row1, int row2) {
    if (isRow(row1) && isRow(row2)) {
        Fraction aux;
        for (int i = 0; i < n_col; i++) {
            aux = values[row1 * n_col + i];
            values[row1 * n_col + i] = values[row2 * n_col + i];
            values[row2 * n_col + i] = aux;
        }
        aux = b[row1];
        b[row1] = b[row2];
        b[row2] = aux;
        return true;
    } else {
        std::cout << "\nERROR: Illegal row detected for swap!\n";
        return false;
    }
}

bool completeMatrix::partialPivoting(int firstRow, int firstCol) {
    Fraction max;
    int rowmax = firstRow;
    bool no_error = true;
    if (isRow(firstRow) && isCol(firstCol)) {
        max = values[firstRow * n_col + firstCol];
        for (int i = firstRow + 1; i < n_row; i++) {
            if (values[i * n_col + firstCol].abs() > max.abs()) {
                max = values[i * n_col + firstCol];
                rowmax = i;
            }
        }
        if(rowmax != firstRow) {
            swapRows(firstRow, rowmax);
        }
    }
    else no_error = false;

    return no_error;
}

bool completeMatrix::backSubstitution() {
    bool no_error = true;
    Fraction* x = new Fraction[n_row];
    if (isUpperTriangular()) {
        Fraction sum;
        x[n_row-1] = b[n_row-1] / values[n_col*n_row-1];
        for (int i = (n_row-2) ; i >= 0; i--) {
            sum.num = 0;
            sum.den = 1;
            for (int j = i+1; j < n_col; j++) {
                sum = sum + values[i * n_col + j] * x[j];
            }
            x[i] = (b[i] - sum)/values[i*n_row+i];
        }
    }
    else no_error = false;

    if (no_error){
        double decimal;
        for (int k=0; k<n_row; k++) {
            std::cout << "x[" << k + 1 << "] = ";
            x[k].print();
            decimal = x[k].floatify();
            std::cout << " = " << decimal;
            std::cout << std::endl;
        }
    }
    else if (b[n_row - 1] == 0) {// if last known term is == 0 -> infinite solutions!
        std::cout << "\nERROR: Infinite solutions!\n" << std::endl;
    }
    else std::cout << "\nERROR: No solutions!\n" << std::endl;

    return no_error;
}
