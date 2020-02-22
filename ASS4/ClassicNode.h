//
// Created by david on 2/14/2020.
//

#ifndef ASS4_CLASSICNODE_H
#define ASS4_CLASSICNODE_H


#include "MovieNode.h"

class ClassicNode : public MovieNode {
    friend ostream &operator<<(ostream &Out, const ClassicNode &C);
public:

    ClassicNode(string title, string year, int stock, string majorActor);
    string majorActor;
    ClassicNode* next;

    bool operator>(const ClassicNode &C) const;
    bool operator<(const ClassicNode &C) const;
    bool operator>=(const ClassicNode &C) const;
    bool operator<=(const ClassicNode &C) const;
    bool operator==(const ClassicNode &C) const;
    bool operator!=(const ClassicNode &C) const;

};


#endif //ASS4_CLASSICNODE_H
