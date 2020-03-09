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
    deleteHelper(*funnyRoot);
    deleteHelper(*dramaRoot);
    deleteHelper(*classicRoot);
}

void MovieDB::deleteHelper(MovieHeadNode& curr) {
//    if (curr != nullptr) {
//        deleteHelper(curr->left);
//        deleteHelper(curr->right);
//        delete curr;
//    }
}

void MovieDB::insert(string op, MovieHeadNode *&target) {
    MovieHeadNode* curr;
    if (op == "F") {
        if (funnyRoot == nullptr) {
            funnyRoot = target;
            return;
        } else {
            curr = funnyRoot;
//            insertHelper(*funnyRoot, target);
        }
    } else if (op == "D") {
        if (dramaRoot == nullptr) {
            dramaRoot = target;
            return;
        } else {
            curr = dramaRoot;
//            insertHelper(*dramaRoot, target);
        }
    } else if (op == "C") {
//        cout << *target << endl;
        if (classicRoot == nullptr) {
            classicRoot = target;
            return;
        } else {
            curr = classicRoot;
//            insertHelper(*classicRoot, target);
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

void MovieDB::insertHelper(MovieHeadNode& curr, MovieHeadNode *&target) {
//    MovieHeadNode* cur = classicRoot;
//    MovieHeadNode& c = curr;
//
//    if (curr != nullptr) {
//        if (*curr == target) {
//            curr->totalStock += target->totalStock;
////            delete target; needed?
//        } else if (target < curr) {
//            if (curr->left == nullptr) {
//                curr->left = target;
//            } else {
//                insertHelper(curr->left, target);
//            }
//        } else if (target > curr) {
//            if (curr->right == nullptr) {
//                curr->right = target;
//            } else {
//                insertHelper(curr->right, target);
//            }
//        }
//    }
}

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

void MovieDB::displayHelper(MovieHeadNode* curr) const {
    if (curr != nullptr) {
        displayHelper(curr->left);
//        cout << *curr << endl;
        curr->display();
//        cout << *curr << endl;
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


