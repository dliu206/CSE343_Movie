//
// Created by david on 2/22/2020.
//

#include "HashTable.h"


HashTable::HashTable() {
    this->size = 0;
    this->data.resize(20);
}

string HashTable::get(int key) {
    if (containsKey(key)) {
        return this->data[getHashKey(key, size)];
    } else {
        return "";
    }
}

void HashTable::put(int key, string name, string value) {
    if (this->size / data.size() >= 0.5) {
        //resize
        vector<string> temp(data.size() * 2);
        for (int a = 0; a < data.size(); a++) {
            if (data.at(a).length() != 0) {
                temp.at(getHashKey(a, data.size() * 2)) = data.at(a);
//                temp[getHashKey(a / data.size() * 2)]
            }
        }
        this->data = temp;
    }
    if (!containsKey(key)) {
        this->size++;
    }
    int index = getHashKey(key, data.size());
    if (this->data.at(index).length() == 0) {
        // add name?
        this->data.at(index) = name + "\n" + value;
    } else {
        this->data.at(index) = this->data.at(index) + "\n" + value;
    }

}

int HashTable::getHashKey(int key, int size) {
    return key % size;
}

bool HashTable::remove(int key) {
    if (this->data.at(getHashKey(key, data.size())).length() == 0) {
        return false;
    } else {
        this->size--;
        this->data.at(getHashKey(key, data.size())) = "";
        return true;
    }
}

bool HashTable::containsKey(int key) {
    return this->data.at(getHashKey(key, data.size())).length() != 0;
}

int HashTable::getSize() {
    return this->size;
}

void HashTable::display() {
    for (int a = 0; a < data.size(); a++) {
        if (data.at(a).length() != 0) {
            cout << data.at(a) << endl;
        }
    }
}