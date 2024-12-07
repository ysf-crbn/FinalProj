cmake_minimum_required(VERSION 3.29)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

configure_file(doctors.txt doctors.txt COPYONLY)
configure_file(patients.txt patients.txt COPYONLY)

add_executable(FinalProject main.cpp
        Patient.h
        Patient.cpp
        Doctor.h
        Doctor.cpp
        Hospital.h
        Hospital.cpp)
