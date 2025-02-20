#include "../include/subjects.h"


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