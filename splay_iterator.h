//
// Created by szymek on 19.05.2021.
//

#ifndef SPLAY2_SPLAY_ITERATOR_H
#define SPLAY2_SPLAY_ITERATOR_H

#include "TreeTraversal.cpp"

template <typename K, typename C, typename A>
class splay_iterator {
public:
    typedef typename A::difference_type difference_type;
    typedef typename A::value_type value_type;
    typedef typename A::reference reference;
    typedef typename A::pointer pointer;
    typedef std::bidirectional_iterator_tag iterator_category;


    splay_iterator(pointer ptr) : m_ptr(ptr){}
    splay_iterator(const splay_iterator&);
    ~splay_iterator();

    splay_iterator& operator=(const splay_iterator&);
//    bool operator==(const splay_iterator&) const;
//    bool operator!=(const splay_iterator&) const;

    splay_iterator& operator++() {
        this->m_ptr = treeMove.getNext(this->m_ptr);
        return *this;
    }
    splay_iterator operator++(int) { splay_iterator tmp = *this; ++(*this); return tmp; }

    splay_iterator& operator--() {
        this->m_ptr = treeMove.getPrevious(this->m_ptr);
        return *this;
    }

    reference operator*() const { return *m_ptr; }
    pointer operator->() const { return m_ptr; }

    friend bool operator== (const splay_iterator& a, const splay_iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const splay_iterator& a, const splay_iterator& b) { return a.m_ptr != b.m_ptr; };

private:
    pointer m_ptr;
    TreeTraversal<K> treeMove;
};

template<typename K, typename C, typename A>
splay_iterator<K, C, A>::splay_iterator(const splay_iterator &) {

}

template<typename K, typename C, typename A>
splay_iterator<K, C, A>::~splay_iterator() = default;



#endif //SPLAY2_SPLAY_ITERATOR_H
