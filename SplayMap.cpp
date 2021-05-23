//
// Created by szymek on 22.05.2021.
//

#include "SplayMap.h"

template<typename Key, typename Value, typename Compare, typename Alloc>
void SplayMap<Key, Value, Compare, Alloc>::insert(pair<Key, Value> pair) {
    splayTree.insert(pair.first, pair.second);
}

template<typename Key, typename Value, typename Compare, typename Alloc>
SplayMap<Key, Value, Compare, Alloc>::SplayMap() = default;

template<typename Key, typename Value, typename Compare, typename Alloc>
SplayMap<Key, Value, Compare, Alloc>::SplayMap(const SplayMap &) {

}

template<typename Key, typename Value, typename Compare, typename Alloc>
void SplayMap<Key, Value, Compare, Alloc>::printTree() {
    cout << "Splay Tree Diagram:" << endl << endl;
    splayTree.prettyPrint();
    //this will print a pre-order traversal of the tree
    cout << endl <<"Pre-Order Traversal:"<< endl;
    splayTree.preorder();
}

template<typename Key, typename Value, typename Compare, typename Alloc>
void SplayMap<Key, Value, Compare, Alloc>::erase(Key key) {
    splayTree.deleteNode(key);
}

template<typename Key, typename Value, typename Compare, typename Alloc>
int SplayMap<Key, Value, Compare, Alloc>::size() {
    return splayTree.getSize();
}

template<typename Key, typename Value, typename Compare, typename Alloc>
bool SplayMap<Key, Value, Compare, Alloc>::empty() {
    return splayTree.getSize() == 0;
}

template<typename Key, typename Value, typename Compare, typename Alloc>
size_t SplayMap<Key, Value, Compare, Alloc>::max_size() {
    return splayTree.getMaxSize();
}

template<typename Key, typename Value, typename Compare, typename Alloc>
void SplayMap<Key, Value, Compare, Alloc>::clear() {
    for (auto it = begin(); it != end(); ++it) {
        splayTree.clear(it.getData());
    }
    splayTree.clear(end().getData());
}

template<typename Key, typename Value, typename Compare, typename Alloc>
Value SplayMap<Key, Value, Compare, Alloc>::getValue(Key key) {
    return splayTree.searchTree(key)->value;
}

template<typename Key, typename Value, typename Compare, typename Alloc>
pair<Key, Value> SplayMap<Key, Value, Compare, Alloc>::find(Key key) {
    NodePtr ptr = splayTree.searchTree(key);
    return pair<Key, Value>(ptr->data, ptr->value);
}

template<typename Key, typename Value, typename Compare, typename Alloc>
SplayMap<Key, Value, Compare, Alloc>::~SplayMap() = default;
