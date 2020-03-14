//

// ----------------------------------------- Classic.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface to Classic

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_CLASSIC_H
#define ASS4_CLASSIC_H


#include "MovieHeadNode.h"

class Classic : public MovieHeadNode {
public:
    // Retrieves ClassicNodes within data
    bool retrieve(string title, string year, string majorActor, MovieNode*& target);
};


#endif //ASS4_CLASSIC_H
