#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

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
