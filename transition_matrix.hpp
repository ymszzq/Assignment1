//
// Created by Administrator on 2018-10-10.
//

#ifndef ASSIGNMENT1_TRANSITION_MATRIX_HPP
#define ASSIGNMENT1_TRANSITION_MATRIX_HPP

#include "matrix.hpp"
#include "stochastic_matrix.hpp"
#include "teleportation_matrix.hpp"

class transition_matrix :public matrix{
public:
    transition_matrix(stochastic_matrix& sm, teleportation_matrix& tm,double probability);

//    transition_matrix(const matrix &matrix);
};


#endif //ASSIGNMENT1_TRANSITION_MATRIX_HPP
