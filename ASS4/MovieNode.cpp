//
// Created by david on 2/14/2020.
//

#include <iostream>
#include "MovieNode.h"

ostream& operator<<(ostream& Out, const MovieNode& M) {
    Out << "Title: " << M.title << " Year: " << M.year << " Stock: " << M.stock << endl;
    return Out;
}


//
//MovieNode::MovieNode(string title, string year, int stock) {
//    this->title = title;
//    this->year = year;
//    this->stock = stock;
//    this->next = nullptr;
//}

bool MovieNode::operator==(const MovieNode& m) const {

    return this->title == m.title && this->year == m.year;
}

bool MovieNode::operator!=(const MovieNode& m) const {
    return !(*this == m);
}

bool MovieNode::operator<(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year < m.year;
    }
    return this->title < m.title;
}

bool MovieNode::operator<=(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year <= m.year;
    }
    return this->title <= m.title;
}

bool MovieNode::operator>(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year > m.year;
    }
    return this->title > m.title;
}

bool MovieNode::operator>=(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year >= m.year;
    }
    return this->title >= m.title;
}

void MovieNode::setAttributes(string title, string year, int stock) {
    this->title = title;
    this->year = year;
    this->stock = stock;
    this->next = nullptr;
}

void MovieNode::display() {
    cout << "Title: " << title << " Year: " << year << " Stock: " << stock << endl;
}
