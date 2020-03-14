//

// ----------------------------------------- MovieDB.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of MovieDB

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "MovieDB.h"
using namespace std;

// ------------------------------------ Constructor -----------------------------------------------

// Description

// Constructor: initializes the MovieDB with null roots
// preconditions: n/a
// postconditions: initializes the MovieDB with null roots

// --------------------------------------------------------------------------------------------
MovieDB::MovieDB() {
    this->funnyRoot = nullptr;
    this->dramaRoot = nullptr;
    this->classicRoot = nullptr;
}


// ------------------------------------ Deconstructor -----------------------------------------------

// Description

// Deconstructor: Frees memory from the MovieDB
// preconditions: n/a
// postconditions: Frees memory from the MovieDB

// --------------------------------------------------------------------------------------------
MovieDB::~MovieDB() {
    deleteHelper(funnyRoot);
    deleteHelper(dramaRoot);
    deleteHelper(classicRoot);
}

// ------------------------------------ deleteHelper -----------------------------------------------

// Description

// deleteHelper: Helps free the memory recursively
// preconditions: n/a
// postconditions: Helps free the memory recursively

// --------------------------------------------------------------------------------------------
void MovieDB::deleteHelper(MovieHeadNode* curr) {
    if (curr != nullptr) {
        deleteHelper(curr->left);
        deleteHelper(curr->right);
        delete curr;
    }
}

// ------------------------------------ insert -----------------------------------------------

// Description

// insert: Inserts the MovieHeadNode into a given root (op)
// preconditions: n/a
// postconditions: Inserts the MovieHeadNode into a given root

// --------------------------------------------------------------------------------------------
void MovieDB::insert(string op, MovieHeadNode *&target) {
    MovieHeadNode* curr;
    if (op == "F") {
        if (funnyRoot == nullptr) {
            funnyRoot = target;
            return;
        } else {
            curr = funnyRoot;
        }
    } else if (op == "D") {
        if (dramaRoot == nullptr) {
            dramaRoot = target;
            return;
        } else {
            curr = dramaRoot;
        }
    } else if (op == "C") {
        if (classicRoot == nullptr) {
            classicRoot = target;
            return;
        } else {
            curr = classicRoot;
        }
    } else {
        cout << "Invalid Genre Error - Must Be (F) Funny / (C) Classic / (D) Drama" << endl;
        return;
    }

    while (curr != nullptr) {
        if (curr == target) {
            curr->totalStock += target->totalStock;
            return;
        } else if (target < curr) {
            if (curr->left == nullptr) {
                curr->left = target;
                return;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right == nullptr) {
                curr->right = target;
                return;
            } else {
                curr = curr->right;
            }
        }
    }
}

// ------------------------------------ display -----------------------------------------------

// Description

// display: Writes the whole MovieDB contents to console
// preconditions: n/a
// postconditions: Writes the whole MovieDB contents to console

// --------------------------------------------------------------------------------------------
void MovieDB::display() const {
    cout << "Comedy Root: " << endl;
    displayHelper(funnyRoot);
    cout << endl;
    cout << "Drama Root: " << endl;
    displayHelper(dramaRoot);
    cout << endl;
    cout << "Classic Root: " << endl;
    displayHelper(classicRoot);
    cout << endl;
}

// ------------------------------------ displayHelper -----------------------------------------------

// Description

// displayHelper: Helps write the display recursively to console
// preconditions: n/a
// postconditions: Helps write the display recursively to console

// --------------------------------------------------------------------------------------------
void MovieDB::displayHelper(MovieHeadNode* curr) const {
    if (curr != nullptr) {
        displayHelper(curr->left);
        curr->display();
        displayHelper(curr->right);
    }
}

// ------------------------------------ operator<< -----------------------------------------------

// Description

// operator<<: Writes the contents of MovieDB to console
// preconditions: n/a
// postconditions: Writes the contents of MovieDB to console

// --------------------------------------------------------------------------------------------
ostream &operator<<(ostream &Out, const MovieDB &M) {
    M.display();
    return Out;
}


// ------------------------------------ retrieve -----------------------------------------------

// Description

// retrieve: retrieves the MovieHeadNode from movieDB given precondition information
// preconditions:
// pos is changed if target is found
// For comedy movie retrival (type=F): input1 is year, input2 is title
// For drama movie retrival (type=D): input1 is director, input2 is title
// For classic movie retrival (type=C): input1 is year("date"), input2 is majorActor
// postconditions: retrieves the MovieHeadNode from movieDB given precondition informationn

// --------------------------------------------------------------------------------------------
void MovieDB::retrieve(string type, string input1, string input2, MovieHeadNode*& curr, MovieHeadNode*& pos) {
    if (curr != nullptr) {
        if (type == "F") {
            MovieNode* currentData = curr->data;
            if (currentData->year == input1 && currentData->title == input2) {
                pos = curr;
            }
        }

        if (type == "D") {
            MovieNode* currentData = curr->data;
            if (curr->director == input1 && currentData->title == input2) {
                pos = curr;
            }
        }

        if (type == "C") {
            ClassicNode* currentData = dynamic_cast<ClassicNode*>(curr->data);
            if (currentData->year == input1 && currentData->majorActor == input2) {
                pos = curr;
            }
        }

        retrieve(type, input1, input2, curr->left, pos);
        retrieve(type, input1, input2, curr->right, pos);
    }
}
