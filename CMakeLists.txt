cmake_minimum_required(VERSION 3.29)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FinalProject main.cpp
        Patient.h
        Patient.cpp
        Doctor.h
        Doctor.cpp
        Hospital.h
        Hospital.cpp)
