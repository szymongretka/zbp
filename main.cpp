#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "SplayTree.cpp"
//#include "SplaySet.h"
#include "SplayMap.cpp"
#include "SplaySet.cpp"

using namespace std;

void DisplayMapFindDuration(const string& key, map<string, string> m) {
    auto findStartClock = chrono::high_resolution_clock::now();

    m.find(key);

    auto findEndClock = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span3 = chrono::duration_cast<chrono::duration<double>>(findEndClock - findStartClock);

    cout << "duration for finding in normal map: " << time_span3.count() << endl;
}

void DisplayMapInsertDuration(const vector<string>& english_dictionary_vec, map<string, string> m) {
    auto insertStartClock = chrono::high_resolution_clock::now();

    for (const string& i : english_dictionary_vec) {
        m.insert(pair<string,string>(i, i));
    }

    auto insertEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(insertEndClock - insertStartClock);
    cout << "duration for inserting into normal map: " << time_span.count() << endl;
}


void DisplayDeleteInNormalSetDuration(const string& key, set<string> set) {
    auto start = chrono::high_resolution_clock::now();
    set.erase(key);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "duration for deleting in normal set: " << time_span.count() << endl;
}

void DisplaySetInsertDuration(const vector<string>& english_dictionary_vec, set<string> set) {
    auto insertStartClock = chrono::high_resolution_clock::now();

    for (const string& i : english_dictionary_vec) {
        set.insert(i);
    }

    auto insertEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(insertEndClock - insertStartClock);
    cout << "duration for inserting into normal set: " << time_span.count() << endl;
}

void DisplaySetSingleInsertDuration(string key, set<string> set) {
    auto insertStartClock = chrono::high_resolution_clock::now();

    set.insert(key);

    auto insertEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(insertEndClock - insertStartClock);
    cout << "duration for inserting into normal set 2: " << time_span.count() << endl;
}



void DisplaySetFindDuration(const string& key, set<string> set) {
    auto findStartClock = chrono::high_resolution_clock::now();

    set.find(key);

    auto findEndClock = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span3 = chrono::duration_cast<chrono::duration<double>>(findEndClock - findStartClock);

    cout << "duration for finding in normal set: " << time_span3.count() << endl;
}

void DisplaySetClearDuration(set<string> set) {
    auto start = chrono::high_resolution_clock::now();

    set.clear();

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span3 = chrono::duration_cast<chrono::duration<double>>(start - end);

    cout << "duration for clearing in normal set: " << time_span3.count() << endl;
}

int main() {
////==============================CREATING INITIAL TREE=======================================


    set<string> set;
    vector<string> english_dictionary_vec;
    SplaySet<string> splaySet;

    ifstream file("/home/szymek/CLionProjects/splay2/english.dic");

    string line;
    while (getline(file, line)) {
        english_dictionary_vec.push_back(line.c_str());
    }
    file.close();

    DisplaySetInsertDuration(english_dictionary_vec, set);

    DisplaySetSingleInsertDuration("testing\r", set);

    ////Insert into Splay set
    auto insertStartClock2 = chrono::high_resolution_clock::now();
    for (const string& i : english_dictionary_vec) {
        splaySet.insert(i);
    }
    auto insertEndClock2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span2 = chrono::duration_cast<chrono::duration<double>>(insertEndClock2 - insertStartClock2);
    cout << "duration for inserting into splay set: " << time_span2.count() << endl;

    ////Insert into Splay set2
    auto insertStartClock3 = chrono::high_resolution_clock::now();
    splaySet.insert("testing\r");
    auto insertEndClock3 = chrono::high_resolution_clock::now();
    chrono::duration<double> insert_time_span = chrono::duration_cast<chrono::duration<double>>(insertEndClock3 - insertStartClock3);
    cout << "duration for inserting into splay set 2: " << insert_time_span.count() << endl;

    //// Find in normal set
    DisplaySetFindDuration("incipience\r", set);

    //// Find in Splay set
    auto findStartClock = chrono::high_resolution_clock::now();
    splaySet.find("sunshines\r");
    auto findEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span3 = chrono::duration_cast<chrono::duration<double>>(findEndClock - findStartClock);
    cout << "duration for finding in splay set: " << time_span3.count() << endl;


    //// Find in Splay set 2
    auto findStartClock2 = chrono::high_resolution_clock::now();
    splaySet.find("youngly\r");
    auto findEndClock2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span4 = chrono::duration_cast<chrono::duration<double>>(findEndClock2 - findStartClock2);
    cout << "duration for finding in splay set 2: " << time_span4.count() << endl;

    //// Find in Splay set 3
    auto findStartClock3 = chrono::high_resolution_clock::now();
    splaySet.find("youngness\r");
    auto findEndClock3 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span5 = chrono::duration_cast<chrono::duration<double>>(findEndClock3 - findStartClock3);
    cout << "duration for finding in splay set 3: " << time_span5.count() << endl;


    ////Delete in normal set
    DisplayDeleteInNormalSetDuration("incipiency\r", set);

    cout << "size before deletion: " << splaySet.size() << endl;

    ////Delete in splay set
    auto deleteStartClock = chrono::high_resolution_clock::now();
    splaySet.erase("whale\r");
    auto deleteEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> delete_time_span = chrono::duration_cast<chrono::duration<double>>(deleteEndClock - deleteStartClock);
    cout << "duration for deleting in splay set: " << delete_time_span.count() << endl;

    cout << "size after deletion: " << splaySet.size() << endl;

    cout << "is empty: " << splaySet.empty() << endl;

    cout << "max size for splay set: " << splaySet.max_size() << endl;

    DisplaySetClearDuration(set);

    ////Clear splay set
    auto clearStartClock = chrono::high_resolution_clock::now();
    splaySet.clear();
    auto clearEndClock = chrono::high_resolution_clock::now();
    chrono::duration<double> clear_time_span = chrono::duration_cast<chrono::duration<double>>(clearEndClock - clearStartClock);
    cout << "duration for clearing splay set: " << clear_time_span.count() << endl;


    cout << "size after clear: " << splaySet.size() << endl;
    cout << "is empty: " << splaySet.empty() << endl;


    auto comp_func = splaySet.key_comp();

    cout << "is aaab less than aaa: " << comp_func("aaab", "aaa") << endl;

    ////MAP
    cout << "========== MAP ============" << endl;

    map<string, string> map;

    SplayMap<string, string> splayMap;

    DisplayMapInsertDuration(english_dictionary_vec, map);

    DisplayMapFindDuration("incipience\r", map);

    ////Insert into Splay map
    auto insertMapStart = chrono::high_resolution_clock::now();
    for (const string& i : english_dictionary_vec) {
        splayMap.insert(pair<string, string>(i, i));
    }
    auto insertMapEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> map_time_insert_span = chrono::duration_cast<chrono::duration<double>>(insertMapEnd - insertMapStart);
    cout << "duration for inserting into splay map: " << map_time_insert_span.count() << endl;

    //// Find in Splay map
    auto findStartClockMap = chrono::high_resolution_clock::now();
    pair<string, string> str = splayMap.find("zymurgy\r");
    cout << str.first << endl;
    auto findEndClockMap = chrono::high_resolution_clock::now();
    chrono::duration<double> map_insert_time_span = chrono::duration_cast<chrono::duration<double>>(findEndClockMap - findStartClockMap);
    cout << "duration for finding in splay map: " << map_insert_time_span.count() << endl;


    return 0;
}


//    splaySet.insert(3);
//    splaySet.insert(39);
//    splaySet.insert(87);
//    splaySet.insert(7);
//    splaySet.insert(22);
//    splaySet.insert(42);
//    splaySet.insert(20);
//
//    cout << "In Splay Tree Diagrams, ??????????????? denotes a right child and ??????????????? denotes a left child" << endl
//              << endl;
//    //this will print out a diagram of the tree
//    cout << "INITIAL SPLAY TREE:" << endl << endl;
//    splaySet.printTree();
//
//
//////=============SPLAY TREE INSERTION TEST==============
//    splaySet.insert(10);
//    cout << endl << endl << "AFTER INSERTING 10:" << endl << endl;
//    splaySet.printTree();
//
//////==============SPLAY TREE SEARCH TEST============
//    splaySet.find(42);
//    cout << endl << endl << "AFTER SEARCHING FOR 42:" << endl << endl;
//    splaySet.printTree();
//
//////=========SPLAY TREE DELETE TEST===========
//
////    splaySet.deleteNode(22);
////    cout << endl << endl <<"AFTER DELETING 22:"<< endl << endl;
////    printTree(splayTree1);
//
//    cout << "ITERATOR!!!"  << endl;
//    for (auto it = splaySet.begin(); it != splaySet.end(); ++it) {
//        cout << ' ' << it->data;
//    }
//
//    cout << endl;
//
//    cout << "ITERATOR BACKWARDS!!!"  << endl;
//    for (auto it = splaySet.end(); it != splaySet.begin(); --it) {
//        cout << ' ' << it->data;
//    }