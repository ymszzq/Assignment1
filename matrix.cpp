//
// Created by Administrator on 2018-10-09.
//

#include <iomanip>
#include "matrix.hpp"

const double matrix::tolerance = 0.00001;

matrix::matrix(const matrix &copy) {
num_row=copy.num_row;
num_col=copy.num_col;
container = generateMatrix(num_row,num_col);
    for (int i = 0; i <num_row ; ++i) {
        for (int j = 0; j <num_col ; ++j) {
            container[i][j]=copy.container[i][j];
        }
    }
}


matrix::matrix() :  num_row(1), num_col(1){
    container = generateMatrix(num_row,num_col);
    clear();
}

matrix::matrix(int n) :num_row(n), num_col(n){
    if (n <= 0)
    {
        throw invalid_argument("Parameter int must be greater than zero!");
    }
    container = generateMatrix(num_row,num_col);
    clear();
}

matrix::matrix(int r, int c)  :num_row(r), num_col(c){
    if (r <= 0 && c <= 0)
    {
        throw invalid_argument("Parameter int must be greater than zero!");
    }
    container = generateMatrix(num_row,num_col);
    clear();
}
matrix::matrix(double double_array[], int size) {
    int root = sqrt(size);
    if ((root * root) != size)
    {
        throw invalid_argument("Length of array must be a perfect square!");
    }else{
        num_row=root;
        num_col=root;
        container=generateMatrix(num_row,num_col);
        int one_D_array_index=0;
        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                container[i][j]=double_array[one_D_array_index];
                ++one_D_array_index;
            }
        }
    }
}

matrix::~matrix() {

    container.clear();
}
void matrix::clear() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]=0.0;
        }
    }
}

void matrix::set_value(int r, int c, double value) {
    if (r < 0 || c < 0 || r > num_row || c > num_col)
    {
        throw invalid_argument("set Invalid row and column integers!");
    }
    container[r][c] = value;
}

double matrix::get_value(int r, int c) const{
    if (r < 0 || c < 0 || r > num_row || c > num_col)
    {
        throw invalid_argument("get Invalid row and column integers!");
    }
    return container[r][c];
}

void matrix::printMatrix() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            cout<<container[i][j]<<", ";
        }
            cout<<"\n";
    }
}

//double** matrix::generateMatrix( int r, int c) {
//    double **tempMatrix = new double*[r];
//    for (int i = 0; i < r; ++i) {
//        tempMatrix[i] = new double[c];
//    }
//    return tempMatrix;
//}
vector<vector<double>> matrix::generateMatrix( int r, int c) {
    vector<vector<double>> tempMatrix(r,vector<double>(c));

//    for (int i = 0; i < r; ++i) {
//        tempMatrix[i] = new vector<double>(c);
//    }
    return tempMatrix;
}

ostream &operator<<(ostream &os, matrix &out_matrix) {
    try {
        for (int row=0; row < out_matrix.num_row; row++)
        {
            for (int col=0; col < out_matrix.num_col; col++)
            {
                os << setw(10) << left
                   << out_matrix.get_value(row, col);
            }
            os << endl;
        }
    }catch(exception) {
        fprintf(stderr,"SOME EXCEPTION");
    }


    return os;
}



bool operator==(const matrix &lhs, const matrix &rhs) {
    // If matrix is the same size
    if (lhs.num_row == rhs.num_row && lhs.num_col == rhs.num_col)
    {
        for (int i = 0; i < lhs.num_row; ++i) {
            for (int j = 0; j < lhs.num_col; ++j) {
                if (abs(lhs.container[i][j] - rhs.container[i][j]) > matrix::tolerance)
                {
                    return false;
                }
            }

        }
        return true;
    }
    return false;
}


bool operator!=(const matrix &lhs, const matrix &rhs) {
    return !(lhs==rhs);
}

matrix& matrix::operator++() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            ++container[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator++(int) {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]++;
        }
    }
    return *this;
}

matrix &matrix::operator--() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            --container[i][j];
        }
    }
    return *this;
}

matrix &matrix::operator--(int) {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]--;
        }
    }
    return *this;
}

void matrix::swap(matrix &matrix1, matrix &matrix2) {
    using std::swap;

    swap(matrix1.num_row, matrix2.num_row);
    swap(matrix1.num_col, matrix2.num_col);
    swap(matrix1.container, matrix2.container);

}

matrix& matrix::operator=(matrix rhs) {
    swap(*this,rhs);
    return *this;
}

matrix& matrix::operator+=(const matrix &rhs) {
    if (num_row != rhs.num_row && num_col != rhs.num_col)
    {
        throw invalid_argument("Matrices must be of the same size!");
    }
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]+=rhs.container[i][j];
        }
    }
    return *this;
}

matrix &matrix::operator-=(const matrix &rhs) {
    if (num_row != rhs.num_row && num_col != rhs.num_col)
    {
        throw invalid_argument("Matrices must be of the same size!");
    }
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]-=rhs.container[i][j];
        }
    }
    return *this;
}

matrix operator+(matrix lhs, const matrix &rhs) {

    lhs+=rhs;
    return lhs;
}

matrix operator-(matrix lhs, const matrix &rhs) {
    lhs-=rhs;
    return lhs;
}

matrix &matrix::operator*=(const matrix &rhs) {
    if (num_col != rhs.num_row)
    {
        throw invalid_argument("The number of columns must match the number of rows!");
    }
    matrix temp{num_row,rhs.num_col};

    for (int i = 0; i < temp.num_row; ++i) {
        for (int j = 0; j < temp.num_col; ++j) {
            for (int k = 0; k < num_col; ++k) {
                double result = container[i][k]*rhs.container[k][j];
                temp.container[i][j]+=result;
//                temp.set_value(i,j,get_value(i,j)+result);
            }
        }
    }
    swap(*this,temp);
    return *this;
}

matrix operator*(matrix lhs, const matrix &rhs) {
    lhs*=rhs;
    return lhs;
}

int matrix::getNum_row() const {
    return num_row;
}

int matrix::getNum_col() const {
    return num_col;
}

//matrix &matrix::operator*=(const int &rhs) {
//    for (int i = 0; i < num_row; ++i) {
//        for (int j = 0; j < num_col; ++j) {
//            container[i][j]*=rhs;
//        }
//    }
//    return *this;
//}
//
//matrix operator*(int lhs, const matrix &rhs) {
//    matrix matrix_temp(rhs);
//    matrix_temp*=lhs;
//    return matrix_temp;
//}

void matrix::setNum_row(int num_row) {
    matrix::num_row = num_row;
}

void matrix::setNum_col(int num_col) {
    matrix::num_col = num_col;
}








