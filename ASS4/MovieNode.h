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
public:

    MovieNode();
    MovieNode(string title, string year, int stock);
    ~MovieNode() = default;

    string title;
    string year;
    int stock;
    MovieNode* next;

    bool operator>(const MovieNode &M) const;
    bool operator<(const MovieNode &M) const;
    bool operator>=(const MovieNode &M) const;
    bool operator<=(const MovieNode &M) const;
    bool operator==(const MovieNode &M) const;
    bool operator!=(const MovieNode &M) const;
};


#endif //ASS4_MOVIENODE_H
