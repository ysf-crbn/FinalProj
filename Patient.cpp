#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

Patient::Patient() : patient_first_name(""), patient_last_name(""), patient_id(0), assigned_doctor_id(0), date_of_birth(0), blood_type(""),diagnosis(""), date_of_admission(0), date_of_discharge(0) {}

void Patient::set_first_name(string first_name) {
    patient_first_name = first_name;
}
void Patient::set_last_name(string last_name) {
    patient_last_name = last_name;
}
void Patient::set_id(long int id) {
    patient_id = id;
}
void Patient::set_assigned_doctor_id(long int doctor_id) {
    assigned_doctor_id = doctor_id;
}
void Patient::set_birth_date(long int birth_date) {
    date_of_birth = birth_date;
}
void Patient::set_blood_type(string b_type) {
    blood_type = b_type;
}
void Patient::set_diagnosis(string status) {
    diagnosis = status;
}
void Patient::set_admission_date(long int admission_date) {
    date_of_admission = admission_date;
}
void Patient::set_discharge_date(long int discharge_date) {
    date_of_discharge = discharge_date;
}

string Patient::get_first_name() {
    return patient_first_name;
}
string Patient::get_last_name() {
    return patient_last_name;
}
long int Patient::get_id() {
    return patient_id;
}
long int Patient::get_doctor_id() {
    return assigned_doctor_id;
}
long int Patient::get_birth_date() {
    return date_of_birth;
}
string Patient::get_blood_type() {
    return blood_type;
}
string Patient::get_diagnosis() {
    return diagnosis;
}
long int Patient::get_admission_date() {
    return date_of_admission;
}
long int Patient::get_discharge_date() {
    return date_of_discharge;
}

bool Patient::is_discharged() {

}

string Patient::patient_status() {

}

void Patient::print_patient_info() {

}