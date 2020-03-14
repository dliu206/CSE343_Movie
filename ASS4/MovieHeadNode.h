//

// ----------------------------------------- MovieHeadNode.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface to Movie Head Node

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_MOVIEHEADNODE_H
#define ASS4_MOVIEHEADNODE_H


#include "MovieNode.h"
#include "ClassicNode.h"

class MovieHeadNode {
    friend ostream &operator<<(ostream &Out, const MovieHeadNode &M);
public:
    MovieHeadNode();
<<<<<<< HEAD
=======
    bool retrieve(string title, string year, string majorActor, MovieNode*&);
    void display();
>>>>>>> 4ce6d8968ddddb965dd8f804861bc6a7933c0cd7
    ~MovieHeadNode();
    // sets director and total stock
    void setAttributes(string director, int totalStock);
    // inserts movie node into temp;
    virtual void insert(MovieNode* temp);
    // retrieves the movie node
    bool retrieve(string title, string year, string majorActor, MovieNode*&);
    // displays the data
    void display();

    string director;
    int totalStock;
    MovieNode* data;
    MovieHeadNode* left;
    MovieHeadNode* right;

    bool operator==(const MovieHeadNode &M) const;
    bool operator!=(const MovieHeadNode &M) const;
    bool operator<(const MovieHeadNode &M) const;
    bool operator>(const MovieHeadNode &M) const;
};


#endif //ASS4_MOVIEHEADNODE_H