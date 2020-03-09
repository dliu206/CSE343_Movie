//
// Created by david on 2/14/2020.
//

#ifndef ASS4_CLASSICNODE_H
#define ASS4_CLASSICNODE_H


#include "MovieNode.h"

class ClassicNode : public MovieNode {
    friend ostream &operator<<(ostream &Out, const ClassicNode &C);
public:
    void display();
    void setAttribute(string majorActor);
//    void setMajorActor(string majorActor);
    string majorActor;

    bool operator>(const ClassicNode &C) const;
    bool operator<(const ClassicNode &C) const;
    bool operator>=(const ClassicNode &C) const;
    bool operator<=(const ClassicNode &C) const;
    bool operator==(const ClassicNode &C) const;
    bool operator!=(const ClassicNode &C) const;

};


#endif //ASS4_CLASSICNODE_H
