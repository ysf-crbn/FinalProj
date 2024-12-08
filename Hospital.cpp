#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Hospital.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

Hospital::Hospital(string doctor_file, string patient_file) {
    doctors = new vector<const Doctor*>();
    patients = new vector<const Patient*>();

    ifstream dfile(doctor_file);
    string line;
    getline(dfile, line);
    int doctor_count = stoi(line);
    for (int i = 1; i <= doctor_count; i++) {
        getline(dfile, line);
        stringstream ss(line);
        doctors->push_back(new Doctor(ss));
    }
    dfile.close();

    ifstream pfile(patient_file);
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
    if (doctors) {
        for (int i = 0; i < doctors->size(); i++) {
            delete doctors->at(i);
        }
        delete doctors;
    }
    if (patients) {
        for (int i = 0; i < patients->size(); i++) {
            delete patients->at(i);
        }
        delete patients;
    }
}

const Patient *Hospital::find_oldest_patient() const {
    const Patient* oldest_patient = nullptr;
    for (int i = 0; i < patients->size(); i++) {
        if (oldest_patient == nullptr) {
            oldest_patient = patients->at(i);
        } else if (oldest_patient->get_birth_date() > patients->at(i)->get_birth_date()) {
            oldest_patient = patients->at(i);
        }
    }
    return oldest_patient;
}

int Hospital::count_critical_patients() const {
    int critical_patient_count = 0;
    for (int i = 0; i < patients->size(); i++) {
        if (patients->at(i)->patient_status().compare("Critical") == 0) {
            critical_patient_count++;
        }
    }
    return critical_patient_count;
}

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