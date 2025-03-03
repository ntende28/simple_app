#pragma once

#include <iostream>
#include <string>
#include <vector>


class Student {

  private:
	int id_;
	std::string name_;
	int age_;
	
  public:
  		// class constructors
	// Student();
	Student(std::string& student_name);
	// Student(&Student student);
	Student(int age, std::string name);
	Student(int id, int age, std::string name);
	// ~Student();
				
	// getter helper functions
	int get_age();
	int get_id();
	std::string get_name();

	
	// setters/object creator functions
	void set_id(int id);
	void set_name(std::string student_name);
	void set_age(int age);
};

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