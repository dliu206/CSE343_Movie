//

// ----------------------------------------- MovieNode.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of Movie Node

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "MovieNode.h"


// ------------------------------------ operator<< -----------------------------------------------

// Description

// operator<<: Writes contents of Movie Node to console
// preconditions: n/a
// postconditions: Writes contents of Movie Node to console

// --------------------------------------------------------------------------------------------
ostream& operator<<(ostream& Out, const MovieNode& M) {
    Out << "Title: " << M.title << " Year: " << M.year << " Stock: " << M.stock << endl;
    return Out;
}

// ------------------------------------ operator== -----------------------------------------------

// Description

// operator==: Returns T if the other MovieNode is equal to this one, F otherwise
// preconditions: n/a
// postconditions: Returns T if the other MovieNode is equal to this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator==(const MovieNode& m) const {
    return this->title == m.title && this->year == m.year;
}

// ------------------------------------ operator!= -----------------------------------------------

// Description

// operator!=: Returns T if the other MovieNode is not equal to this one, F otherwise
// preconditions: n/a
// postconditions: Returns T if the other MovieNode is not equal to this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator!=(const MovieNode& m) const {
    return !(*this == m);
}

// ------------------------------------ operator< -----------------------------------------------

// Description

// operator<: Returns T if the other Movie Node is greater than this one, F otherwise.
// Compared by title then by year.
// preconditions: n/a
// postconditions: Returns T if the other Movie Node is greater than this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator<(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year < m.year;
    }
    return this->title < m.title;
}

// ------------------------------------ operator<= -----------------------------------------------

// Description

// operator<=: Returns T if the other Movie Node is greater than this one, F otherwise.
// Compared by title then by year.
// preconditions: n/a
// postconditions: Returns T if the other Movie Node is greater than this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator<=(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year <= m.year;
    }
    return this->title <= m.title;
}

// ------------------------------------ operator> -----------------------------------------------

// Description

// operator>: Returns T if the other Movie Node is less than this one, F otherwise.
// Compared by title then by year.
// preconditions: n/a
// postconditions: Returns T if the other Movie Node is less than this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator>(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year > m.year;
    }
    return this->title > m.title;
}


// ------------------------------------ operator>= -----------------------------------------------

// Description

// operator>=: Returns T if the other Movie Node is less than or equal to this one, F otherwise.
// Compared by title then by year.
// preconditions: n/a
// postconditions: Returns T if the other Movie Node is less than or equal to this one, F otherwise

// --------------------------------------------------------------------------------------------
bool MovieNode::operator>=(const MovieNode& m) const {
    if (this->title == m.title) {
        return this->year >= m.year;
    }
    return this->title >= m.title;
}

// ------------------------------------ setAttributes -----------------------------------------------

// Description

// setAttributes: Sets title, year, and stock for this MovieNode
// preconditions: n/a
// postconditions: Sets title, year, and stock for this MovieNode

// --------------------------------------------------------------------------------------------
void MovieNode::setAttributes(string title, string year, int stock) {
    this->title = title;
    this->year = year;
    this->stock = stock;
    this->next = nullptr;
}

// ------------------------------------ display -----------------------------------------------

// Description

// display: Writes contents of Movie Node to console
// preconditions: n/a
// postconditions: Writes contents of Movie Node to console

// --------------------------------------------------------------------------------------------
void MovieNode::display() {
    cout << "Title: " << title << " Year: " << year << " Stock: " << stock << endl;
}