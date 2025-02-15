#include "../include/datastore.h"
#include "../include/student.h"
// #include <vector>

// to handle all file related tasks
Datastore& ds = Datastore::getInstance();

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
    for (auto &i : existing_students)
    {
        std::cout << i.map_to_string() << "\n";
    }
    
    // std::cout << "Name \t\t\t| Age \t| Subjects and classrooms \t\t|"<< std::endl;
    // for (auto &it : existing_students)
    // {
    //     std::cout << it.get_name() << "\t\t\t| " << it.get_age() << " \t| " << it.map_to_string() << "\t|\n";

    // }
    
    return 0;
}
