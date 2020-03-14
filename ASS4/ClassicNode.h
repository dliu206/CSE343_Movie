//

// ----------------------------------------- ClassicNode.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface for ClassicNode

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_CLASSICNODE_H
#define ASS4_CLASSICNODE_H


#include "MovieNode.h"
// Extends MovieNode
class ClassicNode : public MovieNode {
    friend ostream &operator<<(ostream &Out, const ClassicNode &C);
public:
    // Displays the node
    void display();
    // Sets the major actor attribute
    void setAttribute(string majorActor);
    string majorActor;

    // Operator functions to compare classic nodes.
    bool operator>(const ClassicNode &C) const;
    bool operator<(const ClassicNode &C) const;
    bool operator>=(const ClassicNode &C) const;
    bool operator<=(const ClassicNode &C) const;
    bool operator==(const ClassicNode &C) const;
    bool operator!=(const ClassicNode &C) const;
};


#endif //ASS4_CLASSICNODE_H
