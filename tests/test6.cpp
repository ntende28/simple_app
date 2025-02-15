#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::map<std::string, std::string> parseStringToMap(const std::string& input) {
    std::map<std::string, std::string> result;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ',')) { // Split by ", "
        size_t start = token.find('{');
        size_t end = token.find('}');
        if (start != std::string::npos) token = token.substr(start + 1); // Remove leading '{'
        if (end != std::string::npos) token = token.substr(0, end);      // Remove trailing '}'
        // std::cout << token <<"\n";

        size_t delimiter = token.find(": ");
        if (delimiter != std::string::npos) {
            std::string key = token.substr(0, delimiter);
            std::string value = token.substr(delimiter + 2);
            result[key] = value;
        }
    }

    return result;
}

int main() {
    std::string input = "{Alice: Alice in wonderland}, {Bob: Bob's jungle}, {Charlie: Charlie and the chipmunks}";
    std::map<std::string, std::string> myMap = parseStringToMap(input);

    for (const auto& item : myMap) {
        std::cout << item.first << " -> " << item.second << std::endl;
    }

    return 0;
}
