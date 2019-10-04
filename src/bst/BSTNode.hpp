#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iomanip>
#include <iostream>
using namespace std;

template <typename Data>

class BSTNode {
  public:
    BSTNode<Data>* left;
    BSTNode<Data>* right;
    BSTNode<Data>* parent;
    Data const data;  // the const Data in this node.

    /** TODO */
    BSTNode(const Data& d) : data(d) { left = right = parent = nullptr; }

    /** TODO */
    BSTNode<Data>* successor() {
        BSTNode<Data>* current = nullptr;  // holds the successor

        /* no right child to become sucessor
         * then the successor must be one of its ancestors if it exists
         */
        if (!this->right) {
            current = this;  // start at this node
            // traverse up parents until a node that is left child of its parent
            // is found
            while (current->parent != nullptr &&
                   current == current->parent->right) {
                current = current->parent;
            }

            return current->parent;  // return parent of left child
        }

        // has a right child
        else {
            BSTNode<Data>* current = this->right;  // go to right child
            /* successor is the smallest element in this right child's subtree*/
            while (current->left != nullptr) {
                current = current->left;
            }
            return current;
        }

        return nullptr;  // no successor was found;
    }
};

/** DO NOT CHANGE THIS METHOD
 *  Overload operator<< to print a BSTNode's fields to an ostream.
 */
template <typename Data>
ostream& operator<<(ostream& stm, const BSTNode<Data>& n) {
    stm << '[';
    stm << setw(10) << &n;                  // address of the BSTNode
    stm << "; p:" << setw(10) << n.parent;  // address of its parent
    stm << "; l:" << setw(10) << n.left;    // address of its left child
    stm << "; r:" << setw(10) << n.right;   // address of its right child
    stm << "; d:" << n.data;                // its data field
    stm << ']';
    return stm;
}

#endif  // BSTNODE_HPP
