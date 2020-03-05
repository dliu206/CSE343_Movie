//
// Created by david on 2/14/2020.
//

#include <iostream>
#include "ClassicNode.h"


ostream &operator<<(ostream &Out, const ClassicNode &C) {
    Out << "Title: " << C.title << " Year: " << C.year << " Stock: " << C.stock  << " Major Actor: " << C.majorActor;
    return Out;
}
void ClassicNode::display() {
    cout << "Title: " << title << " Year: " << year << " Stock: " << stock  << " Major Actor: " << majorActor;
}
//ClassicNode::ClassicNode(string title, string year, int stock, string majorActor) : MovieNode(title, year, stock) {
//    this->majorActor = majorActor;
//    this->next = nullptr;
//}


bool ClassicNode::operator<(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year < C.year;
        }
        return this->title < C.title;
    }
    return this->majorActor < C.majorActor;
}

bool ClassicNode::operator<=(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year <= C.year;
        }
        return this->title <= C.title;
    }
    return this->majorActor <= C.majorActor;
}

bool ClassicNode::operator>(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year > C.year;
        }
        return this->title > C.title;
    }
    return this->majorActor > C.majorActor;
}

bool ClassicNode::operator>=(const ClassicNode &C) const {
    if (this->majorActor == C.majorActor) {
        if (this->title == C.title) {
            return this->year >= C.year;
        }
        return this->title >= C.title;
    }
    return this->majorActor >= C.majorActor;
}

bool ClassicNode::operator==(const ClassicNode &C) const {
    return this->title == C.title && this->year == C.year && this->majorActor == C.majorActor;
}

bool ClassicNode::operator!=(const ClassicNode &C) const {
    return !(*this == C);
}

void ClassicNode::setMajorActor(string majorActor) {
    this->majorActor = majorActor;
}

//ClassicNode::ClassicNode(string majorActor) {
//    this->majorActor = majorActor;
//}


