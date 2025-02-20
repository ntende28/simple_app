#include <iostream>
#include <map>
#include <vector>

// Function to extract keys and values from a map
template <typename K, typename V>
void separateMap(const std::map<K, V>& inputMap, std::vector<K>& keys, std::vector<V>& values) {
    for (const auto& pair : inputMap) {
        keys.push_back(pair.first);
        values.push_back(pair.second);
    }
}

int main() {
    // Example map
    std::map<int, std::string> myMap = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Cherry"}
    };

    std::vector<int> keys;
    std::vector<std::string> values;

    // Separate map into keys and values
    separateMap(myMap, keys, values);

    // Print keys
    std::cout << "Keys: ";
    for (int key : keys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    // Print values
    std::cout << "Values: ";
    for (const std::string& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
