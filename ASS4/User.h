//
// Created by david on 2/22/2020.
//

#ifndef ASS4_USER_H
#define ASS4_USER_H
#include <string>

using namespace std;

class User {
public:
    string name;
    struct Node {
        string data;
        Node* next;
    };
    Node* head;

};


#endif //ASS4_USER_H
