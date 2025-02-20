#include "../include/datastore.h"

/*Implementing a proxy storage system to create a persistent storage with a csv
file. This is to contain the input obtained from the user in the commandline.*/
// initialize the pointer
Datastore* Datastore::instance = nullptr;

// creating all needed tables
int Datastore::init() {
    if (sqlite3_open("../db/students.db", &db)) {
		std::cerr << "Cannot open database!" << std::endl;
		return -1;
	}
    else {
        // Create table
        std::string create_students_SQL = "CREATE TABLE IF NOT EXISTS Students ("
                "Student_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "Student_name TEXT NOT NULL, "
                "Student_age INTEGER NOT NULL"
                ");";


        std::string create_subjects_SQL = "CREATE TABLE IF NOT EXISTS Subjects("
            "Subject_id	INTEGER PRIMARY KEY AUTOINCREMENT, "
            "Subject_name 	TEXT NOT NULL, "
            "Location  	TEXT NOT NULL"
            ");";

        std::string create_student_courses_SQL = "CREATE TABLE IF NOT EXISTS Students_Courses("
            "student_id INT, "
            "Subject_id	INT, "
            "PRIMARY KEY (student_id, Subject_id), "
            "FOREIGN KEY (student_id) REFERENCES students(student_id), "
            "FOREIGN KEY (Subject_id) REFERENCES courses(Subject_id)), "
            ");";

        sqlite3_exec(db, create_students_SQL.c_str(), 0, 0, 0);
        sqlite3_exec(db, create_subjects_SQL.c_str(), 0, 0, 0);
        sqlite3_exec(db, create_student_courses_SQL.c_str(), 0, 0, 0);
        return 0;
    }
}

// add a new student to the db
void Datastore::add_student(Student& student) {
    const char* sql = "INSERT INTO Students (Student_name, Student_age) VALUES (?, ?);";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Bind values
    sqlite3_bind_text(stmt, 1, student.get_name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, student.get_age());

    // Execute the statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error inserting student: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Student inserted successfully!" << std::endl;
    }

    // Finalize statement
    sqlite3_finalize(stmt);
}


int students_callback(void* data, int argc, char** argv, char** colNames) {
    std::vector<Student>* students = static_cast<std::vector<Student>*>(data);

    int id = std::stoi(argv[0]);
    std::string name = argv[1];
    int age = std::stoi(argv[2]);
    students->emplace_back(id, age, name);
    return 0;
}

void Datastore::fetch_students(std::vector<Student>& students) {
    std::string sql = "SELECT * FROM Students;";
    char* errMsg;

    int rc = sqlite3_exec(db, sql.c_str(), students_callback, &students, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error fetching students: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}


void Datastore::add_subject(Subject& subject) {
    const char* sql = "INSERT INTO Subjects (Subject_name, Location) VALUES (?, ?);";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Bind values
    sqlite3_bind_text(stmt, 1, subject.get_subject_name().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, subject.get_location().c_str(), -1, SQLITE_STATIC);

    // Execute the statement
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error in adding a new subject : " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Subject added successfully!" << std::endl;
    }

    // Finalize statement
    sqlite3_finalize(stmt);
}

int subjects_callback(void* data, int argc, char** argv, char** colNames) {
    std::vector<Subject>* subjects = static_cast<std::vector<Subject>*>(data);

    int id = std::stoi(argv[0]);
    std::string subject = argv[1];
    std::string location = argv[2];

    subjects->emplace_back(id, subject, location);
    return 0;
}

void Datastore::fetch_subjects(std::vector<Subject>& subjects) {
    std::string sql = "SELECT * FROM Subjects;";
    char* errMsg;

    int rc = sqlite3_exec(db, sql.c_str(), subjects_callback, &subjects, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error fetching subjects: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

