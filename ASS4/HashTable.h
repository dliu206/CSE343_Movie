//
// Created by david on 2/22/2020.
//

#ifndef ASS4_HASHTABLE_H
#define ASS4_HASHTABLE_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class HashTable {
public:
    HashTable();
//    double size;
//    vector<string> data;

    User get(int key);
    void put(User u);
    int getHashKey(int key, int size);
//    bool remove(int key);
    bool containsKey(int key);
    int getSize();
    void display();

private:
    double n;
    int size;
    User* data;



};


#endif //ASS4_HASHTABLE_H
