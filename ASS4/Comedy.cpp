//
// Created by david on 3/4/2020.
//

#include "Comedy.h"

bool Comedy::retrieve(string title, string year, MovieNode *&M) {
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
