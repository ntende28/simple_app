#pragma once

#include "student.h"
#include <fstream>
#include <sqlite3.h>
#include <functional>

// #include <memory>


class DatabaseEvent {
    public:
        using EventHandler = std::function<void(int)>; // Callback function accepting an int
        void addListener(EventHandler handler);
        
        void trigger(int newValue);
    private:
        std::vector<EventHandler> listeners;
};


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





