//
// Created by Administrator on 2018-10-10.
//

#include <vector>
#include "connectivity_matrix.hpp"
/*
 * connectivity_matrix with sigle array and size
 * @param double_array is double array store element
 * @pram size is the size of the array
 */

connectivity_matrix::connectivity_matrix(double *double_array,int size) : matrix(double_array,size) {
    for (int i{0}; i < sizeof(double_array); ++i)
    {
        if (double_array[i] == 0
            || double_array[i] ==1)
        {}
        else
        {
            throw invalid_argument("Connectivity Matrix must contain 0's and 1's only!");
        }
    }
}
/*
 * connectivity_matrix constructor with file path
 */
connectivity_matrix::connectivity_matrix(string FILE_PATH) {
    ifstream ifs(FILE_PATH);
    vector<double> double_array;
    double value;
    while(ifs>>value){
        double_array.push_back(value);
    }
    connectivity_matrix connectivity_matrix_temp(double_array.data(),double_array.size());
    *this=connectivity_matrix_temp;

}


