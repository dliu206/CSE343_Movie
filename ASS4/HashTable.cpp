//
// Created by david on 2/22/2020.
//

#include "HashTable.h"


HashTable::HashTable() {
    this->n = 0;
    this->size = 10;
    this->data = new User * [10];

    for (int a = 0; a < 10; a++) {
        User* temp = new User;
        data[a] = temp;
    }
}

// DO
HashTable::~HashTable() {
    for (int a = 0; a < this->size; a++) {
        delete data[a];
        data[a] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

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

            cout << s << endl;
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

User* HashTable::get(int key) {
    int index = 0;
    int hashCode = getHashKey(key, this->size);
    while (true) {
        if (index >= this->size) {
            return nullptr;
        }
        if (data[(hashCode + index) % this->size]->id == key) {
            return data[(hashCode + index) % this->size];
        }
        else if (data[(hashCode + index) % this->size] == nullptr) {
            return nullptr;
        }
        else {
            index++;
        }
    }
}

User* HashTable::retrieve(int key, User*& U) {
    int hashCode = getHashKey(key, this->size);
    int index = 0;
    while (true) {
        if (index >= this->size) {
            break;
        }
        if (data[(hashCode + index) % (this->size)]->id == key) {
            U = data[(hashCode + index) % (this->size)];
            return U;
        }
        else if (data[(hashCode + index) % (this->size)]->isEmpty()) {
            return U;
        }
        else {
            index++;
        }
    }
}

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
                        //                        delete temp[(hashCode + index) % (this->size * 2)];
                        temp[(hashCode + index) % (this->size * 2)] = data[a];
                        //                        delete data[a];
                        break;
                    }
                    else {
                        index++;
                    }
                }
            }
            else {
                //                delete this->data[a];
            }
        }
        //        delete[] data;
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
            //            delete data[(hashCode + index) % this->size];
            data[(hashCode + index) % this->size] = u;
            break;
        }
        else {
            index++;
        }
    }
}

// pre: Takes in integer User id and integer Hashmap size
// post: Returns integer hash key, or array-index, of the specified User id
int HashTable::getHashKey(int id, int size) {
    return id % size;
}

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
}

int HashTable::getSize() {
    return this->size;
}

void HashTable::display() {
    for (int a = 0; a < this->size; a++) {
        if (data[a] != nullptr && !data[a]->isEmpty()) {
            cout << *data[a] << endl;
        }
    }
}