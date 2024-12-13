#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Patient.h"

using namespace std;

class Hospital {
    public:
        // Constructor
        Hospital(const string& doctor_file, const string& patient_file);

        // Destructor
        ~Hospital();

        // Methods
        void find_oldest_patient() const;
        int count_critical_patients() const;
        void doctors_by_specialty(const string& specialty);
        void show_patient_by_id(long int id) const;
        void show_doctor_by_id(long int doctor_id) const;
        void show_assigned_doctor(long int id);
        void show_assigned_patients(long int doctor_id);

    private:
        // Attributes
        vector<Doctor*> *doctors;
        vector<Patient*> *patients;
};

#endif //HOSPITAL_H