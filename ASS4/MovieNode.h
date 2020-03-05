//
// Created by david on 2/14/2020.
//

#ifndef ASS4_MOVIENODE_H
#define ASS4_MOVIENODE_H
// #include <iostream>
#include <string>

using namespace std;

class MovieNode {
     friend ostream &operator<<(ostream &Out, const MovieNode &M);
protected:

    bool operator>(const MovieNode &M) const;
    bool operator<(const MovieNode &M) const;
    bool operator>=(const MovieNode &M) const;
    bool operator<=(const MovieNode &M) const;
    bool operator==(const MovieNode &M) const;
    bool operator!=(const MovieNode &M) const;

public:
    virtual void display();
    MovieNode* next;
    int stock;
    string year;

//    MovieNode();
//    MovieNode(string title, string year, int stock);
//    ~MovieNode() = default;
    void setAttributes(string title, string year, int stock);

    string title;
};


#endif //ASS4_MOVIENODE_H
