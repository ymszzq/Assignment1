//
// Created by Administrator on 2018-10-10.
//

#include "teleportation_matrix.hpp"

teleportation_matrix::teleportation_matrix(int n) : matrix(n) {
    for (int r = 0; r < getNum_row(); ++r) {
        for (int c = 0; c < getNum_col(); ++c) {
            set_value(r,c,1.0/getNum_row());
        }
    }
}
