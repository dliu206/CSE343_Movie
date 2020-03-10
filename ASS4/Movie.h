//
// Created by david on 3/2/2020.
//

#ifndef ASS4_MOVIE_H
#define ASS4_MOVIE_H
#include "MovieNode.h"
#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
    Movie(string director, string title, string year, int stock);
    bool insert(MovieNode& m);
    void display();

    bool operator<(const Movie& M) const;
    bool operator<=(const Movie& M) const;
    bool operator>(const Movie& M) const;
    bool operator>=(const Movie& M) const;
    bool operator==(const Movie& M) const;
    bool operator!=(const Movie& M) const;
private:
    string director;
    int totalStock;
    Movie* Left;
    Movie* Right;
    MovieNode* Data;
};


#endif //ASS4_MOVIE_H
