#include <iostream>
#include <string>
#include "Doctor.h"
using namespace std;

Doctor::Doctor() : doctor_first_name(""), doctor_last_name(""), doctor_id(0), specialization(""), years_of_experience(0), base_salary(0), performance_bonus(0) {}


void Doctor::set_first_name(string first_name) {
    doctor_first_name = first_name;
}
void Doctor::set_last_name(string last_name) {
    doctor_last_name = last_name;
}
void Doctor::set_doctor_id(long int doc_id) {
    doctor_id = doc_id;
}
void Doctor::set_specialization(string specialty) {
    specialization = specialty;
}
void Doctor::set_years_experience(int years_experience) {
    years_of_experience = years_experience;
}
void Doctor::set_base_salary(double salary) {
    base_salary = salary;
}
void Doctor::set_performance_bonus(double bonus) {
    performance_bonus = bonus;
}

string Doctor::get_first_name() {
    return doctor_first_name;
}
string Doctor::get_last_name() {
    return doctor_last_name;
}
long int Doctor::get_doctor_id() {
    return doctor_id;
}
string Doctor::get_specialization() {
    return specialization;
}
int Doctor::get_years_experience() {
    return years_of_experience;
}
double Doctor::get_base_salary() {
    return base_salary;
}
double Doctor::get_performance_bonus() {
    return performance_bonus;
}

double Doctor::calculate_salary() {
    return base_salary + (base_salary * performance_bonus);
}

void Doctor::print_doctor_info() {

}