//

// ----------------------------------------- HashTable.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of Hash Table

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#include "HashTable.h"


// ------------------------------------ Constructor -----------------------------------------------

// Description

// Constructor: initializes the Hash Table with size 10
// preconditions: n/a
// postconditions: initializes the Hash Table with size 10

// --------------------------------------------------------------------------------------------
HashTable::HashTable() {
    this->n = 0;
    this->size = 10;
    this->data = new User *[10];

    for (int a = 0; a < 10; a++) {
        User* temp = new User;
        data[a] = temp;
    }
}


// ------------------------------------ Deconstructor -----------------------------------------------

// Description

// Deconstructor: Frees memory used by the Hash Table
// preconditions: n/a
// postconditions: Frees memory used by the Hash Table

// --------------------------------------------------------------------------------------------
HashTable::~HashTable() {
    for (int a = 0; a < this->size; a++) {
        delete data[a];
        data[a] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

// ------------------------------------ build -----------------------------------------------

// Description

// build: Stores values into the Hash Table given specificly styled lines specified in prog4_2020.pdf
// preconditions: n/a
// postconditions: Stores values into the Hash Table given specificly styled lines specified in prog4_2020.pdf

// --------------------------------------------------------------------------------------------
void HashTable::build(string fileName) {
    ifstream infile(fileName);

    if (!infile) {
        cout << "Customer file couldn't be opened" << endl;
    }
    else {
        string s;
        for (;;) {
            getline(infile, s);
            if (s.length() == 0) {
                break;
            }
            int index = s.find(" ");
            int id = stoi(s.substr(0, index));
            string name = s.substr(index + 1, s.length());

            if (containsKey(id)) {
                cout << "Duplicate customer ID: " << id << endl;
            }
            else {
                User* temp = new User(id, name);
                put(temp);
            }
            if (infile.eof()) {
                break;
            }
        }
    }
}

// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: retrieves the specific User within a Hash Table
// preconditions: n/a
// postconditions: retrieves the specific User within a Hash Table

// --------------------------------------------------------------------------------------------
bool HashTable::retrieve(int key, User*& U) {
    int hashCode = getHashKey(key, this->size);
    int index = 0;
    while (true) {
        if (index >= this->size) {
            break;
        }
        if (data[(hashCode + index) % (this->size)]->id == key) {
            U = data[(hashCode + index) % (this->size)];
            return true;
        }
        else if (data[(hashCode + index) % (this->size)]->isEmpty()) {
            return false;
        }
        else {
            index++;
        }
    }
    return false;
}

// ------------------------------------ put -----------------------------------------------

// Description

// put: Inserts a user into the Hash Table using linear probing. Resize is load factor >= 0.5
// preconditions: n/a
// postconditions: Inserts a user into the Hash Table

// --------------------------------------------------------------------------------------------
void HashTable::put(User* u) {
    if (this->n / this->size >= 0.5) {
        //resize
        User** temp = new User * [this->size * 2];

        for (int a = 0; a < this->size * 2; a++) {
            User* temp2 = new User;
            temp[a] = temp2;
        }

        for (int a = 0; a < this->size; a++) {
            if (!this->data[a]->isEmpty()) {
                int hashCode = getHashKey(this->data[a]->id, this->size * 2);
                int index = 0;
                while (true) {
                    if (index >= this->size) {
                        break;
                    }
                    if (temp[(hashCode + index) % (this->size * 2)]->isEmpty()) {
                        temp[(hashCode + index) % (this->size * 2)] = data[a];
                        break;
                    }
                    else {
                        index++;
                    }
                }
            }
            else {
            }
        }
        this->size *= 2;
        this->data = temp;
    }

    int index = 0;
    int hashCode = getHashKey(u->id, this->size);
    while (true) {
        if (index >= this->size) {
            break;
        }
        if (data[(hashCode + index) % this->size]->id == u->id) {
            cout << "Duplicate ID" << endl;
            return;
        }
        if (data[(hashCode + index) % this->size]->isEmpty()) {
            this->n++;
            data[(hashCode + index) % this->size] = u;
            break;
        }
        else {
            index++;
        }
    }
}

// ------------------------------------ getHashKey -----------------------------------------------

// Description

// getHashKey: generates a hashkey given an id and table size
// preconditions: n/a
// postconditions: generates a hashkey given an id and table size

// --------------------------------------------------------------------------------------------
int HashTable::getHashKey(int id, int size) {
    return id % size;
}

// ------------------------------------ containsKey -----------------------------------------------

// Description

// containsKey: Returns T/F if the key is in the Hash Table
// preconditions: n/a
// postconditions: Returns T/F if the key is in the Hash Table

// --------------------------------------------------------------------------------------------
bool HashTable::containsKey(int key) {
    int index = 0;
    int hashCode = getHashKey(key, this->size);
    while (true) {
        if (index >= this->size) {
            break;
        }
        if (this->data[(hashCode + index) % this->size]->id == key) {
            return true;
        }
        else if (this->data[(hashCode + index) % this->size]->isEmpty()) {
            return false;
        }
        else {
            index++;
        }
    }
    return false;
}

// ------------------------------------ display -----------------------------------------------

// Description

// display: Writes to console each user in the HashTable
// preconditions: n/a
// postconditions: Writes to console each user in the HashTable

// --------------------------------------------------------------------------------------------
void HashTable::display() {
    for (int a = 0; a < this->size; a++) {
        if (data[a] != nullptr && !data[a]->isEmpty()) {
            data[a]->display();
        }
    }
}