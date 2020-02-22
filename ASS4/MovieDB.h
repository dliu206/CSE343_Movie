//
// Created by david on 2/14/2020.
//

#ifndef ASS4_MOVIEDB_H
#define ASS4_MOVIEDB_H
#include "MovieHeadNode.h"

class MovieDB {
    friend ostream &operator<<(ostream &Out, const MovieDB &M);
public:
    MovieDB();
    MovieDB(const MovieDB &M);
    ~MovieDB();

    MovieHeadNode* funnyRoot;
    MovieHeadNode* dramaRoot;
    MovieHeadNode *classicRoot;

    void insert(string op, MovieHeadNode* target);
    bool retrieve(string op, string director, MovieHeadNode*& pos);
    void display() const;
private:
    void deleteHelper(MovieHeadNode* curr);
    void insertHelper(MovieHeadNode* curr, MovieHeadNode* target);
    void displayHelper(MovieHeadNode* curr) const;



};


#endif //ASS4_MOVIEDB_H
