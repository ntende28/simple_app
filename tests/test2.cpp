#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}
};

void writeCSV(const std::string &filename, const std::vector<Person> &people) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        return;
    }
    outFile << "Name,Age\n";
    for (const auto &person : people) {
        outFile << person.name << "," << person.age << "\n";
    }
    outFile.close();
}

int main() {
    std::vector<Person> people = { Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35) };
    writeCSV("people.csv", people);
    return 0;
}