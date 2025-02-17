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
	std::vector<Student> current_students =  ds.find_all("../db/datastore.csv");

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
			printTable(current_students);
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