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
            root = new BSTNode<Data>(item);
            root->parent = nullptr;// has no parent;
            isize++;//increment size
            iheight++;//increment tree height
            return true;
        }
        
        /* maintain two pointer one following the other*/
        BSTNode<Data>* current = root;
        BSTNode<Data>* prev = nullptr;  // keeps track where we fell off tree
        
        /* traverse tree*/
        while (current != nullptr) {
            // check which side to go and traverse it
            if (item < current->data) {
                prev = current;
                current = current->left;
                iheight++;
            } else if (current->data < item) {
                prev = current;
                current = current->right;
                iheight++;
            }
            // node is already there
            else {
                return false;
            }
        }
        // pick up from where we fell off tree and check whether to attach new node to its
        // left or right
        if (item < prev->data) {
            prev->left = new BSTNode<Data>(item);

            prev->left->parent = prev;//prev is its parent
            isize++;
        }

        else {
            prev->right = new BSTNode<Data>(item);

            prev->right->parent = prev;//prev is its parent;
            
            isize++;
        }

        return true;
    }

    /** TODO */
    virtual iterator find(const Data& item) const {
        
        BSTNode<Data>* current = root;  // start at root

        // check if root has the data being searched
        if (item == current->data) {
            return BST::iterator(current);  // return an iterator pointing to it
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
            } 
            //we have found the node 
            else {
                return BST::iterator(current);
            }
        }
        return end();  // could not find, return iterator past the end
    }

    /** This function returns the size of the tree */
    unsigned int size() const { 

        return isize; 
    }

    /** This function returns the  height of the tree*/
    int height() const { 
        
        return iheight;
    }

    /** This function checks whether the BST is empty or not */
    bool empty() const { 
        
        return root == nullptr; 
    }

    /** Return an iterator pointing to the first item in the BST. */
    iterator begin() const { 
        
        return typename BST<Data>::iterator(first(root));
    }

    /** Return an iterator pointing past the last item in the BST.
     */
    iterator end() const { 
        
        return typename BST<Data>::iterator(0);
    }

    /** this function the inorder traversal of the BST */
    vector<Data> inorder() const { 
       vector<Data> list;
       list = inOrderRecur(root);
       return list;
    }

  private:
    /** This function returns the  first(smallest) element in the tree */
    static BSTNode<Data>* first(BSTNode<Data>* root) {
        // base case
        if (!root->left) {
            return root;
        }
        // recursively move left all the way
        return first(root->left);
    }
    vector<Data> inOrderRecur( BSTNode<Data>* root )const {
	   
        
        vector<Data> list;  // holds the list of points

        if (!root) return list;  // base case
        //visit left of root
        inOrderRecur(root->left);
        //visit root itself
        list.push_back(root->data);
        //visit right of root
        inOrderRecur(root->right);

        return list;
    }
    /** this function deletes the entire BST tree */
    static void deleteAll(BSTNode<Data>* n) {
        /* Pseudocode:
           if current node is null: return;
           recursively delete left sub-tree
           recursively delete right sub-tree
           delete current node
        */
        if (!n) {
            return;
        }

        deleteAll(n->left);   // delete left subtree
        deleteAll(n->right);  // delete right subtree
        delete n;             // delete the root
    }
};

#endif  // BST_HPP
