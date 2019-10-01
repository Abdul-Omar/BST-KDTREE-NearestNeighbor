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
    BSTNode(const Data& d) : data(d) {}

    /** TODO */
    BSTNode<Data>* successor() {
        BSTNode<Data>* succesorr = nullptr;  // holds the successor

        successorr = this;  // start at 'this' node;

        /* no right child to become sucessor
         * then the successor must be one of its ancestors if it exists
         */
        if (!this->right) {
            // traverse up parents until a node that is left child of its parent
            // is found
            while (successorr->parent != nullptr &&
                   successorr == successor->parent->right) {
                successor = successorr->parent;

                successorr->parent = successorr->parent->parent;
            }

            return successorr->parent;
        }

        // has a right child
        else {
            BSTNode<Data>* current = this->right;  // go to right child
            /* successor is the smallest element in this right child's subtree*/
            while (current.left != nullptr) {
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
