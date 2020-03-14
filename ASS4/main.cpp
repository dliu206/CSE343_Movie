//

// ----------------------------------------- main.cpp ------------------------------------------------------

// CSS 343 C - Implementation Group 1
// David Liu
// Gabe Acuna

// 3/13/2020

// ----------------------------------------- File Description ----------------------------------------------------------

// The following file shows the execution and testing of HashTable, MovieHeadNode, and MovieNode with all of their
// subclasses that can all be referenced from each of their files.

// ------------------------------------------- Assumptions -------------------------------------------------------------

// We can assume legal input from data4commands, data4customers, and data4movies as specified in prog4_W2020.pdf.

// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "MovieNode.h"
#include "ClassicNode.h"
#include "MovieDB.h"
#include "User.h"
#include "HashTable.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

int main() {

    MovieDB movieDb;

    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File couldn't be opened" << endl;
        return 0;
    }
    string s;
    // Inserts movies as specified in data4movies into movieDb.
    for (;;) {
        getline(infile, s);
        if (s.length() == 0) {
            break;
        }

        // Reads each line and stores fragments into a string array delimited with ', '
        string temp[6];
        for (int a = 0; a < 5; a++) {
            int index = s.find(", ");
            temp[a] = s.substr(0, index);
            s = s.substr(index + 2, s.length() - index);
        }

        string t = temp[4];
        int num = 0;
        int count = 0;
        for (int b = 0; b < 2; b++) {
            num = t.find(' ');
            t = t.substr(num + 1, t.length() - num);
            count += num;
        }
        temp[4] = temp[4].substr(0, count + 1);
        temp[5] = t;

        // D and F
        // 0 -> Op, 1 -> Stock, 2 -> Director, 3 -> Title, 4 -> Year
        // C
        // 0 -> Op, 1 -> Stock, 2 -> Director, 3 -> Title, 4 -> Major Actor, 5 -> Year
        if (temp[0] == "C" || temp[0] == "F" || temp[0] == "D") {

            MovieHeadNode* headNode = new MovieHeadNode;
            if (temp[0] == "C") {
<<<<<<< HEAD
                movieDb.retrieve("C", temp[5], temp[4], movieDb.classicRoot, headNode);
                if (headNode->director != "") {
                    MovieNode* m = new MovieNode;
=======
                if (movieDb.retrieve(temp[0], temp[2], headNode)) {
                    MovieNode* m = new MovieNode;
                    // don't know if this is true
>>>>>>> 4ce6d8968ddddb965dd8f804861bc6a7933c0cd7
                    if (headNode->retrieve(temp[5], temp[5], temp[4], m)) {
                        m->stock += stoi(temp[1]);
                    }
                    else {
                        ClassicNode* c2 = new ClassicNode;
                        c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                        c2->setAttribute(temp[4]);
                        m = c2;
                        headNode->insert(m);
                    }
                } else {
                    Classic* c = new Classic;
                    c->setAttributes(temp[2], 0);
                    MovieNode* m;
                    ClassicNode* c2 = new ClassicNode;
                    c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                    c2->setAttribute(temp[4]);
                    m = c2;
                    headNode = c;
                    headNode->insert(m);
                    movieDb.insert(temp[0], headNode);
                }
            } else if (temp[0] == "F") {
                movieDb.retrieve("F", temp[4], temp[3], movieDb.funnyRoot, headNode);
                if (headNode->director != "") {
                    MovieNode* m = new MovieNode;

                    if (headNode->retrieve(temp[3], temp[4], "", m)) {
                        m->stock += stoi(temp[1]);
                    } else {
<<<<<<< HEAD
                        m->setAttributes(temp[3], temp[4], stoi(temp[1]));
                        headNode->insert(m);
                    }
                } else {
                    Comedy* c = new Comedy;
                    c->setAttributes(temp[2], 0);
                    MovieNode* m = new MovieNode;
                    m->setAttributes(temp[3], temp[4], stoi(temp[1]));
                    headNode = c;
                    headNode->insert(m);
                    movieDb.insert(temp[0], headNode);
                }

            } else if (temp[0] == "D") {
                movieDb.retrieve("D", temp[2], temp[3], movieDb.dramaRoot, headNode);
                if (headNode->director != "") {
                    MovieNode* m = new MovieNode;

                    if (headNode->retrieve(temp[3], temp[4], "", m)) {
                        m->stock += stoi(temp[1]);
                    } else {
                        m->setAttributes(temp[3], temp[4], stoi(temp[1]));
                        headNode->insert(m);
                    }
                } else {
                    Drama* d = new Drama;
                    d->setAttributes(temp[2], 0);

                    MovieNode* m = new MovieNode;
                    m->setAttributes(temp[3], temp[4], stoi(temp[1]));

                    headNode = d;
=======
                        ClassicNode* c2 = new ClassicNode;
                        c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                        c2->setAttribute(temp[4]);
                        m = c2;
                        headNode->insert(m);
                    }
                } else {
                    headNode = nullptr;
                    Classic* c = new Classic;

                    c->setAttributes(temp[2], 0);

                    MovieNode* m = new MovieNode;
                    ClassicNode* c2 = new ClassicNode;
                    c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                    c2->setAttribute(temp[4]);
//                    cout << c2->title << endl;
                    m = c2;

                    headNode = c;
>>>>>>> 4ce6d8968ddddb965dd8f804861bc6a7933c0cd7
                    headNode->insert(m);

                    movieDb.insert(temp[0], headNode);
                }
            }
<<<<<<< HEAD
=======


//            else if (temp[0] == "F") {
//                if (movieDb.retrieve(temp[0], temp[2], temp2)) {
//                    Comedy* c = dynamic_cast<Comedy *>(temp2);
//                    MovieNode* temp3;
//                    if (c->retrieve(temp[3], temp[5], temp3)) {
//                        temp3->stock += stoi(temp[1]);
//                    } else {
//                        MovieNode* m;
//                        m->setAttributes(temp[3], temp[5], stoi(temp[1]));
//                        c->insert(m);
//                    }
//                } else {
//                    temp2->setAttributes(temp[2], 0);
//                    movieDb.insert(temp[0], temp2);
//                }
//
//            } else {
//                if (movieDb.retrieve(temp[0], temp[2], temp2)) {
//                    Drama* drama = dynamic_cast<Drama *>(temp2);
//                    MovieNode* temp3;
//                    if (drama->retrieve(temp[3], temp3)) {
//                        temp3->stock += stoi(temp[1]);
//                    } else {
//                        MovieNode* m;
//                        m->setAttributes(temp[3], temp[5], stoi(temp[1]));
//                        drama->insert(m);
//                    }
//                } else {
//                    temp2->setAttributes(temp[2], 0);
//                    movieDb.insert(temp[0], temp2);
//                }
//            }
//            bool retrieved = false;
//            if (!movieDb.retrieve(temp[0], temp[2], temp2)) {
//                temp2 = new MovieHeadNode(temp[2], 0);
////                retrieved = true;
//            } else {
////                retrieved = true;
//            }
////            auto* temp2 = new MovieHeadNode(temp[2], 0);
//            if (temp[0] == "C") {
//                temp2->insert(new ClassicNode(temp[3], temp[5], stoi(temp[1]), temp[4]));
//            } else if (temp[0] == " F") {
////                temp2->insert(new MovieNode(temp[3], temp[5], stoi(temp[1])));
//                temp2->insert(new ClassicNode(temp[3], temp[5], stoi(temp[1]), ""));
//            } else if (temp[0] == "D") {
//
//            }
//            if (!retrieved) {
//                movieDb.insert(temp[0], temp2);
//            }
//            movieDb.insert(temp[0], temp2);

// HERE
>>>>>>> 4ce6d8968ddddb965dd8f804861bc6a7933c0cd7
        } else {
            cout << "Incorrect Operator - Must Be (C) Classic / (F) Funny / (D) Drama" << endl;
        }
        if (infile.eof()) {
            return 0;
        }
    }
<<<<<<< HEAD

    // HashTable is a HashMap to store Users
    HashTable table;
    table.build("data4customers.txt");
=======
    cout << "Hello World" << endl;
    movieDb.display();

// HERE
>>>>>>> 4ce6d8968ddddb965dd8f804861bc6a7933c0cd7

    // Reads the data4commands and performs transactions given the table and movieDb.
    ifstream infile2("data4commands.txt");
    for(;;) {
        getline(infile2, s);
        if (s.length() == 0) {
            break;
        }

        string op = s.substr(0, 1);
        if (op == "I") {
//            movieDb.display();
        } else if (op == "H") {
//            s = s.substr(2, s.length() - 2);
//            int id;
//            try {
//                id = stoi(s);
//            } catch (...) {
//                cout << "Invalid id" << endl;
//                continue;
//            }
//            User* u;
//            if (table.retrieve(id, u)) {
//                u->display();
//            } else {
//                cout << "User does not exist" << endl;
//            }
        } else if (op == "B" || op == "R") {
            s = s.substr(2);
            string idString = s.substr(0, s.find(" "));
            int id;
     
            try {
                id = stoi(idString);
            } catch (...) {
                cout << "Invalid id: ID is not an integer." << endl;
                continue;
            }
            s = s.substr(s.find(" ") + 1);

            string media = s.substr(0, 1);
            if (media != "D") {
                cout << "Media not supported. Must be type 'D' for DVD." << endl;
                continue;
            }
            s = s.substr(2);

            string type = s.substr(0, 1);
            s = s.substr(2);

            // Classic movie Borrowing or Return
            if (type == "C") {
                string monthString = s.substr(0, 1);
                int month;
                try {
                    month = stoi(monthString);
                }
                catch (...) {
                    cout << "Invalid month input: Month is not an integer." << endl;
                    continue;
                }
                if (month < 1 || month > 12) {
                    cout << "Invalid month input: Month must be 1-12." << endl;
                    continue;
                }
                s = s.substr(s.find(" ") + 1);

                string yearString = s.substr(0, s.find(" "));
                int year;
                try {
                    year = stoi(yearString);
                }
                catch (...) {
                    cout << "Invalid year input: Year is not an integer." << endl;
                    continue;
                }
                // *year 1888 is the year of the first movie ever created.* 
                if (year < 1888) {
                    cout << "Invalid year input: Year must be greater or equal to 1888" << endl;
                    continue;
                }
                s = s.substr(s.find(" ") + 1);

                string majorActor = s;
                string date = monthString + " " + yearString;

                MovieHeadNode* movieHeadNode = new MovieHeadNode;
                ClassicNode* classicMovie;
                movieDb.retrieve("C", date, majorActor, movieDb.classicRoot, movieHeadNode);
                
                // If found, director will not be empty
                if (movieHeadNode->director != "") {
                    classicMovie = dynamic_cast<ClassicNode*>(movieHeadNode->data);
                    
                    // User wants to Borrow a classical movie
                    if (op == "B") {
                        if (classicMovie->stock <= 0) {
                            cout << "Not enough stock for this movie." << endl;
                            // Classical movie exists with another major actor 
                            if (movieHeadNode->totalStock > 0) {
                                cout << "But we do have this movie with another major actor!" << endl;
                            }
                        }
                        else {
                            User* u;
                            if (table.retrieve(id, u)) {
                                classicMovie->stock--;
                                movieHeadNode->totalStock--;
                                u->insertData(classicMovie->title, classicMovie->year,
                                        1, classicMovie->majorActor);
                            }
                            else {
                                cout << "User does not exist." << endl;
                            }
                        }
                    } else { // User wants to Return a classical movie
                        User* u;
                        if (table.retrieve(id, u)) {
                            classicMovie->stock++;
                            movieHeadNode->totalStock++;
                            u->removeData(classicMovie->title, classicMovie->year, classicMovie->majorActor);
                        } else {
                            cout << "User does not exist." << endl;
                        }
                    }
                } else {
                    cout << "Movie does not exist." << endl;
                }
            } else if (type == "F") { // Comedy movie Borrowing or Return 
                string title = s.substr(0, s.find(","));
                s = s.substr(s.find(",") + 2);
                
                string yearString = s;
                int year;
                try {
                    year = stoi(yearString);
                }
                catch (...) {
                    cout << "Invalid year input: Year is not an integer." << endl;
                    continue;
                }
                // *year 1888 is the year of the first movie ever created.* 
                if (year < 1888) {
                    cout << "Invalid year input: Year must be greater or equal to 1888" << endl;
                    continue;
                }

                MovieHeadNode* movieHeadNode = new MovieHeadNode;
                MovieNode* comedyMovie;
                movieDb.retrieve("F", yearString, title, movieDb.funnyRoot, movieHeadNode);

                // If found, director will not be empty
                if (movieHeadNode->director != "") {
                    comedyMovie = movieHeadNode->data;

                    // User wants to Borrow a drama movie
                    if (op == "B") {
                        if (comedyMovie->stock <= 0) {
                            cout << "Not enough stock for this movie." << endl;
                        }
                        else {
                            User* u;
                            if (table.retrieve(id, u)) {
                                comedyMovie->stock--;
                                movieHeadNode->totalStock--;
                                u->insertData(comedyMovie->title, comedyMovie->year, 1, "");
                            }
                            else {
                                cout << "User does not exist." << endl;
                            }
                        }
                    }
                    else { // User wants to Return a drama movie
                        User* u;
                        if (table.retrieve(id, u)) {
                            comedyMovie->stock++;
                            movieHeadNode->totalStock++;
                            u->removeData(comedyMovie->title, comedyMovie->year, "");
                        }
                        else {
                            cout << "User does not exist." << endl;
                        }
                    }
                }
                else {
                    cout << "Movie does not exist." << endl;
                }
            } else if (type == "D") { // Drama movie Borrowing or Return 
                string director = s.substr(0, s.find(","));
                s = s.substr(s.find(",") + 2, s.find(","));

                string title = s;

                MovieHeadNode* movieHeadNode = new MovieHeadNode;
                MovieNode* dramaMovie;
                movieDb.retrieve("D", director, title, movieDb.funnyRoot, movieHeadNode);

                // If found, director will not be empty
                if (movieHeadNode->director != "") {
                    dramaMovie = movieHeadNode->data;

                    // User wants to Borrow a drama movie
                    if (op == "B") {
                        if (dramaMovie->stock <= 0) {
                            cout << "Not enough stock for this movie." << endl;
                        }
                        else {
                            User* u;
                            if (table.retrieve(id, u)) {
                                dramaMovie->stock--;
                                movieHeadNode->totalStock--;
                                u->insertData(dramaMovie->title, dramaMovie->year, 1, "");
                            }
                            else {
                                cout << "User does not exist." << endl;
                            }
                        }
                    }
                    else { // User wants to Return a drama movie
                        User* u;
                        if (table.retrieve(id, u)) {
                            dramaMovie->stock++;
                            movieHeadNode->totalStock++;
                            u->removeData(dramaMovie->title, dramaMovie->year, "");
                        }
                        else {
                            cout << "User does not exist." << endl;
                        }
                    }
                }
                else {
                    cout << "Movie does not exist." << endl;
                }
            }      
        } else {
            cout << "Incorrect command" << endl;
        }
        if (infile2.eof()) {
            break;
        }
    }


    movieDb.display();
    table.display();
    return 0;
}