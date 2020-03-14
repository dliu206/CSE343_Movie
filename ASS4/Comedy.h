//

// ----------------------------------------- Comedy.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface to Comedy

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_COMEDY_H
#define ASS4_COMEDY_H


#include "MovieHeadNode.h"

class Comedy : public MovieHeadNode {
public:
    // Retrieves MovieNodes within data
    bool retrieve(string title, string year, string majorActor, MovieNode*& target);
};


#endif //ASS4_COMEDY_H
