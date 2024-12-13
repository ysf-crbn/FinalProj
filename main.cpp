// Yousef Carbon 40308658, Irmuun Uyanga 40309646

#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Hospital.h"
#include "Patient.h"

using namespace std;

int main() {
    Hospital hospital("doctors.txt", "patients.txt");

    //Testing Hospital class member functions

    hospital.find_oldest_patient();

    int critical_patients = hospital.count_critical_patients();
    cout << "\n Number of critical patients: " << critical_patients << endl;

    hospital.doctors_by_specialty("Cardiologist");

    hospital.show_patient_by_id(11111111);

    hospital.show_doctor_by_id(12345678);

    hospital.show_assigned_doctor(11111111);

    hospital.show_assigned_patients(12345678);

    //Create new doctors and patients
    Doctor new_doctor("Boe", "Jiden", 66666666,
        "Neurologist", 10, 120000, 0.1);
    new_doctor.print_doctor_info();

    Patient new_patient("Ronald", "Drump", 99999999, 66666666,
        19450305, "O-" , "Dementia", 19990213, -1);
    new_patient.print_patient_info();


    return 0;
}