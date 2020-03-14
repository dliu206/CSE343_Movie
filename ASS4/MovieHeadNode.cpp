//

// ----------------------------------------- MovieHeadNode.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of MovieHeadNode

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "MovieHeadNode.h"
#include "ClassicNode.h"

// ------------------------------------ Constructor -----------------------------------------------

// Description

// Constructor: initializes the MovieHeadNode with an empty director and 0 stock.
// preconditions: n/a
// postconditions: initializes the MovieHeadNode with an empty director and 0 stock.

// --------------------------------------------------------------------------------------------
MovieHeadNode::MovieHeadNode() {
    director = "";
    totalStock = 0;
}

// ------------------------------------ Deconstructor -----------------------------------------------

// Description

// Deconstructor: Frees memory allocated by Movie Head Node
// preconditions: n/a
// postconditions: Frees memory allocated by Movie Head Node

// --------------------------------------------------------------------------------------------
MovieHeadNode::~MovieHeadNode() {
    MovieNode* current = this->data;
    while (current != nullptr) {
        MovieNode* temp = current->next;
        delete current;
        current = temp;
    }
}

// ------------------------------------ setAttributes -----------------------------------------------

// Description

// setAttributes: Sets the director, total stock, and data values with nullptr.
// preconditions: n/a
// postconditions: Sets the director, total stock, and data values with nullptr.

// --------------------------------------------------------------------------------------------
void MovieHeadNode::setAttributes(string director, int totalStock) {
    this->director = director;
    this->totalStock = totalStock;
    this->data = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

// ------------------------------------ insert -----------------------------------------------

// Description

// insert: Inserts a Movie Node into data
// preconditions: n/a
// postconditions: Inserts a Movie Node into data

// --------------------------------------------------------------------------------------------
void MovieHeadNode::insert(MovieNode *temp) {
    totalStock += temp->stock;
    MovieNode* current = this->data;
    if (this->data == nullptr) {
        this->data = temp;
        return;
    } else if (temp < current) {
        temp->next = current;
        this->data = temp;
        return;
    } else if (temp == current) {
        current->stock += temp->stock;
        return;
    }

    while (current->next != nullptr) {
        if (temp < current->next) {
            temp->next = current->next;
            current->next = temp->next;
            return;
        } else if (temp == current->next) {
            current->next->stock += temp->stock;
            return;
        }
        current = current->next;
    }
    current->next = temp;
}

// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: For Classic, Drama, and Comedy interface method execution
// preconditions: N/A
// postconditions: N/A

// --------------------------------------------------------------------------------------------
bool MovieHeadNode::retrieve(string title, string year, string majorActor, MovieNode*&) {
    return false;
}

// ------------------------------------ operator<< -----------------------------------------------

// Description

// operator<<: Writes contents of MovieHeadNode to console
// preconditions: N/A
// postconditions: Writes contents of MovieHeadNode to console

// --------------------------------------------------------------------------------------------
ostream &operator<<(ostream &Out, const MovieHeadNode &M) {
    Out << "Director: " << M.director << " Total Stock: " << M.totalStock << endl << "Data: " << endl;
    MovieNode* current = M.data;
    while (current != nullptr) {
        current->display();
        current = current->next;
    }
    return Out;
}

// ------------------------------------ display -----------------------------------------------

// Description

// display: Writes contents of MovieHeadNode to console
// preconditions: N/A
// postconditions: Writes contents of MovieHeadNode to console

// --------------------------------------------------------------------------------------------
void MovieHeadNode::display() {
    cout << "Director : " << director << " Total Stock: " << totalStock << endl;
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        curr->display();
        curr = curr->next;
    }
}

// ------------------------------------ operator== -----------------------------------------------

// Description

// operator==: Returns T if the other MovieHeadNode is equal to this one, F otherwise
// preconditions: N/A
// postconditions: Returns T if the other MovieHeadNode is equal to this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieHeadNode::operator==(const MovieHeadNode &M) const {
    return this->director == M.director;
}

// ------------------------------------ operator!= -----------------------------------------------

// Description

// operator!=: Returns T if the other MovieHeadNode is not equal to this one, F otherwise
// preconditions: N/A
// postconditions: Returns T if the other MovieHeadNode is not equal to this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieHeadNode::operator!=(const MovieHeadNode &M) const {
    return !(*this == M);
}

// ------------------------------------ operator< -----------------------------------------------

// Description

// operator<: Returns T if this MovieHeadNode is less than the other MovieHeadNode, F otherwise
// preconditions: N/A
// postconditions: Returns T if this MovieHeadNode is less than the other MovieHeadNode, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieHeadNode::operator<(const MovieHeadNode &M) const {
    return this->director < M.director;
}

// ------------------------------------ operator> -----------------------------------------------

// Description

// operator>: Returns T if this MovieHeadNode is greater than the other MovieHeadNode, F otherwise
// preconditions: N/A
// postconditions: Returns T if this MovieHeadNode is greater than the other MovieHeadNode, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieHeadNode::operator>(const MovieHeadNode &M) const {
    return this->director > M.director;
}

