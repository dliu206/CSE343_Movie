//
// Created by david on 3/4/2020.
//

#ifndef ASS4_COMEDY_H
#define ASS4_COMEDY_H


#include "MovieHeadNode.h"

class Comedy : public MovieHeadNode {
public:
     bool retrieve(string title, string year, MovieNode*& M);
};


#endif //ASS4_COMEDY_H
