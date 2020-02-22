//
// Created by david on 2/14/2020.
//

#include <iostream>
#include "MovieHeadNode.h"
#include "ClassicNode.h"

// move?
MovieHeadNode::MovieHeadNode(string director, int totalStock) {
    this->director = director;
    this->totalStock = totalStock;
    this->data = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

MovieHeadNode::MovieHeadNode() {
    this->director = "";
    this->totalStock = 0;
    this->data = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

MovieHeadNode::~MovieHeadNode() {
    MovieNode* current = this->data;

    while (current != nullptr) {
        MovieNode* temp = current->next;
        delete current;
        current = temp;
    }
}

// untested
//void MovieHeadNode::insert(MovieNode *temp) {
//    totalStock += temp->stock;
//    MovieNode* current = this->data;
//    if (this->data == nullptr) {
//        this->data = temp;
//        return;
//    } else if (temp < current) {
//        temp->next = current;
//        this->data = temp;
//        return;
//    } else if (temp == current) {
//        current->stock += temp->stock;
//        return;
//    }
//
//    while (current->next != nullptr) {
//        if (temp < current->next) {
//            temp->next = current->next;
//            current->next = temp->next;
//            return;
//        } else if (temp == current->next) {
//            current->next->stock + temp->stock;
//            return;
//        }
//        current = current->next;
//    }
//    current->next = temp;
//}

void MovieHeadNode::insert(ClassicNode *temp) {
//    cout << typeid(temp).name() << endl;
    totalStock += temp->stock;
    ClassicNode* current = this->data;
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
            current->next->stock + temp->stock;
            return;
        }
        current = current->next;
    }
    current->next = temp;
}

// untested
//bool MovieHeadNode::retrieve(const string director, MovieNode *&pos) {
//    MovieNode* current = this->data;
//
//    while (current != nullptr) {
//        if (*current == node) {
//            pos = current;
//            return true;
//        }
//        if (*current > node) {
//            return false;
//        }
//        current = current->next;
//    }
//    return false;
//}

ostream &operator<<(ostream &Out, const MovieHeadNode &M) {
    Out << "Director: " << M.director << " Total Stock: " << M.totalStock << endl << "Data: " << endl;
    ClassicNode* current = M.data;
    while (current != nullptr) {
        Out << *current << endl;
        current = current->next;
    }
    return Out;
}


