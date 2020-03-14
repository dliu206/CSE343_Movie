//

// ----------------------------------------- User.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the implementation of User

// ------------------------------------------- Assumptions -------------------------------------------------------------

// N/A

// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "User.h"
#include "ClassicNode.h"

// ------------------------------------ Constructor -----------------------------------------------

// Description

// Constructor: Constructs a User with empty data
// preconditions: n/a
// postconditions: Constructs a User with empty data

// --------------------------------------------------------------------------------------------
User::User() {
    this->data = nullptr;
    this->id = -1;
    this->name = "";
    this->history = "";
}

// ------------------------------------ Deconstructor -----------------------------------------------

// Description

// Deconstructor: Frees memory allocated by User data
// preconditions: n/a
// postconditions: Frees memory allocated by User data

// --------------------------------------------------------------------------------------------
User::~User() {
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        MovieNode* temp = curr->next;
        delete curr;
        curr = temp;
    }
}

// ------------------------------------ Constructor -----------------------------------------------

// Description

// Constructor: Sets the id and name to the User
// preconditions: n/a
// postconditions: Sets the id and name to the User

// --------------------------------------------------------------------------------------------
User::User(int id, string name) {
    this->data = nullptr;
    this->id = id;
    this->name = name;
    this->history = "";
}

// ------------------------------------ isEmpty() -----------------------------------------------

// Description

// isEmpty: Returns T/F if the User has any data
// preconditions: n/a
// postconditions: Returns T/F if the User has any data

// --------------------------------------------------------------------------------------------
bool User::isEmpty() const {
    return this->id == -1 && this->name == "" && this->history == "";
}

// ------------------------------------ display() -----------------------------------------------

// Description

// display: Write the contents of the User to console
// preconditions: n/a
// postconditions: Write the contents of the User to console

// --------------------------------------------------------------------------------------------
void User::display() {
    cout << "User's ID: " << id << endl;
    cout << "User's Name: " << name << endl;
    cout << "User's History: " << endl;
    cout << history << endl;
    cout << "User's Data: " << endl;
    MovieNode* curr = this->data;
    while (curr != nullptr) {
        curr->display();
        curr = curr->next;
    }
    cout << endl;
}

// ------------------------------------ insertData -----------------------------------------------

// Description

// insertData: Inserts a MovieNode into data into User or increments stock if it already exists and adds it to history
// preconditions: n/a
// postconditions: Inserts a MovieNode into data into User or increments stock if
// it already exists and adds it to history

// --------------------------------------------------------------------------------------------
void User::insertData(string title, string year, int stock, string majorActor) {
    MovieNode* curr = data;
    if (curr == nullptr) {
        if (majorActor == "") {
            MovieNode* temp = new MovieNode;
            temp->setAttributes(title, year, stock);
            history += "Inserted Movie: Title: " + title + " Year: " + year + '\n';
            data = temp;
        } else {
            ClassicNode* temp = new ClassicNode;
            temp->setAttributes(title, year, stock);
            temp->setAttribute(majorActor);
            history += "Inserted Movie: Title: " + title + " Year: " + year + " Major Actor: " + majorActor + '\n';
            data = temp;
        }
        return;
    }

    while (curr->next != nullptr) {
        if (majorActor == "") {
            if (title == curr->title && year == curr->year) {
                curr->stock += stock;
                history += "Inserted Movie: Title: " + title + " Year: " + year + '\n';
                return;
            }
        } else {
            ClassicNode* t = static_cast<ClassicNode *>(curr);
            if (title == curr->title && year == curr->year && majorActor == t->majorActor) {
                curr->stock += stock;
                history += "Inserted Movie: Title: " + title + " Year: " + year + " Major Actor: " + majorActor + '\n';
                return;
            }
        }
        curr = curr->next;
    }

    if (majorActor == "") {
        MovieNode* temp = new MovieNode;
        temp->setAttributes(title, year, stock);
        curr->next = temp;
        history += "Inserted Movie: Title: " + title + " Year: " + year + '\n';
    } else {
        ClassicNode* temp = new ClassicNode;
        temp->setAttributes(title, year, stock);
        temp->setAttribute(majorActor);
        curr->next = temp;
        history += "Inserted Movie: Title: " + title + " Year: " + year + " Major Actor: " + majorActor + '\n';
    }
}

// ------------------------------------ removeData -----------------------------------------------

// Description

// removeData: Removes a stock from data in User and adds it to history
// preconditions: n/a
// postconditions: Removes a stcok from data in User and adds it to history

// --------------------------------------------------------------------------------------------
void User::removeData(string title, string year, string majorActor) {
    MovieNode* curr = data;
    while (curr != nullptr) {
        if (majorActor == "") {
            if (curr->title == title && curr->year == year) {
                if (curr->stock > 0) {
                    curr->stock--;
                    history += "Removed Movie: " + title + " Year: " + year + "\n";
                    return;
                } else {
                    history += "Doesn't have Movie: Title " + title + " Year: " + year + " to return.\n";
                }
                return;
            }
        } else {
            ClassicNode* temp = static_cast<ClassicNode *>(curr);
            if (temp->title == title && curr->year == year && temp->majorActor == majorActor) {
                if (curr->stock > 0) {
                    curr->stock--;
                    history += "Removed Movie: " + title + " Year: " + year + " Major Actor: " + majorActor + "\n";
                    return;
                } else {
                    history += "Doesn't have Movie: Title " + title + " Year: " + year +
                            " Major Actor " + majorActor + " to return.\n";
                }
                return;
            }
        }
        curr = curr->next;
    }
    if (majorActor == "") {
        history += "Doesn't have Movie: Title " + title + " Year: " + year + " to return.\n";
    } else {
        history += "Doesn't have Movie: Title " + title + " Year: " + year +
                   " Major Actor " + majorActor + " to return.\n";
    }
}


