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

int main() {

    MovieDB movieDb;

    // get the movie file
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File couldn't be opened" << endl;
        return 0;
    }

    // stores the string of the current line
    string cur_line;

    // continue reading until end of file
    
    for (;;) {

        // read current line
        getline(infile, cur_line);
        if (cur_line.length() == 0) {
            // at the end of file, stop reading
            return 0;//break;
        }


        string temp[6]; // stores movie metadata {category, score, director, title, year, }

        // splits string from the given movie file and stores separated metadata into temp
        for (int a = 0; a < 5; a++) {
            int index = cur_line.find(", ");
            temp[a] = cur_line.substr(0, index);
            cur_line = cur_line.substr(index + 2, cur_line.length() - index);
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

        // TODO: REMOVE PRINTOUT
        for (int g = 0; g < 6; g++) {
            cout << g << " " <<  temp[g] << endl;
        }

        // D and F
        // 0 -> Op, 1 -> Stock, 2 -> Director, 3 -> Title, 4 -> Year
        // C
        // 0 -> Op, 1 -> Stock, 2 -> Director, 3 -> Title, 4 -> Major Actor, 5 -> Year
        // retrieve has not been checked but i like it
        if (temp[0] == "C" || temp[0] == "F" || temp[0] == "D") {

            MovieHeadNode *headNode = new MovieHeadNode();
            if (temp[0] == "C") {
                if (movieDb.retrieve(temp[0], temp[2], headNode)) {
                    MovieNode *m = new MovieNode();
                    // don't know if this is true
                    if (headNode->retrieve(temp[5], temp[5], temp[4], m)) {
                        m->stock += stoi(temp[1]);
                    } else {
                        ClassicNode *c2 = new ClassicNode();
                        c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                        c2->setAttribute(temp[4]);
                        m = c2;
                        headNode->insert(m);
                    }
                } else {
                    
                    headNode = nullptr;

                    Classic *c = new Classic();
                    c->setAttributes(temp[2], 0);

                    MovieNode *m = new MovieNode(); 
                    ClassicNode *c2 = new ClassicNode();
                    c2->setAttributes(temp[3], temp[5], stoi(temp[1]));
                    c2->setAttribute(temp[4]);
                    
                    m = c2;

                    headNode = c;
                    headNode->insert(m);

//                    cout << *movieDb.classicRoot << endl;

//                    cout << *headNode << endl;

//                    cout << movieDb.classicRoot << endl;

                    movieDb.insert(temp[0], headNode);
//                    cout << movieDb.classicRoot << endl;
//                    cout << *movieDb.classicRoot << endl;
//                    movieDb.display();

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

// HERE
        } else {
            cout << "Incorrect Operator - Must Be (C) Classic / (F) Funny / (D) Drama" << endl;
        }

        if (infile.eof()) {
            return 0;//break;
        }
    }
    cout << "Hello World" << endl;
    movieDb.display();
    cout << "Hello World" << endl;

 //  BOOOOOOOp
//    movieDb.classicRoot->display();
//    cout << movieDb << endl;

// HERE
//
//    HashTable table;
//    table.build("data4customers.txt");
//    table.display();

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