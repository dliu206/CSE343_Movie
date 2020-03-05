#include <iostream>
#include "MovieNode.h"
#include "ClassicNode.h"
#include "MovieDB.h"
#include <fstream>
#include <unordered_map>
#include "User.h"
#include "HashTable.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

using namespace std;

HashTable* buildUserDB() {
    HashTable* table = new HashTable;

    ifstream infile("data4customers.txt");

    if (!infile) {
        cout << "Customer file couldn't be opened" << endl;
        return table;
    }
    string s;
    for (;;) {
        getline(infile, s);
        if (s.length() == 0) {
            break;
        }
        int index = s.find(" ");
        int id = stoi(s.substr(0, index));
        string name = s.substr(index + 1, s.length());

        cout << s << endl;
        if (table->containsKey(id)) {
            cout << "Duplicate customer ID: " << id << endl;
        } else {
            User* temp = new User(id, name);
            table->put(temp);
        }
        if (infile.eof()) {
            break;
        }
    }
    return table;
}

int main() {
    // if you complete copy constructor for MovieDB, you can push this code into a separate method
    MovieDB movieDb;

    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File couldn't be opened" << endl;
        return 0;
    }
    string s;
    for (;;) {
        getline(infile, s);
        if (s.length() == 0) {
            break;
        }

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

        if (temp[0] == "C" || temp[0] == "F" || temp[0] == "D") {
            MovieHeadNode *temp2;
            if (temp[0] == "C") {
                if (movieDb.retrieve(temp[0], temp[2], temp2)) {
//                    cout << 1 << endl;
                    MovieNode *temp3;
                    if (temp2->retrieve(temp[5], temp[4], temp3)) {
//                        cout << 1 << endl;
                        temp3->stock += stoi(temp[1]);
                    } else {
//                        cout << 1 << endl;

                        ClassicNode *c2;
                        c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                        c2->majorActor = temp[4];
                        MovieNode* m = c2;
                        // title year stock

//                        m->setAttributes(temp[3], temp[5], stoi(temp[1]));
//                        m->majorActor = temp[4];
                        temp2->insert(m);
                    }
                } else {
                    temp2 = new Classic;
                    temp2->setAttributes(temp[2], 0);
                    cout << *temp2 << endl;
                    movieDb.insert(temp[0], temp2);
                }
            }
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
        } else {
            cout << "Error Reading Line to add to Movie DB" << endl;
        }

        if (infile.eof()) {
            break;
        }
    }
    movieDb.display();

//    HashTable* table = buildUserDB();
//    table->display();

//    ifstream infile2("data4commands");
//    for(;;) {
//        getline(infile2, s);
//        if (s.length() == 0) {
//            break;
//        }
////        int index = s.find(" ");
//        string op = s.substr(0, 1);
//        if (op == "I") {
//            movieDb.display();
//        } else if (op == "H") {
//            int id = stoi(s.substr(2, s.length()));
//            if (umap.find(id) != umap.end()) {
//                cout << umap.at(id) << endl;
//            } else {
//                // not found
//                cout << "User Does Not Exist" << endl;
//            }
//        } else if (op == "B") {
//            s = s.substr(2, s.length());
//            int index = s.find(" ");
//            int id = stoi(s.substr(0, index));
//            s = s.substr(index + 1, s.length());
//            string dvd = s.substr(0, 1);
//            if (dvd != "D") {
//                // error
//                umap.at(id).insertHistory("Failed attempt to borrow: " + dvd);
//            } else {
//                string type = s.substr(2, 1);
//                if (type == "C") {
//                    // 2 length date
//                    // major actor
//                } else if (type == "D") {
//                    //comma separated director then title
//                } else if (type == "F") {
//                    // comma separated title then year
//                }
//            }
//
//        } else if (op == "R") {
//
//        } else {
//            cout << "Incorrect command" << endl;
//        }
//        if (infile2.eof()) {
//            break;
//        }
//    }


    return 0;
}