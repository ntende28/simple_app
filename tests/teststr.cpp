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

int main() {
    string my_str = "{Computer Programming 101: Computer Lab}, {Electronics: Electronics lab}, {Literature: Literature Room}, {Physics: Physics Lab}";
    cout << "Original string : " << my_str << endl;
    
    string my_new_string = removal(my_str);
    istringstream stream(my_new_string);
    string token;
    map<string, string> result;

    while (getline(stream, token, ',')) {
        // cout << token << endl;
        size_t delimiter = token.find(": ");
        if (delimiter != std::string::npos) {
            std::string key = token.substr(0, delimiter);
            std::string value = token.substr(delimiter + 2);
            result[key] = value;
        }
    }
    
    for (auto &it : result)
    {
        cout << it.first << " -> " << it.second << endl;         
    }
    

    return 0;
}