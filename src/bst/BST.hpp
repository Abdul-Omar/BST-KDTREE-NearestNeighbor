#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <vector>
#include "BSTIterator.hpp"
#include "BSTNode.hpp"
using namespace std;

template <typename Data>
class BST {
  protected:
    // pointer to the root of this BST, or 0 if the BST is empty
    BSTNode<Data>* root;

    // number of Data items stored in this BST.
    unsigned int isize;

    // height of this BST.
    int iheight;

  public:
    /** Define iterator as an aliased typename for BSTIterator<Data>. */
    typedef BSTIterator<Data> iterator;

    /** Default constructor.
     *  Initialize an empty BST.
     */
    BST() : root(0), isize(0), iheight(-1) {}

    /** TODO */
    virtual ~BST() { deleteAll(root); }

    /** TODO */
    virtual bool insert(const Data& item) {
        /* empty tree */
        if (root == nullptr) {
            root = new BST<Data>(item);
            return true;
        }

        BSTNode<Data> current = root;
        BSTNode<Data> prev = nullptr;  // keeps track where we fell off tree
        /* traverse tree*/
        while (current = !nullptr) {
            // check which side to go and traverse it
            if (value < current->data) {
                prev = current;
                current = current->left;
            } else if (current->data < item) {
                prev = current;
                current = current->right;
            }
            // found the node wanted to insert
            else {
                return false;
            }
        }
        // pick up from where we fell off tree and check whether to attach it
        // left or right
        if (value < prev->data) {
            prev->left = new BSTNode<Data>(item);
        }

        else {
            prev->right = new BSTNode<Data>(item);
        }

        return true;
    }

    /** TODO */
    virtual iterator find(const Data& item) const {
        BSTNode<Data>* current = root;  // start at root

        // check if root has the data being searched
        if (item == current->data) {
            return iterator(temp);  // return an iterator pointing to it
        }

        /* traverse the tree left or right to check */
        while (current != nullptr) {
            // check left
            if (item < current->data) {
                current = current->left;
            }
            // check right
            else if (current->data < item) {
                current = current->right;
            } else {
                return iterator(temp);
            }
            return end();  // iterator past the end
        }

        return 0;
    }

    /** TODO */
    unsigned int size() const { return 0; }

    /** TODO */
    int height() const { return 0; }

    /** TODO */
    bool empty() const { return false; }

    /** TODO */
    iterator begin() const { return BST::iterator(first(root)); }

    /** Return an iterator pointing past the last item in the BST.
     */
    iterator end() const { return typename BST<Data>::iterator(0); }

    /** TODO */
    vector<Data> inorder() const {}

  private:
    /** TODO */
    static BSTNode<Data>* first(BSTNode<Data>* root) { return 0; }

    /** TODO */
    static void deleteAll(BSTNode<Data>* n) {
        /* Pseudocode:
           if current node is null: return;
           recursively delete left sub-tree
           recursively delete right sub-tree
           delete current node
        */
    }
};

#endif  // BST_HPP
