// importing all the helper functions
#include "include/helper_functions.hpp"

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
	std::string student, subject;
	int val = ds->init();
	std::vector<Student> my_students;
	std::vector<Subject> subjects;

	if (val == -1) {
        std::cout << "Error occurred in initializing the database!!\n";
    }

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
			add_new_student();
			break;
		
		case 2:
			std::cout << "Adding new subjects...\n";
			add_new_subject();
			break;

		case 3:
			/* Return all existing students in the datastore in a table format  */
			std::cout << "Displaying all existing students...\n";
			ds->fetch_students(my_students);
			print_students_table(my_students);
			break;

		case 4:
			/* Update info/attributes for an existing student */
			std::cout << "Updating student information...\n";
			break;

		case 5:
			/* Delete a student from the datastore */
			std::cout << "Deleting a student...\n";
			break;

		case 6:
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