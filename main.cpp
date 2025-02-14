// main.cpp

#include "src/student.h"

int main() {

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
	
	/*Creating the main program loop; It is meant to accomplish these things
		- check if user has not quit program
		- present a menu of options from which the user can select
		- based on selection, allow user to carry out any of the CRUD operations
		- Allow to edit particular attribute of existing obj data
		- save to a proxy datastore here this is a .csv file
		- return a table format for students in proxy storage
	*/
	int choice 0;

	while(std::cin.get() != 'q') {
		switch (choice)
		{
		case 0:
			/* Display the menu of options */
			break;
		
		case 1:
			/* Add new student */
			break;

		case 2:
			/* Return all existing students in the datastore in a table format  */
			break;

		case 3:
			/* Update info/attributes for an existing student */
			break;

		case 4:
			/* Delete a student from the datastore */
			break;

		case 5:
			/* Quit program */
			break;
		
		default:
			break;
		}
	}

	Student newbie;
	newbie.set_name("Kenneth");
	newbie.set_age(28);
	newbie.add_students_classes(science_subject_rooms);
	newbie.update_class_subject("Electronics", "Industrial electronics Lab");


	Student robert(22, "Robert", arts_rooms);
	robert.remove_class_subject("Computer Programming 101");

	std::cout << "Initial Students \n";
	newbie.print_student();
	std::cout << " \n";
	robert.print_student();

	std::cout << "****************************** \n";
	newbie.add_new_class_subject({"Power systems", "Power systems Lab"});
	robert.add_new_class_subject({"Geography", "Geography room"});
	std::cout << "After adding new subjects \n";
	newbie.print_student();
	std::cout << " \n";
	robert.print_student();
	return 0;
}