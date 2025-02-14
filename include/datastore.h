#pragma once

/*Creating an interface/template for a proxy storage system to create a persistent storage 
with a csv file. This is to contain the input obtained from the user in the commandline.*/
#include "student.h"
#include <fstream>
#include <vector>

class Datastore {
    private:
        std::vector<Student> students;
        Datastore() {
            std::cout << "New datastore created\n";
        }

        // Delete copy constructor and assignment operator to prevent copying
        Datastore(const Datastore&) = delete;
        Datastore& operator=(const Datastore&) = delete;

        // Static pointer to hold the single instance
        static Datastore* instance;

    public:
        // Static method to provide access to the instance
        static Datastore* getInstance() {
            if (instance == nullptr) {
                instance = new Datastore();
            }
            return instance;
        }
        
        // CRUD operations: create, read, update, delete
        void add_students(const std::string &filename, const std::vector<Student> &students);
        Student find_student(std::string student_name);
        std::vector<Student> find_all();
        void update_student(Student& obj);
        void delete_student(Student& obj);
};

// Initialize the static instance pointer to nullptr
Datastore* Datastore::instance = nullptr;