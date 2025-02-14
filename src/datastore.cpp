#include "../include/datastore.h"

/*Implementing a proxy storage system to create a persistent storage with a csv
file. This is to contain the input obtained from the user in the commandline.*/

void Datastore::add_students(const std::string &filename, const std::vector<Student> &students) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    // Write header
    file << "Name,Age,Subjects and Rooms\n";

    // Write each student as a CSV row
    for (const auto& student : students) {
        file << student.to_csv() << "\n";
    }

    file.close();
}
std::vector<Student> readFromCSV(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for reading!\n";
        return students;
    }

    std::string line;
    bool firstLine = true;  // To skip the header

    while (getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string name, ageStr, gradeStr;

        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, gradeStr, ',');

        int age = std::stoi(ageStr);
        double grade = std::stod(gradeStr);

        students.emplace_back(name, age, grade);
    }

    file.close();
    return students;
}

std::vector<Student> Datastore::find_all() {
    return this->students;
}

void Datastore::update_student(Student& obj) {

}

void Datastore::delete_student(Student& obj) {

}

Student Datastore::find_student(std::string student_name) {

}

