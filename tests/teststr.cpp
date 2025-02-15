#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

string removal(string s) {
    string ns;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '{' && s.at(i) != '}') {
            ns+=s.at(i);
        }
    }
    return ns;
}

string _removal(string& str, char ct) {
    string ns;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) != ct)
            ns+=str.at(i);
    }
    return ns;
}


map<string, string> create_pair_string(string& str) {
    string element;
    string key;
    string value; 
    int index, idx;
    map<string, string> objects;

    for (int i = 0; i < str.length(); i++)
    {
        index = str.find(',');
        element = str.substr(0, index);
        idx = element.find(':');
        key = element.substr(0, idx);
        value = element.substr(idx+1);  
        objects[key] = value;     
    }
    return objects;
}

// char* sp

int main() {
    string my_str = "{Computer Programming 101: Computer Lab}, {Electronics: Electronics lab}, {Literature: Literature Room}, {Physics: Physics Lab}";
    cout << "Original string : " << my_str << endl;
    
    string my_new_string = removal(my_str);
    istringstream stream(my_new_string);
    string token;

    while (std::getline(stream, token, ',')) {
        std::cout << token << std::endl;
    }
    // char map_str[my_new_string.length()];
    // strcpy(map_str, my_new_string.c_str());

    // const char* delimiter = ",";
    // char* token = strtok(map_str, delimiter); // Get first token
    // while (token != nullptr) {
    //     std::cout << token << std::endl;
    //     token = strtok(nullptr, delimiter); // Get next token
    // }

    // const char* delimiter2 = ":";
    // char* key = strtok()

    return 0;
}