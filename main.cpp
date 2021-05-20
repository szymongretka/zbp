#include <iostream>
#include "SplayTree.cpp"
#include "SplaySet.h"
#include "SplaySet.cpp"

//Method that prints the splay tree and pre order traversal
//void printTree(SplayTree<int> &splayTree1) {
//    cout << "Splay Tree Diagram:" << endl << endl;
//    splayTree1.prettyPrint();
//    //this will print a pre-order traversal of the tree
//    cout << endl <<"Pre-Order Traversal:"<< endl;
//    splayTree1.preorder();
//}

int main() {
////==============================CREATING INITIAL TREE=======================================
    SplaySet<int> splaySet;

    splaySet.testInsert(3);
    splaySet.testInsert(39);
    splaySet.testInsert(87);
    splaySet.testInsert(7);
    splaySet.testInsert(22);
    splaySet.testInsert(42);
    splaySet.testInsert(20);

    std::cout << "In Splay Tree Diagrams, └──── denotes a right child and ├──── denotes a left child" << std::endl
              << std::endl;
    //this will print out a diagram of the tree
    std::cout << "INITIAL SPLAY TREE:" << std::endl << std::endl;
    splaySet.printTree();


////==============================SPLAY TREE INSERTION TEST===================================
    splaySet.testInsert(10);
    std::cout << std::endl << std::endl << "AFTER INSERTING 10:" << std::endl << std::endl;
    splaySet.printTree();

////==============================SPLAY TREE SEARCH TEST===================================
    splaySet.testSearch(42);
    std::cout << std::endl << std::endl << "AFTER SEARCHING FOR 42:" << std::endl << std::endl;
    splaySet.printTree();

////==============================SPLAY TREE DELETE TEST===================================

//    splaySet.deleteNode(22);
//    std::cout << std::endl << std::endl <<"AFTER DELETING 22:"<< std::endl << std::endl;
//    printTree(splayTree1);

    std::cout << "ITERATOR!!!"  << std::endl;
    for (auto it = splaySet.begin(); it != splaySet.end(); ++it) {
        cout << ' ' << it->data;
    }

    std::cout << std::endl;

    std::cout << "ITERATOR BACKWARDS!!!"  << std::endl;
    for (auto it = splaySet.end(); it != splaySet.begin(); --it) {
        cout << ' ' << it->data;
    }


    return 0;
}
