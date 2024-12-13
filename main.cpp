// Yousef Carbon 40308658, Irmuun Uyanga 40309646

#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Hospital.h"
#include "Patient.h"

using namespace std;

int main() {
    try{
        Hospital hospital("doctors.txt", "patients.txt");

        cout << "Hospital data successfully opened" << endl;
    }catch (){
    }



    return 0;
}