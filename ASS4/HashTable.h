//
// Created by david on 2/22/2020.
//

#ifndef ASS4_HASHTABLE_H
#define ASS4_HASHTABLE_H

#include <iostream>
#include <vector>
#include "User.h"
#include <fstream>

using namespace std;

class HashTable {
public:
    HashTable();
    ~HashTable();
    //    double size;
    //    vector<string> data;

    void build(string);

    User* get(int key);
    User* retrieve(int key, User*& U);
    void put(User* u);
    int getHashKey(int key, int size);
    //    bool remove(int key);
    bool containsKey(int key);
    int getSize();
    void display();


private:
    double n;
    int size;
    User** data;



};


#endif //ASS4_HASHTABLE_H
