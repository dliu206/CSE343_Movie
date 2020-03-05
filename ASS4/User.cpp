////
//// Created by david on 2/22/2020.
////
//
#include <iostream>
#include "User.h"
//
User::User() {

    this->id = -1;
    this->name = "";
    this->history = "";
}

User::User(int id, string name) {
    this->id = id;
    this->name = name;
    this->history = "";
}

void User::insertHistory(string s) {
    this->history += s + "\n";
}

bool User::isEmpty() const {
    return this->id == -1 && this->name == "" && this->history == "";
}

ostream &operator<<(ostream &Out, const User &U) {
    Out << "User's ID: " << U.id << endl;
    Out << "User's Name: " << U.name << endl;
    Out << "User's History: " << U.history << endl;
    return Out;
}

void User::display() {
    cout << "User's ID: " << id << endl;
    cout << "User's Name: " << name << endl;
    cout << "User's History: " << history << endl;
}
