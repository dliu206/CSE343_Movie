////
//// Created by david on 2/22/2020.
////
//
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
//User::User() {
//    this->name = "";
//    this->head = nullptr;
//    this->back = nullptr;
//}
//
//User::~User() {
//    Node* current = this->head;
//
//    while (current != nullptr) {
//        Node* temp = current->next;
//        delete current;
//        current = temp;
//    }
//}
//
//User::Node::Node(string data) {
//    this->data = data;
//}
//
//
//void User::insertHistory(string s) {
//    if (this->head == nullptr) {
//        this->head = new Node(s);
//        this->back = this->head;
//        return;
//    }
//    Node* temp = new Node(s);
//    this->back->next = temp;
//    this->back = temp;
//}
//
//ostream &operator<<(ostream &Out, const User &U) {
//    Out << "User Name : " << U.name << endl;
//    Out << "User History: " << endl;
//    auto* curr = U.head;
//    while (curr != nullptr) {
//        Out << curr->data << endl;
//        curr = curr->next;
//    }
//    return Out;
//}

