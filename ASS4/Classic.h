//
// Created by david on 3/4/2020.
//

#ifndef ASS4_CLASSIC_H
#define ASS4_CLASSIC_H


#include "MovieHeadNode.h"

class Classic : public MovieHeadNode {
public:

    bool retrieve(string year, string majorActor, MovieNode*& target);
};


#endif //ASS4_CLASSIC_H