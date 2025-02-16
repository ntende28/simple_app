#include "../include/datastore.h"
#include "../include/student.h"
#include <iomanip>
// #include <vector>

// to handle all file related tasks
Datastore& ds = Datastore::getInstance();


void printTable(std::vector<Student>& students) {
    if (students.empty()) return;

    // Determine column widths
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
    for (auto& student : students) {
        bool firstRow = true;
        for (auto& entry : student.get_subjects_classes()) {
            if (firstRow) {
                std::cout << "| " << std::setw(nameWidth) << std::left << student.get_name() << " | "
                          << std::setw(ageWidth) << student.get_age() << " | "
                          << std::setw(subjectWidth) << (entry.first + ": " + entry.second) << " |\n";
                firstRow = false;
            } else {
                std::cout << "| " << std::setw(nameWidth) << std::left << "" << " | "
                          << std::setw(ageWidth) << "" << " | "
                          << std::setw(subjectWidth) << (entry.first + ": " + entry.second) << " |\n";
            }
        }

        std::cout << "+" << std::string(nameWidth + 2, '-') << "+"
                  << std::string(ageWidth + 2, '-') << "+"
                  << std::string(subjectWidth + 2, '-') << "+\n";
    }
}

int main () {

    std::map<std::string, std::string> science_subject_rooms = {
        {"Physics", "Physics Lab"}, 
        {"Electronics", "Electronics lab"},
        {"Computer Programming 101", "Computer Lab"},
        {"Literature", "Literature Room"}
    };

    std::map<std::string, std::string> arts_rooms = {
            {"History", "History room"},
            {"Fine Art", "Art room"},
            {"Computer Programming 101", "Computer lab"}
    };

    std::vector<Student> students = {      
        {21, "Alice", science_subject_rooms},
        {22, "Bob", science_subject_rooms},
        {19, "Charlie", arts_rooms},
        {45, "Brown", arts_rooms},
        {35, "Black eye pies", arts_rooms}
    };

    
    ds.add_students("datastore.csv", students);
    std::cout << "CSV file written successfully.\n";

    auto existing_students = ds.find_all("datastore.csv");
    printTable(existing_students);

    return 0;
}
