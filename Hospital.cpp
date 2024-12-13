#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Hospital.h"
#include "Doctor.h"
#include "Patient.h"

using namespace std;

Hospital::Hospital(const string& doctor_file, const string& patient_file)
{
    doctors = new vector<Doctor*>();
    patients = new vector<Patient*>();

    try{
        ifstream dfile(doctor_file);
        if (!dfile.is_open())
            throw runtime_error("Error Opening File");

        string line;
        getline(dfile, line);
        int doctor_count = stoi(line);
        for (int i = 1; i <= doctor_count; i++) {
            getline(dfile, line);
            stringstream ss(line);
            doctors->push_back(new Doctor(ss));
        }
        dfile.close();

    }catch(runtime_error& e){
        cerr << "Doctor File Error "<< e.what() << endl;
        throw;
    }
    try{
        ifstream pfile(patient_file);
        if (!pfile.is_open())
            throw runtime_error("Error: Unable to Open Patient File.");

        string line;
        getline(pfile, line);
        int patient_count = stoi(line);
        for (int i = 1; i <= patient_count; i++) {
            getline(pfile, line);
            stringstream ss(line);
            patients->push_back(new Patient(ss));
        }
        pfile.close();
    }catch(runtime_error& e){
        cerr << "Patient File Error "<< e.what() << endl;
        throw;
    }
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
        cout << "\n---- Find Oldest Patient ----" << endl;
        oldest_patient->print_patient_info();
    } else {
        cout << "No Patients Found in the System." << endl;
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

void Hospital::doctors_by_specialty(const string& special){
    vector<string> special_doctors;
    for (const auto& doctor : *doctors){
        if (doctor->get_specialization() == special){
            special_doctors.push_back(doctor->get_first_name() + " " + doctor->get_last_name());
        }
    }
    if (special_doctors.empty()){
        cout << "No Doctors with Specialization "<< special << " Found." << endl;
    }else{
        cout << "\n---- Doctors with Specialization: " << special << " ----" << endl;
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
            cout << "\n---- Show Patient by ID: " << id <<" ----" << endl;
            patients->at(i)->print_patient_info();
        }
    }
    if(!patient_found){
        cout << "No Patient Has the Provided ID" << endl;
    }
}

void Hospital::show_doctor_by_id(long int doctor_id) const {
    bool patient_found = false;
    for (int i = 0; i < doctors->size(); i++) {
        if (doctors->at(i)->get_doctor_id() == doctor_id) {
            patient_found = true;
            cout << "\n---- Doctor with ID: " << doctor_id <<" ----" << endl;
            doctors->at(i)->print_doctor_info();
        }
    }
    if(!patient_found){
        cout << "No Doctor Has the Provided ID" << endl;
    }
}

void Hospital::show_assigned_doctor(long int id) {
    for (const auto& patient : *patients) {
        if (patient->get_id() == id) {
            for (const auto& doctor : *doctors) {
                if (doctor->get_doctor_id() == patient->get_doctor_id()) {
                    cout << "\n---- Assigned Doctor(s) for Patient ID:" << id << " ----\n"
                         << doctor->get_first_name() << " "
                         << doctor->get_last_name() << "." << endl;
                    return;
                }
            }
            cout << "No Assigned Doctor for the Patient with ID " << id << "." << endl;
            return;
        }
    }
        cout << "No Patient Found with ID " << id << "." << endl;
}

void Hospital::show_assigned_patients(long int doctor_id) {
    bool assigned_patients = false;
    cout << "\n---- Assigned Patients(s) for Doctor ID:" << doctor_id << " ----\n";
    for (const auto& patient : *patients) {
        if (patient->get_doctor_id() == doctor_id){
            assigned_patients = true;
            patient-> print_patient_info();
        }
    }
    if (!assigned_patients) {
        cout << "No Patients Assigned to Doctor ID " << doctor_id << "." << endl;
    }
}