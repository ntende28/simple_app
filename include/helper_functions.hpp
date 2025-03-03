#pragma once

/*This contains helper functions and variables to be utilised by the main function*/

#include "student.h"
#include "datastore.h"
#include <iomanip>

Datastore* ds = Datastore::getInstance();

void print_menu(){
	std::cout << "0. Display available options \n";
	std::cout << "1. Add a new student \n";
    std::cout << "2. Add a new course \n";
	std::cout << "3. View all existing students \n";
	std::cout << "4. Update the details of a student \n";
	std::cout << "5. Delete a student \n";
	std::cout << "6. Quit the program \n";
	std::cout << "Enter your choice: ";
}

void add_new_student() {
    int student_age;
    std::string student_name;
        
    std::cout << "Enter the student name : ";
    std::cin >> student_name;
    std::cout << "Enter the student's age : ";
    std::cin >> student_age;
    
    Student my_student(student_age, student_name);
    ds->add_student(my_student);
    std::cout << "Returning to main menu...\n";
}

void add_new_subject() {
    std::string subject_name;
    std::string subject_room;
        
    std::cout << "Enter the course name : ";
    std::cin >> subject_name;
    std::cout << "Enter the study room for subject : ";
    std::cin >> subject_room;
    
    Subject my_subject(subject_name, subject_room);
    ds->add_subject(my_subject);
    std::cout << "Returning to main menu...\n";
}

void print_all_students(std::vector<Student>& students) {
    if (students.empty()) return;

    std::cout << "ID \t Name \t Age \t" << std::endl;
    for (auto& it : students) {
        std::cout << it.get_id() <<"\t" 
                  << it.get_name() << "\t"
                  << it.get_age() << std::endl;
    }
}

void print_students_table(std::vector<Student>& students) {
    if (students.empty()) return;

    // Determine column widths
	size_t id_field = 3;
    size_t nameWidth = 4;  // Minimum width for "Name"
    size_t ageWidth = 3;   // Minimum width for "Age"
    
    for (auto& student : students) {
        nameWidth = std::max(nameWidth, student.get_name().size());
    }
    // Print header
    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+\n";

    std::cout << "| " << std::setw(id_field) << std::left << "Id" << " | "
			  << std::setw(nameWidth) << std::left << "Name" << " | "
              << std::setw(ageWidth) << "Age" << " | \n";

    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+\n";

       // Print each row
       for (auto& student : students) {
            std::cout << "| " << std::setw(id_field) << std::left << student.get_id() << " | "
                    << "| " << std::setw(nameWidth) << std::left << student.get_name() << " | "
                    << std::setw(ageWidth) << student.get_age() << " | \n";

            
            std::cout << "+" << std::string(id_field + 2, '-') << "+"
                    << "+" << std::string(nameWidth + 2, '-') << "+"
                    << std::string(ageWidth + 2, '-') << "+\n";
        }
}

void print_subjects_table(std::vector<Subject>& subjects) {
    if (subjects.empty()) return;

    // Determine column widths
	size_t id_field = 3;
    size_t subjectWidth = 4;  // Minimum width for "Name"
    size_t locationWidth = 3;   // Minimum width for "Age"
    
    for (auto& sub : subjects) {
        subjectWidth = std::max(subjectWidth, sub.get_subject_name().size());
        locationWidth = std::max(locationWidth, sub.get_location().size());
    }
    // Print header
    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(subjectWidth + 2, '-') << "+"
              << std::string(locationWidth + 2, '-') << "+\n";

    std::cout << "| " << std::setw(id_field) << std::left << "Id" << " | "
			  << std::setw(subjectWidth) << std::left << "Name" << " | "
              << std::setw(locationWidth) << "Age" << " | \n";

    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(subjectWidth + 2, '-') << "+"
              << std::string(locationWidth + 2, '-') << "+\n";

       // Print each row
       for (auto& sub : subjects) {
            std::cout << "| " << std::setw(id_field) << std::left << sub.get_id() << " | "
                    << "| " << std::setw(subjectWidth) << std::left << sub.get_subject_name() << " | "
                    << std::setw(locationWidth) << sub.get_location() << " | \n";

            
            std::cout << "+" << std::string(id_field + 2, '-') << "+"
                    << "+" << std::string(subjectWidth + 2, '-') << "+"
                    << std::string(locationWidth + 2, '-') << "+\n";
        }
}

