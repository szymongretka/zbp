//
// Created by szymek on 19.05.2021.
//

#ifndef SPLAY2_SPLAYSET_H
#define SPLAY2_SPLAYSET_H

#include <memory>
#include <iostream>
#include "SplayTree.h"
#include "splay_iterator.h"

using namespace std;

template<typename Key, typename Compare = less<Key>,
        typename Alloc = allocator<Node<Key, Key>> >
class SplaySet {
private:
    SplayTree<Key, Key> splayTree;
    Node<Key, Key> *n{};
    Compare compare;
public:
    typedef Alloc allocator_type;
    typedef typename Alloc::value_type value_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::difference_type difference_type;
    typedef typename Alloc::size_type size_type;

    typedef splay_iterator<Key, Key, Compare, Alloc> iterator;
//    typedef splay_const_iterator<Key, Alloc> const_iterator;

    void insert(Key key);
    void erase(Key key);
    int size();
    bool empty();
    size_t max_size();
    void clear();
    Compare key_comp() { return compare; }
    Key find(Key key);


    int getKey();
    void printTree();

    SplaySet();
    SplaySet(const SplaySet&);
    ~SplaySet();

    iterator begin() { return splay_iterator<Key, Key, less<Key>, Alloc>(splayTree.minimum(splayTree.getRoot())); }
    iterator end() { return splay_iterator<Key, Key, less<Key>, Alloc>(splayTree.maximum(splayTree.getRoot())); }
//    iterator find(Key key) { return splay_iterator<Key, Key, less<Key>, Alloc>(splayTree.searchTree(key)); }

};


#endif //SPLAY2_SPLAYSET_H
