//
// Created by Administrator on 2018-10-10.
//

#ifndef ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP
#define ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP

#include "matrix.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "matrix.hpp"
class connectivity_matrix : public matrix{
public:
    connectivity_matrix(double array[],int size);
    connectivity_matrix(string FILE_PATH);



};


#endif //ASSIGNMENT1_CONNECTIVITY_MATRIX_HPP
