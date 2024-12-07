#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Hospital.h"
#include "Patient.h"

using namespace std;

int main() {
    Hospital hospital = Hospital("doctors.txt", "patients.txt");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
