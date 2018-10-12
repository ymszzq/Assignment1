cmake_minimum_required(VERSION 3.12)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment1 main.cpp matrix.cpp matrix.hpp test.cpp test.hpp connectivity_matrix.cpp connectivity_matrix.hpp stochastic_matrix.cpp stochastic_matrix.hpp teleportation_matrix.cpp teleportation_matrix.hpp transition_matrix.cpp transition_matrix.hpp rank_matrix.cpp rank_matrix.hpp)