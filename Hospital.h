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
        Hospital(string doctor_file, string patient_file);

        // Destructor
        ~Hospital();

        // Methods
        const Patient *find_oldest_patient() const;
        int count_critical_patients() const;
        void doctors_by_specialization();
        const Patient* show_patient_by_id(long int id) const;
        const Doctor* show_doctor_by_id(long int doctor_id) const;
        void show_assigned_doctor(long int id);
        void show_assigned_patients(long int doctor_id);

    private:
        // Attributes
        vector<const Doctor*> *doctors;
        vector<const Patient*> *patients;
};

#endif //HOSPITAL_H