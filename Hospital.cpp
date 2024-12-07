#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Hospital.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

Hospital::Hospital() {
    doctors = new vector<const Doctor*>();
    patients = new vector<const Patient*>();

    ifstream dfile("doctors.txt");
    string line;
    getline(dfile, line);
    int doctor_count = stoi(line);
    for (int i = 1; i <= doctor_count; i++) {
        getline(dfile, line);
        stringstream ss(line);
        doctors->push_back(new Doctor(ss));
    }
    dfile.close();

    ifstream pfile("patients.txt");
    getline(pfile, line);
    int patient_count = stoi(line);
    for (int i = 1; i <= patient_count; i++) {
        getline(pfile, line);
        stringstream ss(line);
        patients->push_back(new Patient(ss));
    }
    pfile.close();
}

Hospital::~Hospital() {

}

void Hospital::find_oldest_patient() {

}
//int Hospital::count_critical_patients() {}
void Hospital::doctors_by_specialization() {

}
void Hospital::show_patient_by_id(long int id) {

}
void Hospital::show_doctor_by_id(long int doctor_id) {

}
void Hospital::show_assigned_doctor(long int id) {

}
void Hospital::show_assigned_patients(long int doctor_id) {

}