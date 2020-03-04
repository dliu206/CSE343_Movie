//
// Created by david on 2/22/2020.
//

#ifndef ASS4_USER_H
#define ASS4_USER_H
#include <string>

using namespace std;

class User {
    friend ostream &operator<<(ostream &Out, const User &U);
public:
    explicit User();
    User(int id, string name);

    bool isEmpty() const;
    void insertHistory(string s);

    int id;
    string name;
    string history;
};


#endif //ASS4_USER_H
