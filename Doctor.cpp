#include <iostream>
#include <string>
#include "Doctor.h"

#include <chrono>
using namespace std;

Doctor::Doctor(string first_name, string last_name, long id, string specialization, int years_experience,
        double base_salary, double performance_bonus)
        : first_name(first_name), last_name(last_name), doctor_id(id), specialization(specialization),
        years_experience(years_experience), base_salary(base_salary), performance_bonus(performance_bonus) {}

Doctor::Doctor(istream &is) {
    is >> first_name >> last_name >> doctor_id;
    is >> specialization >> years_experience;
    is >> base_salary >> performance_bonus;
}

void Doctor::set_first_name(const string &name) {
    first_name = name;
}
void Doctor::set_last_name(const string &name) {
    last_name = name;
}
void Doctor::set_doctor_id(long int id) {
    doctor_id = id;
}
void Doctor::set_specialization(const string &specialty) {
    specialization = specialty;
}
void Doctor::set_years_experience(const int years) {
    years_experience = years;
}
void Doctor::set_base_salary(const double salary) {
    base_salary = salary;
}
void Doctor::set_performance_bonus(const double bonus) {
    performance_bonus = bonus;
}

string Doctor::get_first_name() {
    return first_name;
}
string Doctor::get_last_name() {
    return last_name;
}
long int Doctor::get_doctor_id() const {
    return doctor_id;
}
string Doctor::get_specialization() {
    return specialization;
}
int Doctor::get_years_experience() const {
    return years_experience;
}
double Doctor::get_base_salary() const {
    return base_salary;
}
double Doctor::get_performance_bonus() const {
    return performance_bonus;
}

double Doctor::calculate_salary() const {
    return base_salary + base_salary * performance_bonus;
}

void Doctor::print_doctor_info() const {
    cout << "\nDoctor's name: " << first_name << " " << last_name << endl;
    cout << "Doctor's id: " << doctor_id << endl;
    cout << "Doctor's specialization: " << specialization << endl;
    cout << "Doctor has " << years_experience << " years of experience" << endl;
    cout << "Doctor has a base salary of " << base_salary << "$" << endl;
    cout << "Doctor has a performance bonus of " << performance_bonus * 100 << "%" << endl;
    cout << "Doctor has a total salary of " << calculate_salary() << "$" << endl;
}