#include <iostream>
#include <map>
#include <sstream>
#include <string>

class StudentRecords {
public:
    std::map<std::string, int> records;

    // Convert map to string
    std::string mapToString() const {
        std::ostringstream oss;
        oss << "{";
        for (auto it = records.begin(); it != records.end(); ++it) {
            oss << it->first << ": " << it->second;
            if (std::next(it) != records.end()) oss << ", ";
        }
        oss << "}";
        return oss.str();
    }

    // Convert string back to map
    void stringToMap(const std::string& str) {
        records.clear();
        std::string content = str.substr(1, str.size() - 2);  // Remove '{' and '}'

        std::stringstream ss(content);
        std::string pair;

        while (getline(ss, pair, ',')) {
            std::stringstream pairStream(pair);
            std::string key, value;

            getline(pairStream, key, ':');
            getline(pairStream, value, ':');

            // Trim whitespace
            key.erase(0, key.find_first_not_of(" \t\n\r"));
            key.erase(key.find_last_not_of(" \t\n\r") + 1);
            value.erase(0, value.find_first_not_of(" \t\n\r"));
            value.erase(value.find_last_not_of(" \t\n\r") + 1);

            std::istringstream keyStream(key);
            std::istringstream valueStream(value);
            
            std::string k;
            int v;
            keyStream >> k;
            valueStream >> v;

            records[k] = v;
        }
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
        {"Alice", 23},
        {"Bob", 34},
        {"Charlie", 29}
    };

    std::string mapStr = sr.mapToString();
    std::cout << "Map as string: " << mapStr << std::endl;

    StudentRecords sr2;
    sr2.stringToMap(mapStr);
    std::cout << "\nReconstructed Map from string:" << std::endl;
    sr2.display();

    return 0;
}
