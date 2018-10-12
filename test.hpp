//
// Created by Administrator on 2018-10-09.
//

#ifndef ASSIGNMENT1_TEST_HPP
#define ASSIGNMENT1_TEST_HPP


class test {
private:
    int *a;
public:
    ~test();
    test(int a);
    void printA();


    test returnTest();
    test returnTestObj(test t);
};


#endif //ASSIGNMENT1_TEST_HPP
