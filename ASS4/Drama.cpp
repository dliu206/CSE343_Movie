//
// Created by david on 3/4/2020.
//

#include "Drama.h"

bool Drama::retrieve(string title, MovieNode *&target) {
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
