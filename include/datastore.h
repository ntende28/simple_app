#pragma once

/*Creating an interface/template for a proxy storage system to create a persistent storage 
with a csv file. This is to contain the input obtained from the user in the commandline.*/
#include "student.h"
#include "subjects.h"
#include <fstream>
#include <sqlite3.h>

// #include <memory>

class Datastore {
    private:
        Datastore() {}
        sqlite3* db;

        // Delete copy constructor and assignment operator to prevent copying
        Datastore(const Datastore&) = delete;
        Datastore& operator=(const Datastore&) = delete;

        static Datastore* instance;
    public:
        // Static method to provide access to the instance
        static Datastore* getInstance() {
            if (instance == nullptr) {
                instance = new Datastore();
            }
            return instance;
        }

        int init();

        // CRUD operations (students): create, read, update, delete
        void add_student(Student& student);
        // bool find_student(std::string student_name);
        void fetch_students(std::vector<Student>& students);
        // void update_student(std::string& student_name);
        // void delete_student(std::string& student_name);

        // CRUD operations (subjects)
        void add_subject(Subject& subject);
        void fetch_subjects(std::vector<Subject>& subjects);
};



