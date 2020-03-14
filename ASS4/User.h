//

// ----------------------------------------- User.h ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows interface for User

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#ifndef ASS4_USER_H
#define ASS4_USER_H
#include <string>
#include "MovieNode.h"

using namespace std;

class User {
public:
    explicit User();
    User(int id, string name);
    ~User();

    bool isEmpty() const;
    void insertData(string title, string year, int stock, string majorActor);
    void removeData(string title, string year, string majorActor);
    void display();

    int id;
    string name;
    string history;
    MovieNode* data;
};


#endif //ASS4_USER_H
