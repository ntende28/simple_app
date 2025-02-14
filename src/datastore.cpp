#include "../include/datastore.h"

/*Implementing a proxy storage system to create a persistent storage with a csv
file. This is to contain the input obtained from the user in the commandline.*/

Datastore* Datastore::getInstance() {
    if (instance == nullptr) {
        instance = new Datastore(Student &obj);
    }
    return instance;
}