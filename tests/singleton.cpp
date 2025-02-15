#include <iostream>

class Singleton {
private:
    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created!" << std::endl;
    }

    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static pointer to hold the single instance
    static Singleton* instance;

public:
    // Static method to provide access to the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void displayMessage() {
        std::cout << "Singleton instance method called!" << std::endl;
    }
};

// Initialize the static instance pointer to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    // Access Singleton instance
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->displayMessage();

    // Another access to the Singleton instance
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->displayMessage();

    // Checking if both pointers point to the same instance
    if (singleton1 == singleton2) {
        std::cout << "Both pointers point to the same instance." << std::endl;
    } else {
        std::cout << "Pointers point to different instances." << std::endl;
    }

    return 0;
}
