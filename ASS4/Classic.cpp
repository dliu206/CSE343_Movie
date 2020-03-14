//

// ----------------------------------------- Classic.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of the retrieval of ClassicNodes within a Classic binary search tree.

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------

#include "Classic.h"


// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: retrieves the specific MovieNode within a Classic head node.
// preconditions: N/A
// postconditions: returns true/false if the given title, year, and major actor combination classic node is found
// within this head node and references that pointer to target.

// --------------------------------------------------------------------------------------------
bool Classic::retrieve(string title, string year, string majorActor, MovieNode *&target) {
    ClassicNode* curr = static_cast<ClassicNode *>(this->data);
    while (curr != nullptr) {
        if (title == "") {
            if (curr->year == year && curr->majorActor == majorActor) {
                target = curr;
                return true;
            }
        } else if (curr->title == title && curr->year == year && curr->majorActor == majorActor) {
            target = curr;
            return true;
        } else {
            curr = static_cast<ClassicNode *>(curr->next);
        }
    }
    return false;
}
