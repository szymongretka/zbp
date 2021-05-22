//
// Created by szymek on 19.05.2021.
//

#include "TreeTraversal.h"

template<typename Key>
Node<Key> *TreeTraversal<Key>::getNext(Node<Key> *m_ptr) {
    if (m_ptr->right) {
        m_ptr = m_ptr->right;
        while (m_ptr->left) {
            m_ptr = m_ptr->left;
        }
    } else {
        Node<Key> *temp = m_ptr->parent;
        while (temp && m_ptr == temp->right) {
            m_ptr = temp;
            temp = temp->parent;
        }
        if (m_ptr->right != temp || !temp) {
            m_ptr = temp;
        }

    }
    return m_ptr;
}

template<typename Key>
Node<Key> *TreeTraversal<Key>::getPrevious(Node<Key> *ptr) {

    if (!ptr->left && !ptr->right) {
        return ptr->parent;
    }
    if (ptr->left) {
        Node<Key> *temp = ptr->left;
        while (temp->right) {
            temp = temp->right;
        }
        return temp;
    } else {
        Node<Key> *temp = ptr->parent;
        if(temp->right == ptr) {
            return temp;
        }
        while (temp != temp->parent->right) {
            temp = temp->parent;
        }
        return temp->parent;
    }

}