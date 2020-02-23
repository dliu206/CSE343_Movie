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

    string get(int key);
    void put(int key, string name, string value);
    int getHashKey(int key, int size);
    bool remove(int key);
    bool containsKey(int key);
    int getSize();
    void display();

private:
    double size;
    vector<string> data;



};


#endif //ASS4_HASHTABLE_H
