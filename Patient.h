#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient {
    public:
        Patient();

        void set_first_name(string first_name);
        void set_last_name(string last_name);
        void set_id(long int id);
        void set_assigned_doctor_id(long int doctor_id);
        void set_birth_date(long int birth_date);
        void set_blood_type(string b_type);
        void set_diagnosis(string status);
        void set_admission_date(long int admission_date);
        void set_discharge_date(long int discharge_date);


        string get_first_name();
        string get_last_name();
        long int get_id();
        long int get_doctor_id();
        long int get_birth_date();
        string get_blood_type();
        string get_diagnosis();
        long int get_admission_date();
        long int get_discharge_date();

        bool is_discharged();
        string patient_status();
        void print_patient_info();

    private:
        string patient_first_name;
        string patient_last_name;
        long int patient_id;
        long int assigned_doctor_id;
        long int date_of_birth;
        string blood_type;
        string diagnosis;
        long int date_of_admission;
        long int date_of_discharge;


};

#endif //PATIENT_H