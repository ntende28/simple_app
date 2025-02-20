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


