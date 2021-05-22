//
// Created by szymek on 19.05.2021.
//

#ifndef SPLAY2_SPLAYTREE_H
#define SPLAY2_SPLAYTREE_H


#include <memory>
#include <iostream>

using namespace std;

// data structure that represents a node in the tree
template<typename Key>
struct Node {
    Key data; // holds the key //TODO key jako pair <key, value> ?
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
};

typedef Node<string> *NodePtr;

// class SplayTree implements the operations in Splay tree
template<typename Key, typename Alloc = allocator<Node<Key>>>
class SplayTree {
public:
    SplayTree();

    // Pre-Order traversal
    // Node->Left Subtree->Right Subtree
    void preorder();
    // In-Order traversal
    // Left Subtree -> Node -> Right Subtree
    void inorder();
    // Post-Order traversal
    // Left Subtree -> Right Subtree -> Node
    void postorder();
    // search the tree for the key k
    // and return the corresponding node
    NodePtr searchTree(Key k);
    // find the node with the minimum key
    NodePtr minimum(NodePtr node);
    // find the node with the maximum key
    NodePtr maximum(NodePtr node);
    // find the successor of a given node
    NodePtr successor(NodePtr x);
    // find the predecessor of a given node
    NodePtr predecessor(NodePtr x);
    // insert the key to the tree in its appropriate position
    void insert(Key key);
    NodePtr getRoot();
    // delete the node from the tree
    void deleteNode(Key data);
    // print the tree structure on the screen
    void prettyPrint();
    int getSize();
    size_t getMaxSize();
    void clear(Node<string> *ptr);
private:
    NodePtr mRoot;
    Alloc alloc;
    NodePtr *nodePtr;
    int size = 0;
    //called by pre order function, prints contents of nodes with pre order traversal
    void preOrderHelper(NodePtr node);
    //called by in order function, prints contents of nodes with in order traversal
    void inOrderHelper(NodePtr node);
    //called by post order function, prints contents of nodes with post order traversal
    void postOrderHelper(NodePtr node);
    //traverses binary search tree until finds the location of the key
    NodePtr searchTreeHelper(NodePtr node, Key key);
    //deletes node and rebalances tree
    void deleteNodeHelper(NodePtr node, Key key);
    //prints a diagram of the splay tree
    void printHelper(NodePtr root, string indent, bool last);
    // rotate left at node x
    void leftRotate(NodePtr x);
    // rotate right at node x
    void rightRotate(NodePtr x);
    // splaying
    void splay(NodePtr x);
    // joins two trees s and t
    NodePtr join(NodePtr s, NodePtr t);
    // splits the tree into s and t
    void split(NodePtr &x, NodePtr &s, NodePtr &t);
};



#endif //SPLAY2_SPLAYTREE_H
