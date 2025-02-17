#pragma once

/*Creating an interface/template for a proxy storage system to create a persistent storage 
with a csv file. This is to contain the input obtained from the user in the commandline.*/
#include "student.h"
#include <fstream>
#include <thread>
#include <chrono>

// #include <memory>

class Datastore {
    private:
        int count;
        Datastore() {}

        // Delete copy constructor and assignment operator to prevent copying
        Datastore(const Datastore&) = delete;
        // Datastore& operator=(const Datastore&) = delete;

    public:
        // Static method to provide access to the instance
        static Datastore& getInstance() {
            static Datastore instance;
            return instance;
        }

        int countLines(const std::string& filename);

        // CRUD operations: create, read, update, delete
        void add_students(const std::string &filename, std::vector<Student> &students);
        // Student find_student(std::string student_name);
        std::vector<Student> find_all(const std::string& filename);
        // void update_student(Student& obj);
        // void delete_student(Student& obj);
};

