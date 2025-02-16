#include "../include/datastore.h"

/*Implementing a proxy storage system to create a persistent storage with a csv
file. This is to contain the input obtained from the user in the commandline.*/


// adding students to csv file
void Datastore::add_students(const std::string &filename, std::vector<Student> &students) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    // Write header
    file << "Id,Name,Age,Subjects and Rooms\n";

    // Write each student as a CSV row  
    for (int i = 0; i < students.size(); i++)
    {
       students[i].set_id(i);
       file << students[i].to_csv() << "\n";
    }
    file.close();
}

// returning all students in the csv file
std::vector<Student> Datastore::find_all(const std::string& filename) {
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
        std::string id, name, ageStr, subject_class_str;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, subject_class_str);

        int student_id = std::stoi(id);
        int age = std::stoi(ageStr);
        Student my_student(name);
        my_student.set_id(student_id);
        my_student.set_age(age);
        std::map<std::string, std::string> subjects_classes = my_student.string_to_map(subject_class_str);

        students.emplace_back(student_id, age, name, subjects_classes);
    }

    file.close();
    return students;
}

// void Datastore::update_student(Student& obj) {

// }

// void Datastore::delete_student(Student& obj) {

// }

// Student Datastore::find_student(std::string student_name) {

// }

int Datastore::countLines(const std::string& filename) {
    std::ifstream file(filename);
    int lines = 0;
    std::string temp;
    
    while (getline(file, temp)) {
        lines++;
    }

    return lines;
}



