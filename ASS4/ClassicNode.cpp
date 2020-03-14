
//

// ----------------------------------------- ClassicNode.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of ClassicNode Methods

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "ClassicNode.h"


// ------------------------------------ operator<< -----------------------------------------------

// Description

// operator<<: Writes to console using <<
// preconditions: n/a
// postconditions: Writes the nodes information to console

// --------------------------------------------------------------------------------------------
ostream &operator<<(ostream &Out, const ClassicNode &C) {
    Out << "Title: " << C.title << " Year: " << C.year << " Stock: " << C.stock  << " Major Actor: " << C.majorActor;
    return Out;
}

// ------------------------------------ display -----------------------------------------------

// Description

// display: Writes to console
// preconditions: n/a
// postconditions: Writes the nodes information to console

// --------------------------------------------------------------------------------------------
void ClassicNode::display() {
    cout << "Title: " << title << " Year: " << year << " Stock: " << stock  << " Major Actor: " << majorActor << endl;
}


// ------------------------------------ setAttribute -----------------------------------------------

// Description

// setAttribute: Sets the major actor field
// preconditions: n/a
// postconditions: Sets the major actor field

// --------------------------------------------------------------------------------------------
void ClassicNode::setAttribute(string majorActor) {
    this->majorActor = majorActor;
    this->next = nullptr;
}

// ------------------------------------ operator< -----------------------------------------------

// Description

// operator<: Compares if this Classic Node is less than another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node is less than another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator<(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year < C.year;
        }
        return this->title < C.title;
    }
    return this->majorActor < C.majorActor;
}

// ------------------------------------ operator<= -----------------------------------------------

// Description

// operator<=: Compares if this Classic Node is less than or equal to another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node is less than or equal to another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator<=(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year <= C.year;
        }
        return this->title <= C.title;
    }
    return this->majorActor <= C.majorActor;
}


// ------------------------------------ operator> -----------------------------------------------

// Description

// operator>: Compares if this Classic Node is greater than another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node is greater than another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator>(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year > C.year;
        }
        return this->title > C.title;
    }
    return this->majorActor > C.majorActor;
}

// ------------------------------------ operator>= -----------------------------------------------

// Description

// operator>=: Compares if this Classic Node is greater than or equal to another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node is greater than or equal to another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator>=(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year >= C.year;
        }
        return this->title >= C.title;
    }
    return this->majorActor >= C.majorActor;
}


// ------------------------------------ operator== -----------------------------------------------

// Description

// operator==: Compares if this Classic Node is equal to another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node is equal to another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator==(const ClassicNode &C) const {
    return this->title == C.title && this->year == C.year && this->majorActor == C.majorActor;
}


// ------------------------------------ operator== -----------------------------------------------

// Description

// operator==: Compares if this Classic Node isn't equal to another Classic Node
// preconditions: n/a
// postconditions: Compares if this Classic Node isn't equal to another Classic Node

// --------------------------------------------------------------------------------------------
bool ClassicNode::operator!=(const ClassicNode &C) const {
    return !(*this == C);
}



