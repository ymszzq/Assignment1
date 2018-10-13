//
// Created by Administrator on 2018-10-09.
//

#ifndef ASSIGNMENT1_MATRIX_HPP

#define ASSIGNMENT1_MATRIX_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>


using namespace std;

class matrix{
private:
//    double ** container;
    vector<vector<double>> container;
public:
    void setContainer(double **container);
    static constexpr double tolerance = 0.00001;
private:
    int num_row;
    int num_col;
public:
    void setNum_col(int num_col);
    void setNum_row(int num_row);
    int getNum_col() const;
    int getNum_row() const;

    matrix(const matrix& copy);
    matrix();//init 1x1 matrix with 0.0
    matrix(int n);//n x n with 0.0, exception <=0
    matrix(int r, int c);// r x c, with 0s, exception <=0
    matrix(double intArray[],int size);// exception size is not n^2
    ~matrix();
//    double** generateMatrix(int r, int c);
    vector<vector<double>> generateMatrix(int r, int c);
    void set_value(int r, int c,double value);//exception <=0 or too large
    double get_value(int r,int c) const;//exception <=0 , or too large
    void clear();// sets all values in the matrix to 0.0
    void printMatrix();
    friend ostream & operator << (ostream &os, matrix & out_matrix);
    friend bool operator != (const matrix& lhs, const matrix & rhs);
    friend bool operator == (const matrix& lhs, const matrix & rhs);
    matrix& operator ++ ();
    matrix& operator ++ (int);
    matrix& operator -- ();
    matrix& operator -- (int);
    matrix& operator =(matrix rhs);
    void swap(matrix& matrix1,matrix& matrix2);
    matrix& operator +=(const matrix& rhs);
    matrix& operator -=(const matrix& rhs);
    friend matrix operator +(matrix lhs, const matrix& rhs);
    friend matrix operator -(matrix lhs, const matrix& rhs);
    matrix& operator *=(const matrix& rhs);
    friend matrix operator * (matrix lhs, const matrix& rhs);
//    matrix& operator *=(const int& rhs);
//    friend matrix operator * (int lhs, const matrix& rhs);

};


#endif //ASSIGNMENT1_MATRIX_HPP
