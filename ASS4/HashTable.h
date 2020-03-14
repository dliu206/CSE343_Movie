//

// ----------------------------------------- HashTable.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface to Hash Table using array-based and linear probing.

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
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

    // Takes in a filename and inserts items into the Hash Table
    void build(string);

    // Retrieve a user given an ID
    bool retrieve(int key, User*& U);

    // Puts a user in the Hash Table
    void put(User* u);

    // Generates the Hash Key
    int getHashKey(int key, int size);

    // Returns T/F if it finds the specific Hash Key
    bool containsKey(int key);

    // Displays the entirety of the HashTable
    void display();


private:
    double n;
    int size;
    User** data;
};


#endif //ASS4_HASHTABLE_H
