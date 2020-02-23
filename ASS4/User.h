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
    User();
    User(string name);
    ~User();
    string name;
    struct Node {
        Node(string data);
        string data;
        Node* next;
    };
    Node* head;
    Node* back;

    void insertHistory(string s);

};


#endif //ASS4_USER_H
