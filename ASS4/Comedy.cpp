//

// ----------------------------------------- Comedy.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of the retrieval of Movie Nodes within a Comedy binary search tree.

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#include "Comedy.h"


// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: retrieves the specific MovieNode within a Comedy head node.
// preconditions: N/A
// postconditions: returns true/false if the given title and year combination movie node is found
// within this head node and references that pointer to target.

// --------------------------------------------------------------------------------------------
bool Comedy::retrieve(string title, string year, string majorActor, MovieNode *&M) {
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        if (curr->title == title && curr->year == year) {
            M = curr;
            return true;
        } else {
            curr = curr->next;
        }
    }
    return false;
}
