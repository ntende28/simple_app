#include <iostream>
#include <map>
#include <sstream>

template <typename K, typename V>
std::string mapToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    // oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << it->first << " -- " << it->second;
        if (std::next(it) != m.end())
            oss << ", ";
    }
    // oss << "}";
    return oss.str();
}

int main() {
    std::map<std::string, int> myMap = {
        {"Alice", 23},
        {"Bob", 34},
        {"Charlie", 29}
    };

    std::cout << mapToString(myMap) << std::endl;
    return 0;
}
