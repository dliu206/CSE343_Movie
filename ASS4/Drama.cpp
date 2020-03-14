//

// ----------------------------------------- Drama.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of the retrieval of Movie Nodes within a Drama binary search tree.

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------

#include "Drama.h"

// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: retrieves the specific MovieNode within a Drama head node.
// preconditions: N/A
// postconditions: returns true/false if the given title and year combination movie node is found
// within this head node and references that pointer to target.

// --------------------------------------------------------------------------------------------
bool Drama::retrieve(string title, string year, string majorActor, MovieNode *&target) {
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        if (curr->title == title) {
            target = curr;
            return true;
        } else {
            curr = curr->next;
        }
    }
    return false;
}
