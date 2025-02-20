#include <sqlite3.h>
#include <iostream>
#include <vector>


class Student {
    public:
        int id;
        std::string name;
        int age;
    
        Student(int i, std::string n, int a) : id(i), name(n), age(a) {}
    
        void display() const {
            std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << std::endl;
        }
    };
    

void insertStudent(sqlite3* db, const Student& student) {
    std::string sql = "INSERT INTO Students (ID, Name, Age) VALUES (" +
                      std::to_string(student.id) + ", '" +
                      student.name + "', " +
                      std::to_string(student.age) + ");";

    char* errMsg;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting student: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Student inserted successfully!" << std::endl;
    }
}

int callback(void* data, int argc, char** argv, char** colNames) {
    std::vector<Student>* students = static_cast<std::vector<Student>*>(data);

    int id = std::stoi(argv[0]);
    std::string name = argv[1];
    int age = std::stoi(argv[2]);

    students->emplace_back(id, name, age);
    return 0;
}

void fetchStudents(sqlite3* db, std::vector<Student>& students) {
    std::string sql = "SELECT * FROM Students;";
    char* errMsg;

    int rc = sqlite3_exec(db, sql.c_str(), callback, &students, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error fetching students: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

int main() {
    sqlite3* db;
    if (sqlite3_open("students.db", &db)) {
        std::cerr << "Cannot open database!" << std::endl;
        return 1;
    }

    // Create table
    std::string createTableSQL = "CREATE TABLE IF NOT EXISTS Students \
                                (ID INTEGER PRIMARY KEY, Name TEXT, Age INTEGER);";
                                
    sqlite3_exec(db, createTableSQL.c_str(), 0, 0, 0);

    // Insert students
    Student s1(1, "Alice", 22);
    Student s2(2, "Kenn", 25);
    Student s3(3, "Job", 25);
    Student s4(4, "Mouse", 26);
    Student s5(5, "Dr. Pym", 27);
    Student s6(6, "JC News", 35);
    Student s7(7, "Pole", 24);

    insertStudent(db, s1);
    insertStudent(db, s2);
    insertStudent(db, s3);
    insertStudent(db, s4);
    insertStudent(db, s5);
    insertStudent(db, s6);
    insertStudent(db, s7);


    // Fetch students
    std::vector<Student> students;
    fetchStudents(db, students);

    // Display students
    for (const auto& s : students) {
        s.display();
    }

    // Close database
    sqlite3_close(db);
    return 0;
}
