//
// Created by david on 2/14/2020.
//

#ifndef ASS4_MOVIEHEADNODE_H
#define ASS4_MOVIEHEADNODE_H


#include "MovieNode.h"
#include "ClassicNode.h"
#include <set>

class MovieHeadNode {

    // Movie Head Nodes will compare by Director
// Movie Node will compare by title, year
// Classic Node will compare by title, year, and major actor
// all have stocks
    friend ostream &operator<<(ostream &Out, const MovieHeadNode &M);
public:
    MovieHeadNode();
    MovieHeadNode(string director, int totalStock);
    ~MovieHeadNode();
    string director;
    int totalStock;
    ClassicNode* data;
    MovieHeadNode* left;
    MovieHeadNode* right;

//    virtual void insert(MovieNode* temp);
    virtual void insert(ClassicNode *temp);
//    virtual bool retrieve(const string director, MovieNode*& pos);


};


#endif //ASS4_MOVIEHEADNODE_H
