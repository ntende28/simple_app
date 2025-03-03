#include "../include/student.h"


Student::Student(std::string& student_name) : name_(student_name) {}

Student::Student(int age, std::string name) : age_(age), name_(name) {}

Student::Student(int id, int age, std::string name) : id_(id), age_(age), name_(name) {}


//getter helper functions
int Student::get_age() {
   return this->age_;
}

int Student::get_id() {
   return this->id_;
}

std::string Student::get_name() {
   return this->name_;
}


void Student::set_name(std::string student_name) {
   this->name_ = student_name;
}

void Student::set_age(int age){
   this->age_ = age;
}


Subject::Subject(int id, std::string subject_name, std::string room) 
                : id_(id), subject_name_(subject_name), subject_room_(room) {}


Subject::Subject(std::string subject_name, std::string room) 
                : subject_name_(subject_name), subject_room_(room) {}

// getters
int Subject::get_id() {
    return this->id_;
}

std::string Subject::get_subject_name() {
    return this->subject_name_;
}

std::string Subject::get_location() {
    return this->subject_room_;
}

// setters
void Subject::set_subject(std::string subj) {
    this->subject_name_ = subj;
}

void Subject::set_location(std::string location) {
    this->subject_room_ = location;
}