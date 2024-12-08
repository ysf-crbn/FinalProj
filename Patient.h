#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {
    public:
        // Constructors
        Patient();
        Patient(istream &is);

        // Setters
        void set_first_name(const string &name);
        void set_last_name(const string &name);
        void set_id(long int id);
        void set_assigned_doctor_id(long int id);
        void set_birth_date(long int date);
        void set_blood_type(const string &type);
        void set_diagnosis(const string &status);
        void set_admission_date(long int date);
        void set_discharge_date(long int date);

        // Getters
        string get_first_name();
        string get_last_name();
        long int get_id() const;
        long int get_doctor_id() const;
        long int get_birth_date() const;
        string get_blood_type();
        string get_diagnosis();
        long int get_admission_date() const;
        long int get_discharge_date() const;

        // Methods
        bool is_discharged() const;
        string patient_status() const;
        void print_patient_info() const;

    private:
        // Attributes
        string first_name;
        string last_name;
        long int id;
        long int assigned_doctor_id;
        long int birthdate;
        string blood_type;
        string diagnosis;
        long int admission_date;
        long int discharge_date;
};

#endif //PATIENT_H