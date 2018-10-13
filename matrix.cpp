//
// Created by Administrator on 2018-10-09.
//

#include <iomanip>
#include "matrix.hpp"
//tolerance is mini

/*
 * this is copy constructor
 * PRE: Parameters must be a matrix object
 * POST: Copies values into the new matrix
 *@param copy is reference of the matrix you want to copy
 */
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

/*
 * default constructor, set row and col to 1, and cell value to 0\
 */
matrix::matrix() :  num_row(1), num_col(1){
    container = generateMatrix(num_row,num_col);
    clear();
}
/*
 * 1 param constructor
 * PRE: Parameter must greater than 0
 * POST: Square n x n matrix initialized with 0
 * @param n is the row and col.
 */
matrix::matrix(int n) :num_row(n), num_col(n){
    if (n <= 0){
        throw invalid_argument("Parameter int must be greater than zero!");
    }
    container = generateMatrix(num_row,num_col);
    clear();
}
/*
 * PRE: Parameter must be two integers greater than 0
 * POST: r x c matrix intialized with 0
 *@param r is row of matrix
 *@param c is te col of matrix
 */
matrix::matrix(int r, int c)  :num_row(r), num_col(c){
    if (r <= 0 && c <= 0)
    {
        throw invalid_argument("Parameter int must be greater than zero!");
    }
    container = generateMatrix(num_row,num_col);
    clear();
}
/*
 * PRE: Array of doubles with a size that is a perfect square
 * POST: size x size matrix intialized with values of array
 * @param double_array is an 1d double array
 * @param size is the size of the array
 */
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
/*
 *  Clears the entire matrix to 0.0
 */
void matrix::clear() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]=0.0;
        }
    }
}
/*
 * set the value of certain cell in matrix
 * @param r row
 * @param c col
 * @param value value putting in
 */
void matrix::set_value(int r, int c, double value) {
    if (r < 0 || c < 0 || r > num_row || c > num_col)
    {
        throw invalid_argument("set Invalid row and column integers!");
    }
    container[r][c] = value;
}
/*
 * get value of certain cell(r,c)
 * @param r row
 * @param c col
 * @return the double value of the cell
 */
double matrix::get_value(int r, int c) const{
    if (r < 0 || c < 0 || r > num_row || c > num_col)
    {
        throw invalid_argument("get Invalid row and column integers!");
    }
    return container[r][c];
}

/*
 * @param r row
 * @param c col
 * @return 2d vector of r x c
 */
vector<vector<double>> matrix::generateMatrix( int r, int c) {
    vector<vector<double>> tempMatrix(r,vector<double>(c));

    return tempMatrix;
}

/*
 * output matrix
 * @param os is ostream
 * @param out_matrix is the output matrix
 * @return output stream
 */
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


/*
 * comapre two matrix
 * @param lhs is left side of ==
 * @param rhs is right side of ==
 * @return true of equal, false if not
 */
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

/*
 * comp two matrix
 * @param lhs is left side of ==
 * @param rhs is right side of ==
 * @return true if not equal, false if equal
 */
bool operator!=(const matrix &lhs, const matrix &rhs) {
    return !(lhs==rhs);
}
/*
 * pre increment matrix by one
 * @return the result matrix been added one
 */
matrix& matrix::operator++() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            ++container[i][j];
        }
    }
    return *this;
}
/*
 * post increment matrix
 * @return matrix result
 */
matrix& matrix::operator++(int) {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]++;
        }
    }
    return *this;
}
/*
 * pre decrement matrix
 * @return matrix result
 */
matrix &matrix::operator--() {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            --container[i][j];
        }
    }
    return *this;
}
/*
 * post decrement matrix
 * @return matrix result
 */
matrix &matrix::operator--(int) {
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < num_col; ++j) {
            container[i][j]--;
        }
    }
    return *this;
}
/*
 * swap two matrix reference
 */
void matrix::swap(matrix &matrix1, matrix &matrix2) {
    using std::swap;

    swap(matrix1.num_row, matrix2.num_row);
    swap(matrix1.num_col, matrix2.num_col);
    swap(matrix1.container, matrix2.container);

}
/*
 * assign matrix
 * @param rhs, assignment from
 * @return matrix get assigned
 */
matrix& matrix::operator=(matrix rhs) {
    swap(*this,rhs);
    return *this;
}
/*
 * add and assign
 * @rhs matrix on the right of +=
 * @return matrix get assigned
 */
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
/*
 * subtract and assign
 * @rhs matrix on the right of -=
 * @return matrix get assigned
 */
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
/*
 * add two matrix
 * @param lhs left side of +
 * @parm rhs right side of +
 * @return matrix result
 */
matrix operator+(matrix lhs, const matrix &rhs) {

    lhs+=rhs;
    return lhs;
}
/*
 * subtract two matrix
 * @param lhs left side of -
 * @parm rhs right side of -
 * @return matrix result
 */
matrix operator-(matrix lhs, const matrix &rhs) {
    lhs-=rhs;
    return lhs;
}
/*
 * multiply and assign
 * @pram rhs right side of *=
 * @return matrix result
 */
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
/*
 * multiply matrix
 * @param lhs left side of matrix
 * @param rhs right side of matrix
 * @return matrix result
 */
matrix operator*(matrix lhs, const matrix &rhs) {
    lhs*=rhs;
    return lhs;
}
/*
 * get num_row
 * @return  number of row
 */
int matrix::getNum_row() const {
    return num_row;
}
/*
 * get number of col
 * @reutnr number of col
 */
int matrix::getNum_col() const {
    return num_col;
}

/*
 * set number of row
 * @param number of row need to assign
 */
void matrix::setNum_row(int num_row) {
    matrix::num_row = num_row;
}
/*
 * set number of col
 * @parm number of col need to assign
 */
void matrix::setNum_col(int num_col) {
    matrix::num_col = num_col;
}








