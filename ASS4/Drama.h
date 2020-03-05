//
// Created by david on 3/4/2020.
//

#ifndef ASS4_DRAMA_H
#define ASS4_DRAMA_H


#include "MovieHeadNode.h"

class Drama : public MovieHeadNode {
public:
    bool retrieve(string title, MovieNode*& target);
};


#endif //ASS4_DRAMA_H
