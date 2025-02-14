#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Student {
public:
    std::string name;
    int age;
    double grade;

    Student(std::string n, int a, double g) : name(n), age(a), grade(g) {}

    // Convert object data to CSV format
    std::string toCSV() const {
        return name + "," + std::to_string(age) + "," + std::to_string(grade);
    }
};

void writeToCSV(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    // Write header
    file << "Name,Age,Grade\n";

    // Write each student as a CSV row
    for (const auto& student : students) {
        file << student.toCSV() << "\n";
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

int main() {
    std::vector<Student> students = {
        {"Alice", 20, 85.5},
        {"Bob", 22, 78.3},
        {"Charlie", 19, 92.7}
    };

    writeToCSV("students.csv", students);
    std::cout << "CSV file written successfully.\n";

    auto current_students = readFromCSV("students.csv");
    // adding the headers
    std::cout << "Name \t| Age \t| Grade "<< std::endl;
    for(auto i: current_students)
        std::cout << i.name << " \t| " << i.age << " \t| " << i.grade << "\n";

    return 0;
}
