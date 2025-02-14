#pragma once

/*Creating an interface/template for a proxy storage system to create a persistent storage 
with a csv file. This is to contain the input obtained from the user in the commandline.*/
#include "student.h"

class Datastore {
    private:
        Student student_obj;
        Datastore(Student &obj) : student_obj(obj) {
            std::cout << "New datastore created\n";
        }

        // Delete copy constructor and assignment operator to prevent copying
        Datastore(const Datastore&) = delete;
        Datastore& operator=(const Datastore&) = delete;

        // Static pointer to hold the single instance
        static Datastore* instance;

    public:
        // Static method to provide access to the instance
        static Datastore* getInstance();
        
        // CRUD operations: create, read, update, delete
};

// Initialize the static instance pointer to nullptr
Datastore* Datastore::instance = nullptr;