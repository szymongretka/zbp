//
// Created by szymek on 19.05.2021.
//

#include "SplaySet.h"

template<typename Key, typename Compare, typename Alloc>
Key SplaySet<Key, Compare, Alloc>::testInsert(Key key) {
    splayTree.insert(key);
}

template<typename Key, typename Compare, typename Alloc>
Key SplaySet<Key, Compare, Alloc>::testSearch(Key key) {
    Node<Key> *result = splayTree.searchTree(key);
    return result->data;
}

template<typename Key, typename Compare, typename Alloc>
int SplaySet<Key, Compare, Alloc>::getKey() {
    return n->key;
}

template<typename Key, typename Compare, typename Alloc>
void SplaySet<Key, Compare, Alloc>::preOrder() {
    splayTree.preOrder(n);
}

template<typename Key, typename Compare, typename Alloc>
SplaySet<Key, Compare, Alloc>::SplaySet() = default;

template<typename Key, typename Compare, typename Alloc>
SplaySet<Key, Compare, Alloc>::SplaySet(const SplaySet &) {

}

template<typename Key, typename Compare, typename Alloc>
void SplaySet<Key, Compare, Alloc>::printTree() {
    cout << "Splay Tree Diagram:" << endl << endl;
    splayTree.prettyPrint();
    //this will print a pre-order traversal of the tree
    cout << endl <<"Pre-Order Traversal:"<< endl;
    splayTree.preorder();
}

template<typename Key, typename Compare, typename Alloc>
SplaySet<Key, Compare, Alloc>::~SplaySet() = default;
