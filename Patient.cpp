#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient() {}
Patient::Patient(istream &is) {
    is >> first_name >> last_name >> id;
    is >> assigned_doctor_id;
    is >> birthdate >> blood_type;
    is >> diagnosis >> admission_date >> discharge_date;
}

void Patient::set_first_name(string name) {
    name = name;
}
void Patient::set_last_name(string name) {
    name = name;
}
void Patient::set_id(long int id) {
    id = id;
}
void Patient::set_assigned_doctor_id(long int id) {
    assigned_doctor_id = id;
}
void Patient::set_birth_date(long int date) {
    birthdate = date;
}
void Patient::set_blood_type(string type) {
    blood_type = type;
}
void Patient::set_diagnosis(string status) {
    diagnosis = status;
}
void Patient::set_admission_date(long int date) {
    date = date;
}
void Patient::set_discharge_date(long int date) {
    date = date;
}

string Patient::get_first_name() {
    return first_name;
}
string Patient::get_last_name() {
    return last_name;
}
long int Patient::get_id() {
    return id;
}
long int Patient::get_doctor_id() {
    return assigned_doctor_id;
}
long int Patient::get_birth_date() {
    return birthdate;
}
string Patient::get_blood_type() {
    return blood_type;
}
string Patient::get_diagnosis() {
    return diagnosis;
}
long int Patient::get_admission_date() {
    return admission_date;
}
long int Patient::get_discharge_date() {
    return discharge_date;
}

bool Patient::is_discharged() {
    if (discharge_date == -1) {
        return false;
    }
    return true;
}

string Patient::patient_status() {

}

void Patient::print_patient_info() {

}