//
// Created by Administrator on 2018-10-09.
//

#include <iostream>
#include "test.hpp"

test test::returnTest() {
    test temp = test(5);
    return temp;
}

test::test(int number)  {
    a = new int[number];
    for (int i = 0; i < number; ++i) {
        a[i]=number;
    }
}

void test::printA() {
std::cout<<a;

}

test::~test() {
    delete[] a;
}

test test::returnTestObj(test t) {
    return t;
}
