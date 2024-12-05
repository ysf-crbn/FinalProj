#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

using namespace std;

class Doctor {
    public:
        Doctor();
        Doctor(string first_name, string last_name, long int doc_id, string specialty, int years_experience, double salary, double bonus);

        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_doctor_id(long int doc_id);
        void set_specialization(string specialty);
        void set_years_experience(int years_experience);
        void set_base_salary(double salary);
        void set_performance_bonus(double bonus);

        string get_first_name();
        string get_last_name();
        long int get_doctor_id();
        string get_specialization();
        int get_years_experience();
        double get_base_salary();
        double get_performance_bonus();

        double calculate_salary();
        void print_doctor_info();

    private:
        string doctor_first_name;
        string doctor_last_name;
        long int doctor_id;
        string specialization;
        int years_of_experience;
        double base_salary;
        double performance_bonus;
};

#endif //DOCTOR_H