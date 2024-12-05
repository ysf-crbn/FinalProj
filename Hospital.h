#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include <vector>
#include "Doctor.h"
#include "Patient.h"

using namespace std;

class Hospital {
    public:
        Hospital();

        void find_oldest_patient();
        int count_critical_patients();
        void doctors_by_specialization();
        void show_patient_by_id(long int id);
        void show_doctor_by_id(long int doctor_id);
        void show_assigned_doctor(long int id);
        void show_assigned_patients(long int doctor_id);

    private:
        vector<const Doctor*> doctors;
        vector<const Patient*> patients;
};


#endif //HOSPITAL_H