//

// ----------------------------------------- MovieDB.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows interface for MovieDB

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_MOVIEDB_H
#define ASS4_MOVIEDB_H
#include "MovieHeadNode.h"

class MovieDB {
    friend ostream &operator<<(ostream &Out, const MovieDB &M);
public:
    MovieDB();
    ~MovieDB();

    MovieHeadNode* funnyRoot;
    MovieHeadNode* dramaRoot;
    MovieHeadNode* classicRoot;

    // inserts a MovieHeadNode into a root
    void insert(string op, MovieHeadNode*& target);
    // Retrieves a MovieHeadNode given a root
    void retrieve(string type, string input1, string input2, MovieHeadNode*& curr, MovieHeadNode*& pos);
    void display() const;
private:
    void deleteHelper(MovieHeadNode* curr);
    void displayHelper(MovieHeadNode* curr) const;
};


#endif //ASS4_MOVIEDB_H
