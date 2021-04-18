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
                input.Input();
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

    virtual void Print();

    Matrix operator+(const Matrix& right);
    Matrix operator-(const Matrix& right);
    Matrix operator*(const Matrix& right);
    Matrix& operator=(const Matrix& right); // Shallow copy

    Fraction abs(int pos);

    bool isUpperTriangular(); // Checks if the matrix is upper triangular

    virtual bool Gauss();
    virtual void Transpose();
    virtual bool SwapRows(int row1, int row2);
    bool SwapColumns(int col1, int col2);
    virtual bool PartialPivoting(int firstRow, int firstCol); // optimizes the matrix for Gauss application
    virtual bool GaussPP(); // Gauss elimination method with Partial Pivoting
    bool CraftIdentity();
    bool Inversion();

    bool RowMax(int row, Fraction& result);
    bool ColMax(int col, Fraction& result);
    bool AbsRowSum(int row, Fraction& result); // returns the sum of the absolute of values in selected row
    bool AbsColSum(int col, Fraction& result); // returns the sum of the absolute of values in selected column

    Fraction Norm1();
    Fraction NormInf();

protected:
    int n_col;
    int n_row;
    Fraction* values = new Fraction[n_col*n_row];
};

class fullMatrix : public Matrix {
public:
    fullMatrix(Fraction const V[], int row_number, int col_number, Fraction const bi[]) : Matrix(V, row_number, col_number) {
        for (int i=0; i<row_number; i++)
            b[i] = bi[i];
    }

    fullMatrix(int row_number, int col_number) : Matrix(row_number, col_number){
        Fraction input;
        std::cout << "Insert known terms: \n";
        for (int i = 0; i < row_number; i++) {
            std::cout << "Insert b[" << i + 1 << "]:\t";
            input.Input();
            b[i] = input;
        }
    }

    fullMatrix(fullMatrix& that) : Matrix(that) {
        for (int i = 0; i < n_row; i++)
            b[i] = that.b[i];
    }

    ~fullMatrix() override{
        delete[] b;
    }

    void Print() override;
    bool Gauss() override;
    bool SwapRows(int row1, int row2) override;
    bool PartialPivoting(int firstRow, int firstCol) override;
    bool GaussPP() override;
    bool Back_Substitution(); // Prints the solutions of an upper triangular matrix

protected:
    Fraction* b = new Fraction[n_row];
};

#endif //MATRIX_CALC_MATRIX_H