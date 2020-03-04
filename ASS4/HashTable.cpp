//
// Created by david on 2/22/2020.
//

#include "HashTable.h"


HashTable::HashTable() {
    this->n = 0;
    this->size = 10;
    this->data[10];
}

User HashTable::get(int key) {
    User temp;
    int index = 0;
    int hashCode = getHashKey(key, this->size);
    while (true) {
        if (data[(hashCode + index) % this->size].id == key) {
            return data[(hashCode + index) % this->size];
        } else if (data[(hashCode + index) % this->size].isEmpty()) {
            return temp;
        } else {
            index++;
        }
    }
}

void HashTable::put(User u) {
    if (this->n / this->size >= 0.5) {
//        cout << "called" << endl;
        //resize
        User* temp = new User[this->size * 2];

        this->size *= 2;
        for (int a = 0; a < this->size; a++) {
            int hashCode = getHashKey(this->data[a].id, this->size * 2);
            int index = 0;
            while (true) {
                if (temp[(hashCode + index) % (this->size * 2)].isEmpty()) {
                    temp[(hashCode + index) % (this->size * 2)] = data[a];
                    break;
                } else {
                    index++;
                }
            }
        }
        this->data = temp;
    }
    if (!containsKey(u.id)) {
        this->n++;
    }
    int index = 0;
    int hashCode = getHashKey(u.id, size);
    while (true) {
        if (data[(hashCode + index) % this->size].id == u.id) {
            return;
        }
        if (data[(hashCode + index) % this->size].isEmpty()) {
            data[(hashCode + index) % this->size] = u;
            break;
        } else {
            index++;
        }
    }
}

int HashTable::getHashKey(int key, int size) {
    return key % size;
}

//bool HashTable::remove(int key) {
//    if (this->data.at(getHashKey(key, data.size())).length() == 0) {
//        return false;
//    } else {
//        this->size--;
//        this->data.at(getHashKey(key, data.size())) = "";
//        return true;
//    }
//}

bool HashTable::containsKey(int key) {
    int index = 0;
    int hashCode = getHashKey(key, this->size);
    while (true) {
        if (this->data[(hashCode + index) % this->size].id == key) {
            return true;
        } else if (this->data[(hashCode + index) % this->size].isEmpty()) {
            return false;
        } else {
            index++;
        }
    }
}

int HashTable::getSize() {
    return this->size;
}

void HashTable::display() {
    for (int a = 0; a < this->size; a++) {
        if (!data[a].isEmpty()) {
            cout << data[a] << endl;
        }
    }
}