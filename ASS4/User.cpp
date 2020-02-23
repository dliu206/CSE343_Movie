//
// Created by david on 2/22/2020.
//

#include "User.h"

User::User(string name) {
    this->name = name;
    this->head = nullptr;
    this->back = nullptr;
}
User::User() {
    this->name = "";
    this->head = nullptr;
    this->back = nullptr;
}

User::~User() {
    Node* current = this->head;

    while (current != nullptr) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}

User::Node::Node(string data) {
    this->data = data;
}


void User::insertHistory(string s) {
    if (this->head == nullptr) {
        this->head = new Node(s);
        this->back = this->head;
        return;
    }
    Node* temp = new Node(s);
    this->back->next = temp;
    this->back = temp;
}

ostream &operator<<(ostream &Out, const User &U) {
    Out << "User Name : " << U.name << endl;
    Out << "User History: " << endl;
    auto* curr = U.head;
    while (curr != nullptr) {
        Out << curr->data << endl;
        curr = curr->next;
    }
    return Out;
}