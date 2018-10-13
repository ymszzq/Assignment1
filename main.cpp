#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "test.hpp"
#include "connectivity_matrix.hpp"
#include "stochastic_matrix.hpp"
#include "transition_matrix.hpp"
#include <unistd.h>
#include "rank_matrix.hpp"
using namespace std;
int main() {
    const double probability =0.85;

    connectivity_matrix connectivity_matrix1("connectivity.txt");
    cout<<"generating connectivity"<<"\n";


    stochastic_matrix stochastic_matrix1(connectivity_matrix1);
    cout<<"\ngenerating stochastic ..."<<"\n";


    teleportation_matrix teleportation_matrix1(connectivity_matrix1.getNum_row());
    cout<<"\ngenerating Q ..."<<"\n";


    transition_matrix transition_matrix1(stochastic_matrix1,teleportation_matrix1,probability);
    cout<<"\ngenerating transition_matrix ..."<<"\n";


    rank_matrix rank_matrix1(connectivity_matrix1.getNum_row());
    cout<<"\ngenerating rank ...."<<"\n";



    matrix matrix_previous=transition_matrix1*rank_matrix1;
    matrix matrix_current =transition_matrix1*matrix_previous;
    while(matrix_previous!=matrix_current){// calculating
        matrix_previous=matrix_current;
        matrix_current=transition_matrix1*matrix_previous;

    }

    double sum=0;//sum of the final result
    for (int i = 0; i < matrix_previous.getNum_row(); ++i) {
        sum+=matrix_previous.get_value(i,0);
    }
    matrix matrix_one_by_one(1);
    matrix_one_by_one.set_value(0,0,1/sum);
    matrix_previous*=matrix_one_by_one;//final result with %
    cout<<"\nFinal answer:\n"<<matrix_previous;

    return 0;


}