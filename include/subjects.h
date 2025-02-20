#pragma once

#include <iostream>

class Subject {
    private:
        int id_;
        std::string subject_name_;
        std::string subject_room_;

    public:
        // constructors
        Subject(std::string subject_name, std::string room);
        Subject(int id, std::string subject_name, std::string room);

        // getters
        int get_id();
        std::string get_subject_name();
        std::string get_location();

        // setters
        void set_subject(std::string subj);
        void set_location(std::string location);
};