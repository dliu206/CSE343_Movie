//
// Created by david on 2/14/2020.
//

#include <iostream>
#include "MovieDB.h"
using namespace std;

MovieDB::MovieDB() {
    this->funnyRoot = nullptr;
    this->dramaRoot = nullptr;
    this->classicRoot = nullptr;
}

MovieDB::~MovieDB() {
    deleteHelper(funnyRoot);
    deleteHelper(dramaRoot);
    deleteHelper(classicRoot);
}

void MovieDB::deleteHelper(MovieHeadNode *curr) {
    if (curr != nullptr) {
        deleteHelper(curr->left);
        deleteHelper(curr->right);
        delete curr;
    }
}

void MovieDB::insert(string op, MovieHeadNode *target) {
    if (target->director != "" && target->totalStock != 0) {
        if (op == "F") {
            if (funnyRoot == nullptr) {
                funnyRoot = target;
            } else {
                insertHelper(funnyRoot, target);
            }
        } else if (op == "D") {
            if (dramaRoot == nullptr) {
                dramaRoot = target;
            } else {
                insertHelper(dramaRoot, target);
            }
        } else if (op == "C") {
            if (classicRoot == nullptr) {
                classicRoot = target;
            } else {
                insertHelper(classicRoot, target);
            }
        } else {
            cout << "Incorrect Operator Error" << endl;
        }
    }
}

void MovieDB::insertHelper(MovieHeadNode *curr, MovieHeadNode *target) {
    if (curr != nullptr) {
        if (curr == target) {
            curr->totalStock += target->totalStock;
            delete target;
        } else if (target < curr) {
            if (curr->left == nullptr) {
                curr->left = target;
            } else {
                insertHelper(curr->left, target);
            }
        } else if (target > curr) {
            if (curr->right == nullptr) {
                curr->right = target;
            } else {
                insertHelper(curr->right, target);
            }
        }
    }
}

void MovieDB::display() const {
    cout << "Comedy Root: " << endl;
    displayHelper(this->funnyRoot);
    cout << endl;
    cout << "Drama Root: " << endl;
    displayHelper(this->dramaRoot);
    cout << endl;
    cout << "Classic Root: " << endl;
    displayHelper(this->classicRoot);
    cout << endl;
}

void MovieDB::displayHelper(MovieHeadNode *curr) const {
    if (curr != nullptr) {
        displayHelper(curr->left);
        cout << *curr << endl;
        displayHelper(curr->right);
    }
}

bool MovieDB::retrieve(string op, string director, MovieHeadNode*& pos) {
    MovieHeadNode* current;
    if (op == "C") {
        current = this->classicRoot;
    } else if (op == "D") {
        current = this->dramaRoot;
    } else if (op == "F") {
        current = this->funnyRoot;
    } else {
        return false;
    }

    while (current != nullptr) {
        if (current->director == director) {
            pos = current;
            return true;
        } else if (current->director < director) {
            current = current->right;
        } else if (current->director > director) {
            current = current->left;
        }
    }
    return false;
}

ostream &operator<<(ostream &Out, const MovieDB &M) {
    M.display();
    return Out;
}


