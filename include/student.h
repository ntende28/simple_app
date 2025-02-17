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
	std::map<std::string, std::string> subjects_classes;

  public:
  		// class constructors
	Student();
	Student(std::string& student_name);
	// Student(&Student student);
	Student(int age, std::string name, std::map<std::string, std::string> subjects_classes);
	Student(int id, int age, std::string name, std::map<std::string, std::string> subjects_classes);
	~Student();
				
	// getter helper functions
	int get_age();
	int get_id();
	std::string get_name();
	std::map<std::string, std::string> get_subjects_classes();

	// csv helpers
	std::string map_to_string() const;
	std::string brace_removal(std::string& s);
	std::map<std::string, std::string> string_to_map(std::string& str);
	std::string to_csv() const;

	// setters/object creator functions
	void set_id(int id);
	void set_name(std::string student_name);
	void set_age(int age);
	void add_students_classes(std::map<std::string, std::string>& rooms);

	// create, edit, update, delete
	void add_new_class_subject(std::pair<std::string, std::string> new_subject);
	bool exists(const std::string& key);
	void update_class_subject(const std::string& key, const std::string& new_value);
	void remove_class_subject(const std::string& key);
};
