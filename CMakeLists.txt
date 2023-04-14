cmake_minimum_required(VERSION 3.23)
project(_)

set(CMAKE_CXX_STANDARD 20)

add_executable(_ main.cpp
                 rare.cpp
                 usually.cpp
                 frequent.cpp
                 artefacts_randomization.cpp)
