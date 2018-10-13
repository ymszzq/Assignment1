//
// Created by Administrator on 2018-10-10.
//

#include <vector>
#include "stochastic_matrix.hpp"
/*
 * stochastic matrix constructor
 */
stochastic_matrix::stochastic_matrix(connectivity_matrix cm) :matrix(cm.getNum_row(),cm.getNum_col()){
    vector<double> sum_col;
    for (int col = 0; col <cm.getNum_col(); ++col) {
        double sum=0;
        for (int row = 0; row <cm.getNum_row() ; ++row) {
            sum+=cm.get_value(row,col);
        }
        sum_col.push_back(sum);
    }
//add probability to all 0s column
    for (int r = 0; r < getNum_row(); ++r) {
        for (int c = 0; c < getNum_col(); ++c) {
            if(sum_col[c]!=0){
            set_value(r,c,(cm.get_value(r,c)/sum_col[c]));
            }else{
                set_value(r,c,(1.0/cm.getNum_row()));
            }
        }
    }

}
