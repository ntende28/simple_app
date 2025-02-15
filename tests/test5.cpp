#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>

class StudentRecords {
public:
    std::map<std::string, std::string> records;

    // Convert map to string
    std::string mapToString() const {
        std::ostringstream oss;
        for (auto it = records.begin(); it != records.end(); ++it) {
            oss << "{";
            oss << it->first << " : " << it->second;
            oss << "}";
            if (std::next(it) != records.end()) {
                oss << ", ";
                // oss << "}";
            } 
            // oss << "}";
        }
        return oss.str();
    }

    std::map<std::string, std::string> parseStringToMap(const std::string& input) {
        std::map<std::string, std::string> result = this->records;
        std::stringstream ss(input);
        std::string token;
    
        while (std::getline(ss, token, ',')) { // Split by ", "
            size_t start = token.find('{');
            size_t end = token.find('}');
            if (start != std::string::npos) 
                token = token.substr(start + 1); // Remove leading '{'
            if (end != std::string::npos) 
                token = token.substr(0, end);      // Remove trailing '}'
    
            size_t delimiter = token.find(" : ");
            if (delimiter != std::string::npos) {
                std::string key = token.substr(0, delimiter);
                std::string value = token.substr(delimiter + 2);
                records[key] = value;
            }
        }
    
        return records;
    }

    // Display records
    void display() const {
        for (const auto& item : records) {
            std::cout << item.first << ": " << item.second << std::endl;
        }
    }
};

int main() {
    StudentRecords sr;
    sr.records = {
        {"Alice", "Alice in wonderland"},
        {"Bob", "Bob's jungle"},
        {"Charlie", "Charlie and the chipmunks"}
    };

    std::string mapStr = sr.mapToString();
    std::cout << "Map as string: " << mapStr << std::endl;

    StudentRecords sr2;
    sr2.parseStringToMap(mapStr);
    std::cout << "\nReconstructed Map from string:" << std::endl;
    sr2.display();

    return 0;
}
