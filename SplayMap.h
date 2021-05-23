//
// Created by szymek on 22.05.2021.
//

#ifndef SPLAY2_SPLAYMAP_H
#define SPLAY2_SPLAYMAP_H

#include <memory>
#include <iostream>
#include "SplayTree.h"
#include "splay_iterator.h"

using namespace std;

template<typename Key, typename Value, typename Compare = less<Key>,
        typename Alloc = allocator<Node<Key, Value>> >
class SplayMap {
private:
    SplayTree<Key, Value> splayTree;
    Node<Key, Value> *n{};
    Compare compare;
public:
    typedef Alloc allocator_type;
    typedef typename Alloc::value_type value_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::difference_type difference_type;
    typedef typename Alloc::size_type size_type;

    typedef splay_iterator<Key, Value, Compare, Alloc> iterator;
//    typedef splay_const_iterator<Key, Alloc> const_iterator;

    void insert(pair<Key, Value> pair);
    void erase(Key key);
    int size();
    bool empty();
    size_t max_size();
    void clear();
    Compare key_comp() { return compare; }
    pair<Key, Value> find(Key key);


    Value getValue(Key key);
    void printTree();

    SplayMap();
    SplayMap(const SplayMap&);
    ~SplayMap();

    iterator begin() { return splay_iterator<Key, Value, less<Key>, Alloc>(splayTree.minimum(splayTree.getRoot())); }
    iterator end() { return splay_iterator<Key, Value, less<Key>, Alloc>(splayTree.maximum(splayTree.getRoot())); }

};


#endif //SPLAY2_SPLAYMAP_H
