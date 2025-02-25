#pragma once

/*Creating an interface/template for a proxy storage system to create a persistent storage 
with a csv file. This is to contain the input obtained from the user in the commandline.*/
#include "student.h"
#include "subjects.h"
#include <fstream>
#include <sqlite3.h>
#include <functional>

// #include <memory>
using EventHandler = std::function<void(int)>; // Callback function accepting an int

namespace datastore {

    class Datastore {
        private:
            Datastore() {}
            sqlite3* db;

            // Delete copy constructor and assignment operator to prevent copying
            Datastore(const Datastore&) = delete;
            Datastore& operator=(const Datastore&) = delete;

            static Datastore* instance;
            int recordCount = 0; // Variable to track number of records
        public:
            // Static method to provide access to the instance
            static Datastore* getInstance() {
                if (instance == nullptr) {
                    instance = new Datastore();
                }
                return instance;
            }

            int init();
            DatabaseEvent eventHandler; // Event handler instance

            // CRUD operations (students): create, read, update, delete
            void add_student(Student& student);
            void onDatabaseInsert(int newCount);
            // bool find_student(std::string student_name);
            void fetch_students(std::vector<Student>& students);
            // void update_student(std::string& student_name);
            // void delete_student(std::string& student_name);

            // CRUD operations (subjects)
            void add_subject(Subject& subject);
            void fetch_subjects(std::vector<Subject>& subjects);

    };

    class DatabaseEvent {
        private:
            std::vector<EventHandler> listeners;

        public:
            void addListener(EventHandler handler) {
                listeners.push_back(handler);
            }
            
            void trigger(int newValue) {
                for (const auto& handler : listeners) {
                    handler(newValue);
                }
            }
    };
}




