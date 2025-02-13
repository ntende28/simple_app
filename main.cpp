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