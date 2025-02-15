// main.cpp

#include "include/student.h"
#include "include/datastore.h"
#include <limits>

static std::vector<Student> my_students;

Datastore& ds = Datastore::getInstance();

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
	std::string student_name;
	std::string subjects_rooms;
		
	std::cout << "Enter the student name : ";
	std::cin >> student_name;
	std::cout << "Enter the student's age : ";
	std::cin >> student_age;
	std::cout << "Enter choice of subjects and their rooms (e.g. physics : physics lab, art : artroom) : \n";
	std::cin >> subjects_rooms;

	Student my_student(student_name);
	my_student.set_age(student_age);
	std::map<std::string, std::string> rooms = my_student.string_to_map(subjects_rooms);
	my_student.add_students_classes(rooms);
	return my_student;
}


void add_new_students() {
    char flag = 'y';

    while (flag == 'y' || flag == 'Y') {
		Student student = _add_students();
		my_students.push_back(student);
		ds.add_students("datastore.csv", my_students);

        std::cout << "Do you want to enter another student (y/n)? ";
        std::cin >> flag;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush buffer
    }

    std::cout << "Returning to main menu...\n";
}

void display_students(std::vector<Student>& students) {
	
	std::cout << "Name \t| Age \t| Subjects & Classes \t|\n";
	for (auto &it : students) {
		std::cout << it.get_name() << " \t|" << it.get_age() << " \t|" << it.map_to_string() << " \t|\n";
	}
	std::cout << "\n";
}

int main() {

	/*Creating the main program loop; It is meant to accomplish these things
		- check if user has not quit program
		- present a menu of options from which the user can select
		- based on selection, allow user to carry out any of the CRUD operations
		- Allow to edit particular attribute of existing obj data
		- save to a proxy datastore here this is a .csv file
		- return a table format for students in proxy storage
	*/
	int choice = 0;
	bool is_active = true;
	std::vector<Student> current_students =  ds.find_all("datastore.csv");
	print_menu();
	
	while(is_active) {	
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			/* Display the menu of options */
			break;
		
		case 1:
			std::cout << "Adding new students...\n";
			add_new_students();
			break;

		case 2:
			/* Return all existing students in the datastore in a table format  */
			std::cout << "Displaying all existing students...\n";
			display_students(current_students);
			break;

		case 3:
			/* Update info/attributes for an existing student */
			std::cout << "Updating student information...\n";
			break;

		case 4:
			/* Delete a student from the datastore */
			std::cout << "Deleting a student...\n";
			break;

		case 5:
			/* Quit program */
			std::cout << "Exiting program...\n";
			return 0;
		
		default:
			std::cout << "Invalid choice. Try again.\n";
			break;
		}
		print_menu();  // Display the menu again only after processing a choice
	}

	return 0;
}