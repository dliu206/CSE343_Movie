//

// ----------------------------------------- MovieNode.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the interface to Movie Node

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_MOVIENODE_H
#define ASS4_MOVIENODE_H
#include <string>

using namespace std;

class MovieNode {
    friend ostream& operator<<(ostream& Out, const MovieNode& M);
protected:

    bool operator>(const MovieNode& M) const;
    bool operator<(const MovieNode& M) const;
    bool operator>=(const MovieNode& M) const;
    bool operator<=(const MovieNode& M) const;
    bool operator==(const MovieNode& M) const;
    bool operator!=(const MovieNode& M) const;

public:
    void setAttributes(string title, string year, int stock);
    virtual void display();
    MovieNode* next;
    string title;
    int stock;
    string year;
};


#endif //ASS4_MOVIENODE_H
