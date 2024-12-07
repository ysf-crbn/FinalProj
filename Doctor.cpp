#include <iostream>
#include <string>
#include "Doctor.h"

#include <__chrono/year.h>
using namespace std;

Doctor::Doctor() {}
Doctor::Doctor(istream &is) {
    is >> first_name >> last_name >> doctor_id;
    is >> specialization >> years_experience;
    is >> base_salary >> performance_bonus;
}

void Doctor::set_first_name(string name) {
    name = name;
}
void Doctor::set_last_name(string name) {
    name = name;
}
void Doctor::set_doctor_id(long int id) {
    doctor_id = id;
}
void Doctor::set_specialization(string specialty) {
    specialization = specialty;
}
void Doctor::set_years_experience(int years) {
    years = years;
}
void Doctor::set_base_salary(double salary) {
    base_salary = salary;
}
void Doctor::set_performance_bonus(double bonus) {
    performance_bonus = bonus;
}

string Doctor::get_first_name() {
    return first_name;
}
string Doctor::get_last_name() {
    return last_name;
}
long int Doctor::get_doctor_id() {
    return doctor_id;
}
string Doctor::get_specialization() {
    return specialization;
}
int Doctor::get_years_experience() {
    return years_experience;
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