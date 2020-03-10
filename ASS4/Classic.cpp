//
// Created by david on 3/4/2020.
//

#include "Classic.h"

bool Classic::retrieve(string title, string year, string majorActor, MovieNode *&target) {
    ClassicNode* curr = static_cast<ClassicNode *>(this->data);
    while (curr != nullptr) {
        if (curr->title == title && curr->year == year && curr->majorActor == majorActor) {
            target = curr;
            return true;
        } else {
            curr = static_cast<ClassicNode *>(curr->next);
        }
    }
    return false;
}
