#pragma once

/*This contains helper functions and variables to be utilised by the main function*/

#include "student.h"
#include "datastore.h"
#include <iomanip>
#include <thread>

std::vector<Student> my_students;

Datastore& ds = Datastore::getInstance();

std::map<std::string, std::string> science_subject_rooms = {
	{"Physics", "Physics Lab"}, 
	{"Electronics", "Electronics lab"},
	{"Computer Programming 101", "Computer Lab"},
	{"Literature", "Literature Room"}
};

std::map<std::string, std::string> arts_subject_rooms = {
		{"History", "History room"},
		{"Fine Art", "Art room"},
		{"Geography", "Geog room"},
		{"Computer Programming 101", "Computer lab"}
};


void print_menu(){
	std::cout << "0. Display available options \n";
	std::cout << "1. Add a new student \n";
	std::cout << "2. View all existing students \n";
	std::cout << "3. Update the details of a student \n";
	std::cout << "4. Delete a student \n";
	std::cout << "5. Quit the program \n";
	std::cout << "Enter your choice: ";
}

Student _add_students() {
	int student_age;
	char srm;
	std::string student_name;
	std::map<std::string, std::string> subject_rooms;
		
	std::cout << "Enter the student name : ";
	std::cin >> student_name;
	std::cout << "Enter the student's age : ";
	std::cin >> student_age;
	std::cout << "Is student an arts or science student (Enter A for arts or S for sciences): ";
	std::cin >> srm;
	if (srm == 'A' || srm == 'a') {
		subject_rooms = arts_subject_rooms;
	} else if (srm == 's' || srm == 'S') {
		subject_rooms = science_subject_rooms;
	} else {
		subject_rooms = {{"None", "None"}};
	}

	Student my_student(student_age, student_name, subject_rooms);
	return my_student;
}


void add_new_students() {
	Student student = _add_students();
	my_students.push_back(student);
	ds.add_students("../db/datastore.csv", my_students);
    std::cout << "Returning to main menu...\n";
}


void printTable(std::vector<Student>& students) {
    if (students.empty()) return;

    // Determine column widths
	size_t id_field = 3;
    size_t nameWidth = 4;  // Minimum width for "Name"
    size_t ageWidth = 3;   // Minimum width for "Age"
    size_t subjectWidth = 15; // Minimum width for "Subjects and Rooms"

    
    for (auto& student : students) {
        nameWidth = std::max(nameWidth, student.get_name().size());
        for (auto& entry : student.get_subjects_classes()) {
            size_t combinedSize = entry.first.size() + entry.second.size() + 2; // "Subject: Room"
            subjectWidth = std::max(subjectWidth, combinedSize);
        }
    }
    // Print header
    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+"
              << std::string(subjectWidth + 2, '-') << "+\n";

    std::cout << "| " << std::setw(id_field) << std::left << "Id" << " | "
			  << std::setw(nameWidth) << std::left << "Name" << " | "
              << std::setw(ageWidth) << "Age" << " | "
              << std::setw(subjectWidth) << "Subjects and Rooms" << " |\n";

    std::cout << "+" << std::string(id_field + 2, '-') << "+"
			  << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+"
              << std::string(subjectWidth + 2, '-') << "+\n";

    // Print each row
    for (auto& student : students) {
        bool firstRow = true;
        for (auto& entry : student.get_subjects_classes()) {
            if (firstRow) {
                std::cout << "| " << std::setw(id_field) << std::left << student.get_id() << " | "
						  << std::setw(nameWidth) << std::left << student.get_name() << " | "
                          << std::setw(ageWidth) << student.get_age() << " | "
                          << std::setw(subjectWidth) << (entry.first + ": " + entry.second) << " |\n";
                firstRow = false;
            } else {
                std::cout << "| " << std::setw(id_field) << std::left << "" << " | "
						  << std::setw(nameWidth) << std::left << "" << " | "
                          << std::setw(ageWidth) << "" << " | "
                          << std::setw(subjectWidth) << (entry.first + ": " + entry.second) << " |\n";
            }
        }

        std::cout << "+" << std::string(id_field + 2, '-') << "+"
				  << std::string(nameWidth + 2, '-') << "+"
                  << std::string(ageWidth + 2, '-') << "+"
                  << std::string(subjectWidth + 2, '-') << "+\n";
    }
}
