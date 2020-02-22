#include <iostream>
#include "MovieNode.h"
#include "ClassicNode.h"
#include "MovieDB.h"
#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<int, string> buildUserDB() {
    unordered_map<int, string> umap;
    ifstream infile("data4customers.txt");

    if (!infile) {
        cout << "Customer file couldn't be opened" << endl;
        return umap;
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
        // not found
        if (umap.find(id) != umap.end()) {
            cout << "Duplicate customer ID: " << id << endl;
        } else {
            umap[id] = name;
        }

        if (infile.eof()) {
            break;
        }
    }

    return umap;
}

void displayUserDB(unordered_map<int, string> umap) {
    unordered_map<int, string> :: iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
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
            MovieHeadNode* temp2;
            bool retrieved = false;
            if (!movieDb.retrieve(temp[0], temp[2], temp2)) {
                temp2 = new MovieHeadNode(temp[2], 0);
//                retrieved = true;
            } else {
                retrieved = true;
            }
//            auto* temp2 = new MovieHeadNode(temp[2], 0);
            if (temp[0] == "C") {
                temp2->insert(new ClassicNode(temp[3], temp[5], stoi(temp[1]), temp[4]));
            } else {
//                temp2->insert(new MovieNode(temp[3], temp[5], stoi(temp[1])));
                temp2->insert(new ClassicNode(temp[3], temp[5], stoi(temp[1]), ""));
            }
            if (!retrieved) {
                movieDb.insert(temp[0], temp2);
            }
//            movieDb.insert(temp[0], temp2);
        } else {
            cout << "Error Reading Line to add to Movie DB" << endl;
        }

        if (infile.eof()) {
            break;
        }
    }
    movieDb.display();

    unordered_map<int, string> umap = buildUserDB();
//    displayUserDB(umap);

    ifstream infile2("data4commands");
    for(;;) {
        getline(infile2, s);
        if (s.length() == 0) {
            break;
        }
//        int index = s.find(" ");
        string op = s.substr(0, 1);
        if (op == "I") {

        } else if (op == "H") {

        } else if (op == "B") {

        } else if (op == "R") {

        } else {
            cout << "Incorrect command" << endl;
        }
        if (infile2.eof()) {
            break;
        }
    }


    return 0;
}