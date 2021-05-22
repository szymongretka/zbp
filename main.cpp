#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "SplayTree.cpp"
//#include "SplaySet.h"
#include "SplaySet.cpp"

using namespace std;

void DisplayDeleteInNormalSetDuration(const string& key, set<string> english_dictionary_set) {
    auto start = chrono::high_resolution_clock::now();
    english_dictionary_set.erase(key);
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    cout << "duration for deleting in normal set: " << time_span.count() << endl;
}

void DisplaySetInsertDuration(const vector<string>& english_dictionary_vec, set<string> english_dictionary_set) {
    auto insertStartClock = chrono::high_resolution_clock::now();

    for (const string& i : english_dictionary_vec) {
        english_dictionary_set.insert(i);
    }

    auto insertEndClock = chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(insertEndClock - insertStartClock);
    cout << "duration for inserting into normal set: " << time_span.count() << endl;
}

void DisplaySetFindDuration(const string& key, set<string> english_dictionary_set) {
    auto findStartClock = chrono::high_resolution_clock::now();

    english_dictionary_set.find(key);

    auto findEndClock = chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span3 = std::chrono::duration_cast<std::chrono::duration<double>>(findEndClock - findStartClock);

    cout << "duration for finding in normal set: " << time_span3.count() << endl;
}

void DisplaySetClearDuration(set<string> english_dictionary_set) {
    auto start = chrono::high_resolution_clock::now();

    english_dictionary_set.clear();

    auto end = chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span3 = std::chrono::duration_cast<std::chrono::duration<double>>(start - end);

    cout << "duration for clearing in normal set: " << time_span3.count() << endl;
}

int main() {
////==============================CREATING INITIAL TREE=======================================


    set<string> english_dictionary_set;
    vector<string> english_dictionary_vec;
    SplaySet<string> splaySet;

    std::ifstream file("/home/szymek/CLionProjects/splay2/english.dic");

    string line;
    while (getline(file, line)) {
        english_dictionary_vec.push_back(line.c_str());
    }
    file.close();

    DisplaySetInsertDuration(english_dictionary_vec, english_dictionary_set);

    ////Insert into Splay set
    auto insertStartClock2 = chrono::high_resolution_clock::now();
    for (const string& i : english_dictionary_vec) {
        splaySet.insert(i);
    }
    auto insertEndClock2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(insertEndClock2 - insertStartClock2);
    cout << "duration for inserting into splay set: " << time_span2.count() << endl;

    ////Insert into Splay set
    auto insertStartClock3 = chrono::high_resolution_clock::now();
    splaySet.insert("testing\r");
    auto insertEndClock3 = chrono::high_resolution_clock::now();
    std::chrono::duration<double> insert_time_span = std::chrono::duration_cast<std::chrono::duration<double>>(insertEndClock3 - insertStartClock3);
    cout << "duration for inserting into splay set 2: " << insert_time_span.count() << endl;

    //// Find in normal set
    DisplaySetFindDuration("incipience\r", english_dictionary_set);

    //// Find in Splay set
    auto findStartClock = chrono::high_resolution_clock::now();
    splaySet.find("incipience\r");
    auto findEndClock = chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span3 = std::chrono::duration_cast<std::chrono::duration<double>>(findEndClock - findStartClock);
    cout << "duration for finding in splay set: " << time_span3.count() << endl;


    //// Find in Splay set 2
    auto findStartClock2 = chrono::high_resolution_clock::now();
    auto data = splaySet.find("incipience\r");
    auto findEndClock2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span4 = std::chrono::duration_cast<std::chrono::duration<double>>(findEndClock2 - findStartClock2);
    cout << "duration for finding in splay set 2: " << time_span4.count() << endl;

    ////Delete in normal set
    DisplayDeleteInNormalSetDuration("incipiency\r", english_dictionary_set);

    cout << "size before deletion: " << splaySet.size() << endl;

    ////Delete in splay set
    auto deleteStartClock = chrono::high_resolution_clock::now();
    splaySet.erase("incipience\r");
    auto deleteEndClock = chrono::high_resolution_clock::now();
    std::chrono::duration<double> delete_time_span = std::chrono::duration_cast<std::chrono::duration<double>>(deleteEndClock - deleteStartClock);
    cout << "duration for deleting in splay set: " << delete_time_span.count() << endl;

    cout << "size after deletion: " << splaySet.size() << endl;

    cout << "is empty: " << splaySet.empty() << endl;

    cout << "max size for splay set: " << splaySet.max_size() << endl;

    DisplaySetClearDuration(english_dictionary_set);

    ////Clear splay set
    auto clearStartClock = chrono::high_resolution_clock::now();
    splaySet.clear();
    auto clearEndClock = chrono::high_resolution_clock::now();
    std::chrono::duration<double> clear_time_span = std::chrono::duration_cast<std::chrono::duration<double>>(clearEndClock - clearStartClock);
    cout << "duration for clearing splay set: " << clear_time_span.count() << endl;


    cout << "size after clear: " << splaySet.size() << endl;
    cout << "is empty: " << splaySet.empty() << endl;





//    splaySet.insert(3);
//    splaySet.insert(39);
//    splaySet.insert(87);
//    splaySet.insert(7);
//    splaySet.insert(22);
//    splaySet.insert(42);
//    splaySet.insert(20);
//
//    std::cout << "In Splay Tree Diagrams, └──── denotes a right child and ├──── denotes a left child" << std::endl
//              << std::endl;
//    //this will print out a diagram of the tree
//    std::cout << "INITIAL SPLAY TREE:" << std::endl << std::endl;
//    splaySet.printTree();
//
//
//////==============================SPLAY TREE INSERTION TEST===================================
//    splaySet.insert(10);
//    std::cout << std::endl << std::endl << "AFTER INSERTING 10:" << std::endl << std::endl;
//    splaySet.printTree();
//
//////==============================SPLAY TREE SEARCH TEST===================================
//    splaySet.find(42);
//    std::cout << std::endl << std::endl << "AFTER SEARCHING FOR 42:" << std::endl << std::endl;
//    splaySet.printTree();
//
//////==============================SPLAY TREE DELETE TEST===================================
//
////    splaySet.deleteNode(22);
////    std::cout << std::endl << std::endl <<"AFTER DELETING 22:"<< std::endl << std::endl;
////    printTree(splayTree1);
//
//    std::cout << "ITERATOR!!!"  << std::endl;
//    for (auto it = splaySet.begin(); it != splaySet.end(); ++it) {
//        cout << ' ' << it->data;
//    }
//
//    std::cout << std::endl;
//
//    std::cout << "ITERATOR BACKWARDS!!!"  << std::endl;
//    for (auto it = splaySet.end(); it != splaySet.begin(); --it) {
//        cout << ' ' << it->data;
//    }




    return 0;
}

// TODO: eplace, rbegin, rend, key_comp i value_comp
// TODO MAPA