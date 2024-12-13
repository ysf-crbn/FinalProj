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

void Hospital::find_oldest_patient() const{
    const Patient* oldest_patient = nullptr;
    for (int i = 0; i < patients->size(); i++) {
        if (oldest_patient == nullptr) {
            oldest_patient = patients->at(i);
        } else if (oldest_patient->get_birth_date() > patients->at(i)->get_birth_date()) {
            oldest_patient = patients->at(i);
        }
    }
    if (oldest_patient) {
        cout << "Oldest Patient: ID: " << oldest_patient->get_id()
             << ", Name: " << oldest_patient->get_first_name() << " " << oldest_patient->get_last_name()
             << ", Birth Date: " << oldest_patient->get_birth_date() << endl;
    } else {
        cout << "No patients found in the system." << endl;
    }
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

void Hospital::doctors_by_specialization(const string& special) {
    vector<string> special_doctors;
    for (const auto &doctor : doctors){
        if (doctor->get_specialization() == special){
            special_doctors.push_back(doctor->get_first_name() + " " + doctor->get_last_name());
        }
    }
    if (special_doctors.empty()){
        cout << "No doctors with specialization "<< special << " found." << endl;
    }else{
        cout << "Doctors "<< special << " " << endl;
        for (const auto &doctor : special_doctors){
            cout << doctor << endl;
        }
    }
}

void Hospital::show_patient_by_id(long int id) const {
    bool patient_found = false;
    for (int i = 0; i < patients->size(); i++) {
        if (patients->at(i)->get_id() == id) {
            patient_found = true;
            patients->at(i)->print_patient_info();
        }
    }
    if(!patient_found){
        cout << "No patient has the provided ID" << endl;
    }
}

void Hospital::show_doctor_by_id(long int doctor_id) const {
    bool patient_found = false;
    for (int i = 0; i < doctors->size(); i++) {
        if (doctors->at(i)->get_doctor_id() == doctor_id) {
            patient_found = true;
            doctors->at(i)->print_doctor_info();
        }
    }
    if(!patient_found){
        cout << "No doctor has the provided ID" << endl;
    }
}


void Hospital::show_assigned_doctor(long int id) {
    bool found_patient = false;
    for (const auto& patient : patients) {
        if (patient->get_id() == id) {
            found_patient = true;
            for (const auto& doctor : doctors) {
                if (doctor->get_doctor_id() == patient->get_doctor_id()) {
                    cout << "The assigned doctor for patient " << id << " is \n"
                         << doctor->get_first_name() << " "
                         << doctor->get_last_name() << "." << endl;
                    return;
                }
            }
            cout << "The assigned doctor is not found for the patient with ID " << id << "." << endl;
            return;
        }
    }
    if (!found_patient) {
        cout << "No patient found with ID " << id << "." << endl;
    }
}

void Hospital::show_assigned_patients(long int doctor_id) {
    bool assigned_patients = false;
    cout << "Patients assigned to Doctor with ID " << doctor_id << ":" << endl;
    for (const auto& patient : patients) {
        if (patient->get_doctor_id() == doctor_id){
            assigned_patients = true;
            patient-> print_patient_info();
        }
    }
    if (!assigned_patients) {
        cout << "No patients assigned to Doctor ID " << doctor_id << "." << endl;
    }
}