//
// Created by Administrator on 2018-10-10.
//

#include "transition_matrix.hpp"

transition_matrix::transition_matrix(stochastic_matrix& sm, teleportation_matrix& tm, double probability): matrix(sm.getNum_row(),sm.getNum_col()) {


    for (int i = 0; i < getNum_row(); ++i) {
        for (int j = 0; j < getNum_col(); ++j) {
            double cell = (sm.get_value(i,j)*probability)+((1-probability)*tm.get_value(i,j));
            set_value(i,j,cell);
        }
    }
//    matrix matrix1= ((1-probability)*tm);


}

//transition_matrix::transition_matrix(const matrix &copy)  {
//    setNum_row(copy.getNum_row());
//    setNum_col(copy.getNum_col());
//    setContainer(generateMatrix(getNum_row(),getNum_col()));
//    for (int i = 0; i <getNum_row() ; ++i) {
//        for (int j = 0; j <getNum_col() ; ++j) {
//            set_value(i,j,copy.get_value(i,j));
//        }
//    }
//}
