//
// Created by david on 2/14/2020.
//

#ifndef ASS4_MOVIEHEADNODE_H
#define ASS4_MOVIEHEADNODE_H


#include "MovieNode.h"
#include "ClassicNode.h"
#include <set>

class MovieHeadNode {
    friend ostream &operator<<(ostream &Out, const MovieHeadNode &M);
public:
    virtual bool retrieve(string title, string year, MovieNode*&) = 0;

    ~MovieHeadNode();
    string director;
    int totalStock;
    MovieNode* data;
    MovieHeadNode* left;
    MovieHeadNode* right;

    //    virtual void insert(ClassicNode *temp);
//    virtual bool retrieve(const string director, MovieNode*& pos);


//    bool retrieve(const string title, string year, MovieNode *&pos);
public:
    virtual void insert(MovieNode* temp);

//    virtual void makeMHN(string director, int totalStock);
//    MovieHeadNode();
//    MovieHeadNode(string director, int totalStock);
    void setAttributes(string director, int totalStock);
};


#endif //ASS4_MOVIEHEADNODE_H
