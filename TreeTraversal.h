//
// Created by szymek on 19.05.2021.
//

#ifndef SPLAY2_TREETRAVERSAL_H
#define SPLAY2_TREETRAVERSAL_H


#include "SplayTree.h"

using namespace std;


template<typename Key, typename Value>
class TreeTraversal {
public:
    Node<Key, Value>* getNext(Node<Key, Value> *ptr);
    Node<Key, Value>* getPrevious(Node<Key, Value> *ptr);

};


#endif //SPLAY2_TREETRAVERSAL_H
