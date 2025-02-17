#include "../include/student.h"


// object constructors
Student::Student() {}

Student::Student(std::string& student_name) : name_(student_name){
   age_ = 10;
   subjects_classes = {{"None", "None"}};
}


Student::Student(int age, std::string name, std::map<std::string, std::string> students_classes) 
   : age_(age), name_(name), subjects_classes(students_classes) {}


Student::Student(int id, int age, std::string name, std::map<std::string, std::string> students_classes) 
   : id_(id), age_(age), name_(name), subjects_classes(students_classes) {}


Student::~Student(){}



//getter helper functions
int Student::get_age() {
   return this->age_;
}

int Student::get_id() {
   return this->id_;
}

std::string Student::get_name() {
   return this->name_;
}

std::map<std::string, std::string> Student::get_subjects_classes() {
   return this->subjects_classes;
}

// csv helper functions
std::string Student::to_csv() const {
   return std::to_string(id_) + "," + name_ + "," + std::to_string(age_) + "," + map_to_string();
}

std::string Student::map_to_string() const {
   // std::map<std::string, std::string> rms = this->subjects_classes;
   std::ostringstream oss;
   oss << "{";
   for (auto it = subjects_classes.begin(); it != subjects_classes.end(); ++it) {
      oss << "{";
      oss << it->first << ": " << it->second;
      oss << "}";
      if (std::next(it) != subjects_classes.end())
         oss << ", ";
   }
   oss << "}";
   return oss.str();
}

std::string Student::brace_removal(std::string& s) {
   std::string ns;
   for (int i = 0; i < s.length(); i++)
   {
       if (s.at(i) != '{' && s.at(i) != '}') {
           ns+=s.at(i);
       }
   }
   return ns;
}

std::map<std::string, std::string> Student::string_to_map(std::string& input) {
   std::string my_new_string = brace_removal(input);
   std::map<std::string, std::string> result;
   std::istringstream stream(my_new_string);
   std::string token;

   while (std::getline(stream, token, ',')) { // Split by ","
      size_t delimiter = token.find(": ");
      if (delimiter != std::string::npos) {
         std::string key = token.substr(0, delimiter);
         std::string value = token.substr(delimiter + 2);
         result[key] = value;
      }
   }
   return result;
}


// setter functions
void Student::set_id(int id) {
   this->id_ = id;
}

void Student::set_name(std::string student_name) {
   this->name_ = student_name;
}

void Student::set_age(int age){
   this->age_ = age;
}

void Student::add_students_classes(std::map<std::string, std::string>& rooms) {
   this->subjects_classes = rooms;
}


// CRUD operations; create, update and delete
void Student::add_new_class_subject(std::pair<std::string, std::string> new_subject){
   this->subjects_classes.insert(new_subject);
}


bool Student::exists(const std::string& key) {
   if (subjects_classes.count(key))
      return true;
   return false;
}

void Student::update_class_subject(const std::string& key, const std::string& new_value){
   // Check if the key exists in the map
   auto it = subjects_classes.find(key);
   // if(exists(key)) {
   //    subjects_classes[key] = new_value;
   // }
   if (it != subjects_classes.end()) {
      // If the key exists, update the value
      it->second = new_value;
   } 
   else {
      // If the key doesn't exist, you can choose to add it
      std::cout << "Key not found. Adding a new entry." << std::endl;
      subjects_classes[key] = new_value;
   } 
}


void Student::remove_class_subject(const std::string& key){
  // Try to erase the key and check if it existed
   // if (exists(key)){
   //    subjects_classes.erase(key);
   //    std::cout << "Key '" << key << "' successfully deleted." << std::endl;
   // }   
   size_t erased = subjects_classes.erase(key);
   if (erased > 0) {
      std::cout << "Key '" << key << "' successfully deleted." << std::endl;
      // return true;  // Successfully deleted
   } 
   else {
      std::cout << "Key '" << key << "' not found. Nothing deleted." << std::endl;
      // return false;  // Key was not found
   }
}
