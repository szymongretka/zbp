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
        typename Alloc = allocator<Node<Key>> >
class SplaySet {
public:
    typedef Alloc allocator_type;
    typedef typename Alloc::value_type value_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::difference_type difference_type;
    typedef typename Alloc::size_type size_type;

    typedef splay_iterator<Key, Compare, Alloc> iterator;
//    typedef splay_const_iterator<Key, Alloc> const_iterator;

    Key testInsert(Key key);
    Key testSearch(Key key);
    void preOrder();
    int getKey();
    void printTree();

    SplaySet();
    SplaySet(const SplaySet&);
    ~SplaySet();

    iterator begin() { return splay_iterator<Key, less<Key>, Alloc>(splayTree.minimum(splayTree.getRoot())); }
    iterator end() { return splay_iterator<Key, less<Key>, Alloc>(splayTree.maximum(splayTree.getRoot())); }


private:
    SplayTree<Key> splayTree;
    Node<Key> *n{};

};


#endif //SPLAY2_SPLAYSET_H
