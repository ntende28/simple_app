#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>


class Student {

  private:
			int age_;
			std::string name_;
			std::map<std::string, std::string> subjects_classes;

  public:
  		// class constructors
			Student();
			Student(std::string student_name);
			// Student(&Student student);
			Student(int age, std::string name, std::map<std::string, std::string> subjects_classes);
			~Student();
						
			// getter helper functions
			int get_age();
			std::string get_name();
			void get_subjects_classes();

			void print_student();

			// setters/object creator functions
			void set_name(std::string student_name);
			void set_age(int age);
			void add_students_classes(std::map<std::string, std::string> rooms);

			// create, edit, update, delete
			void add_new_class_subject(std::pair<std::string, std::string> new_subject);
			bool exists(const std::string& key);
			void update_class_subject(const std::string& key, const std::string& new_value);
			void remove_class_subject(const std::string& key);
};
