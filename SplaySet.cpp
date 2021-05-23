
#include "SplaySet.h"

template<typename Key, typename Compare, typename Alloc>
void SplaySet<Key, Compare, Alloc>::insert(Key key) {
    splayTree.insert(key, key);
}

//template<typename Key, typename Compare, typename Alloc>
//iterator SplaySet<Key, Compare, Alloc>::find(Key key) {
//    return splay_iterator<Key, less<Key>, Alloc>(splayTree.searchTree(key));
//}

template<typename Key, typename Compare, typename Alloc>
int SplaySet<Key, Compare, Alloc>::getKey() {
    return n->key;
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
void SplaySet<Key, Compare, Alloc>::erase(Key key) {
    splayTree.deleteNode(key);
}

template<typename Key, typename Compare, typename Alloc>
int SplaySet<Key, Compare, Alloc>::size() {
    return splayTree.getSize();
}

template<typename Key, typename Compare, typename Alloc>
bool SplaySet<Key, Compare, Alloc>::empty() {
    return splayTree.getSize() == 0;
}

template<typename Key, typename Compare, typename Alloc>
size_t SplaySet<Key, Compare, Alloc>::max_size() {
    return splayTree.getMaxSize();
}

template<typename Key, typename Compare, typename Alloc>
void SplaySet<Key, Compare, Alloc>::clear() {
    for (auto it = begin(); it != end(); ++it) {
        splayTree.clear(it.getData());
    }
    splayTree.clear(end().getData());
}

template<typename Key, typename Compare, typename Alloc>
SplaySet<Key, Compare, Alloc>::~SplaySet() = default;
