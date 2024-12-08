#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>

using namespace std;

class Doctor {
    public:
        // Constructors
        Doctor();
        Doctor(istream &is);

        // Setters
        void set_first_name(const string &name);
        void set_last_name(const string &name);
        void set_doctor_id(long int id);
        void set_specialization(const string &specialty);
        void set_years_experience(int years);
        void set_base_salary(double salary);
        void set_performance_bonus(double bonus);

        // Getters
        string get_first_name();
        string get_last_name();
        long int get_doctor_id() const;
        string get_specialization();
        int get_years_experience() const;
        double get_base_salary() const;
        double get_performance_bonus() const;

        // Methods
        double calculate_salary() const;
        void print_doctor_info() const;

    private:
        // Attributes
        string first_name;
        string last_name;
        long int doctor_id;
        string specialization;
        int years_experience;
        double base_salary;
        double performance_bonus;
};

#endif //DOCTOR_H