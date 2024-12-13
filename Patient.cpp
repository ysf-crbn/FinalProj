#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient(string first_name, string last_name, long id, long assigned_doctor_id, int birthdate,
                string blood_type, string diagnosis, long admission_date, long discharge_date)
                : first_name(first_name), last_name(last_name), id(id), assigned_doctor_id(assigned_doctor_id),
                birthdate(birthdate), blood_type(blood_type), diagnosis(diagnosis),admission_date(admission_date),
                discharge_date(discharge_date) {}

Patient::Patient(istream &is) {
    is >> first_name >> last_name >> id;
    is >> assigned_doctor_id;
    is >> birthdate >> blood_type;
    is >> diagnosis >> admission_date >> discharge_date;
}


void Patient::set_first_name(const string &name) {
    first_name = name;
}
void Patient::set_last_name(const string &name) {
    last_name = name;
}
void Patient::set_id(const long int id) {
    this->id = id;
}
void Patient::set_assigned_doctor_id(const long int id) {
    assigned_doctor_id = id;
}
void Patient::set_birth_date(const long int date) {
    birthdate = date;
}
void Patient::set_blood_type(const string &type) {
    blood_type = type;
}
void Patient::set_diagnosis(const string &status) {
    diagnosis = status;
}
void Patient::set_admission_date(const long int date) {
    admission_date = date;
}
void Patient::set_discharge_date(const long int date) {
    discharge_date = date;
}

string Patient::get_first_name() const {
    return first_name;
}
string Patient::get_last_name() const{
    return last_name;
}
long int Patient::get_id() const {
    return id;
}
long int Patient::get_doctor_id() const {
    return assigned_doctor_id;
}
long int Patient::get_birth_date() const {
    return birthdate;
}
string Patient::get_blood_type() {
    return blood_type;
}
string Patient::get_diagnosis() {
    return diagnosis;
}
long int Patient::get_admission_date() const {
    return admission_date;
}
long int Patient::get_discharge_date() const {
    return discharge_date;
}

bool Patient::is_discharged() const {
    if (discharge_date == -1) {
        return false;
    }
    return true;
}

string Patient::patient_status() const {
    if(diagnosis.find("Critical") != string::npos || diagnosis.find("critical") != string::npos) {
        return "Critical";
    }
    if (diagnosis.find("Moderate") != string::npos || diagnosis.find("moderate") != string::npos) {
        return "Moderate";
    }
    return "Stable";
}

void Patient::print_patient_info() const {
    cout << "\nPatient name: " << first_name << " " << last_name << endl;
    cout << "Patient id: " << id << endl;
    cout << "Patient's assigned doctor's id: ";
    if (assigned_doctor_id == -1) {
        cout << "No doctor has been assigned to this patient" << endl;
    } else {
        cout << assigned_doctor_id << endl;
    }
    cout << "Patient's birth date: " << birthdate << endl;
    cout << "Patient's blood type: " << blood_type << endl;
    cout << "Patient's diagnosis: " << diagnosis << endl;
    cout << "Patient admitted on: " << admission_date << endl;
    cout << "Patient discharged on: ";
    if (!is_discharged()) {
        cout << "This patient has not been discharged yet" << endl;
    } else {
        cout << discharge_date << endl;
    }
    cout << "Patient's status: " << patient_status() << endl;
}