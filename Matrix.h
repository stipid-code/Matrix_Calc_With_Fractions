//
// Created by leonardo on 08/04/21.
//

#ifndef MATRIX_CALC_MATRIX_H
#define MATRIX_CALC_MATRIX_H

#include <iostream>
#include "Vector.h"
#include "Numbers.h"

class Matrix {
public:
    Matrix(Fraction const V[], int row_number, int col_number) : n_col(col_number), n_row(row_number){
        for (int i=0; i<row_number; i++){
            for (int j=0; j<col_number; j++){
                values[i * col_number + j] = V[i * col_number + j];
            }
        }
    }

    Matrix(int row_number, int col_number) : n_col(col_number), n_row(row_number){
        std::cout << "Insert values: \n";
        Fraction input;
        for (int i=0; i<row_number; i++){
            for (int j=0; j<col_number; j++){
                std::cout << "Insert [" << i << "][" << j << "]" << "\t";
                input.input();
                values[i*col_number+j] = input;
            }
        }
    }

    Matrix(int row_number, int col_number, int init_number) : n_col(col_number), n_row(row_number) {
        for (int i = 0; i < row_number; i++) {
            for (int j = 0; j < col_number; j++) {
                values[i * col_number + j].num = init_number;
                values[i * col_number + j].den = 1;
            }
        }
    }

    Matrix(const Matrix& that) : n_col(that.n_col), n_row(that.n_row) {
        for (int i = 0; i < n_row; i++)
            for (int j = 0; j < n_col; j++)
                values[i * n_col + j] = that.values[i * n_col + j];
    } // deep copy

    virtual ~Matrix(){
        delete[] values;
    }

    bool isCol(int col) const{ //checks if it's a legal column
        if (col >= 0 && col < n_col)
            return true;
        return false;
    }

    bool isRow(int row) const{ //checks if it's a legal row
        if (row >= 0 && row < n_row)
            return true;
        return false;
    }

    virtual void print() const; // Prints the matrix
    void insertValue(unsigned short int position, Fraction* F); // inserts a value at a given position

    Matrix operator+(const Matrix& right) const;
    Matrix operator-(const Matrix& right) const;
    Matrix operator*(const Matrix& right) const;
    Matrix& operator=(const Matrix& right); // Shallow copy
    bool operator==(const Matrix& right);

    Fraction abs(int pos) const; // Returns the absolute of a value of the matrix

    bool isUpperTriangular() const; // Checks if the matrix is upper triangular

    virtual bool gauss(); // Applies the gauss elimination method on the matrix
    virtual void transpose(); // Rows become columns and columns become rows
    virtual bool swapRows(int row1, int row2);
    bool swapColumns(int col1, int col2);
    virtual bool partialPivoting(int firstRow, int firstCol); // optimizes the matrix for gauss application
    virtual bool gaussPP(); // gauss elimination method with Partial Pivoting
    bool craftIdentity(); // Makes a square matrix an identity
    bool inversion(); // Inverts the matrix
    bool determinant(Fraction& det) const;

    void extractDiag(); // Deletes all values except the ones on the diagonal
    void deleteDiag(); // Deletes the values on the diagonal
    void extractUpper(); // Deletes all the values below the diagonal
    void extractLower(); // Deletes all the values above the diagonal

    bool rowMax(int row, Fraction& result) const; // Returns the maximum value of a given row
    bool colMax(int col, Fraction& result) const; // Returns the maximum value of a given column
    bool absRowSum(int row, Fraction& result) const; // Returns the sum of the absolute of values in selected row
    bool absColSum(int col, Fraction& result) const; // Returns the sum of the absolute of values in selected column

    Fraction norm1() const;
    Fraction normInf() const;
    Fraction condNorm1() const; // condition index using norm 1
    Fraction condNormInf() const; // condition index using infinite norm

protected:
    int n_col;
    int n_row;
    Fraction* values = new Fraction[n_col*n_row];
};

class AugmentedMatrix : public Matrix {
public:
    AugmentedMatrix(Fraction const V[], int row_number, int col_number, Fraction const bi[]) : Matrix(V, row_number, col_number) {
        for (int i=0; i<row_number; i++)
            b[i] = bi[i];
    }

    AugmentedMatrix(int row_number, int col_number) : Matrix(row_number, col_number){
        Fraction input;
        std::cout << "Insert known terms: \n";
        for (int i = 0; i < row_number; i++) {
            std::cout << "Insert b[" << i + 1 << "]:\t";
            input.input();
            b[i] = input;
        }
    }

    AugmentedMatrix(int row_number, int col_number, int init_number) : Matrix(row_number, col_number, init_number){
        std::cout << "Insert known terms: \n";
        for (int i = 0; i < row_number; i++) {
            Fraction F(init_number, 1);
            b[i] = F;
        }
    }

    AugmentedMatrix(AugmentedMatrix& that) : Matrix(that) {
        for (int i = 0; i < n_row; i++)
            b[i] = that.b[i];
    }

    ~AugmentedMatrix() override{
        delete[] b;
    }

    void insertKnownTerm(unsigned short int position, Fraction* F) const; // inserts a value at a given position

    bool operator==(const AugmentedMatrix& right);

    void print() const override;
    bool gauss() override;
    bool swapRows(int row1, int row2) override;
    bool partialPivoting(int firstRow, int firstCol) override;
    bool gaussPP() override;
    bool backSubstitution(); // Prints the solutions of an upper triangular matrix

protected:
    Fraction* b = new Fraction[n_row];
};

#endif //MATRIX_CALC_MATRIX_H