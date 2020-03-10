//
// Created by david on 2/14/2020.
//

#include <iostream>
#include "MovieHeadNode.h"
#include "ClassicNode.h"

void MovieHeadNode::setAttributes(string director, int totalStock) {
    this->director = director;
    this->totalStock = totalStock;
    this->data = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

MovieHeadNode::~MovieHeadNode() {
// ?? doesn't compile if i do this
//    MovieNode* current = this->data;
//    while (current != nullptr) {
//        MovieNode* temp = current->next;
//        delete current;
//        current = temp;
//    }
}

// untested
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

bool MovieHeadNode::retrieve(string title, string year, string majorActor, MovieNode*&) {
    return false;
}

ostream &operator<<(ostream &Out, const MovieHeadNode &M) {
    Out << "Director: " << M.director << " Total Stock: " << M.totalStock << endl << "Data: " << endl;
    MovieNode* current = M.data;
    while (current != nullptr) {
        current->display();
        current = current->next;
    }
    return Out;
}

MovieHeadNode::MovieHeadNode() {

}

void MovieHeadNode::display() {
    cout << "Director : " << director << " Total Stock: " << totalStock << endl;
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        curr->display();
        curr = curr->next;
    }
}

bool MovieHeadNode::operator==(const MovieHeadNode &M) const {
    return this->director == M.director;
}

bool MovieHeadNode::operator!=(const MovieHeadNode &M) const {
    return !(*this == M);
}

bool MovieHeadNode::operator<(const MovieHeadNode &M) const {
    return this->director < M.director;
}

bool MovieHeadNode::operator>(const MovieHeadNode &M) const {
    return this->director > M.director;
}

