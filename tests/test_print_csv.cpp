#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

struct Student {
    std::string name;
    int age;
    std::vector<std::string> subjectsAndRooms;
};

void printTable(const std::vector<Student>& students) {
    if (students.empty()) return;

    // Determine column widths
    size_t nameWidth = 4;  // Minimum width for "Name"
    size_t ageWidth = 3;   // Minimum width for "Age"
    size_t subjectWidth = 15; // Minimum width for "Subjects and Rooms"

    for (const auto& student : students) {
        nameWidth = std::max(nameWidth, student.name.size());
        for (const auto& entry : student.subjectsAndRooms) {
            subjectWidth = std::max(subjectWidth, entry.size());
        }
    }

    // Print header
    std::cout << "+" << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+"
              << std::string(subjectWidth + 2, '-') << "+\n";

    std::cout << "| " << std::setw(nameWidth) << std::left << "Name" << " | "
              << std::setw(ageWidth) << "Age" << " | "
              << std::setw(subjectWidth) << "Subjects and Rooms" << " |\n";

    std::cout << "+" << std::string(nameWidth + 2, '-') << "+"
              << std::string(ageWidth + 2, '-') << "+"
              << std::string(subjectWidth + 2, '-') << "+\n";

    // Print each row
    for (const auto& student : students) {
        std::cout << "| " << std::setw(nameWidth) << std::left << student.name << " | "
                  << std::setw(ageWidth) << student.age << " | "
                  << std::setw(subjectWidth) << student.subjectsAndRooms[0] << " |\n";

        for (size_t i = 1; i < student.subjectsAndRooms.size(); ++i) {
            std::cout << "| " << std::setw(nameWidth) << std::left << "" << " | "
                      << std::setw(ageWidth) << "" << " | "
                      << std::setw(subjectWidth) << student.subjectsAndRooms[i] << " |\n";
        }

        std::cout << "+" << std::string(nameWidth + 2, '-') << "+"
                  << std::string(ageWidth + 2, '-') << "+"
                  << std::string(subjectWidth + 2, '-') << "+\n";
    }
}

std::vector<Student> parseCSV() {
    std::vector<Student> students = {
        {"Alice", 21, {"Computer Programming 101: Computer Lab", "Electronics: Electronics lab", "Literature: Literature Room", "Physics: Physics Lab"}},
        {"Bob", 22, {"Computer Programming 101: Computer Lab", "Electronics: Electronics lab", "Literature: Literature Room", "Physics: Physics Lab"}},
        {"Charlie", 19, {"Computer Programming 101: Computer Lab", "Fine Art: Art room", "History: History room"}},
        {"Brown", 45, {"Computer Programming 101: Computer Lab", "Fine Art: Art room", "History: History room"}},
        {"Black eye pies", 35, {"Computer Programming 101: Computer Lab", "Fine Art: Art room", "History: History room"}}
    };
    return students;
}

int main() {
    std::vector<Student> students = parseCSV();
    printTable(students);
    return 0;
}
