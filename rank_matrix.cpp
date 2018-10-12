//
// Created by Administrator on 2018-10-10.
//

#include "rank_matrix.hpp"

rank_matrix::rank_matrix(int n) :matrix(n,1){
    for (int i = 0; i < n; ++i) {
        set_value(i,0,1.0);
    }
}
