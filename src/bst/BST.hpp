/*
 *  Filename: BST.hpp
 *  Author: Abdikhalik Ahmed/Andrew Masters
 *  UserId: 
 *  Date: 10/4/2019
 *  Sources of help:TextBook
*/


#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <vector>
#include<algorithm>
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

    /*destructor for the class */
    virtual ~BST() { deleteAll(root); }

     /*
    * Function Name: insert()
    * Function Prototype: virtual bool insert(const Data& item) 
    * Description: this function inserts a new node in the BST
    * Parameters:
                item: the data of the node to be inserted
    * Return Value: true or false whether node was successfuly inserted
    */
    virtual bool insert(const Data& item) {
        /* empty tree */
        if (root == nullptr) {
            root = new BSTNode<Data>(item);
            root->parent = nullptr;  // has no parent;
            isize++;                 // increment size
            iheight++;               // increment tree height
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
        // pick up from where we fell off tree and check whether to attach new
        // node to its left or right
        if (item < prev->data) {
            prev->left = new BSTNode<Data>(item);

            prev->left->parent = prev;  // prev is its parent
	    iheight++;
            isize++;
        }

        else {
            prev->right = new BSTNode<Data>(item);

            prev->right->parent = prev;  // prev is its parent;
            
	    iheight++;
            isize++;
        }

        return true;
    }

    /** TODO */
    virtual iterator find(const Data& item) const {

	if(!root) return end();
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
            // we have found the node
            else {
                return BST::iterator(current);
            }
        }
        return end();  // could not find, return iterator past the end
    }

    /** This function returns the size of the tree */
    unsigned int size() const { return isize; }

    /** This function returns the  height of the tree*/
    int height() const { return height(root);}

    /** This function checks whether the BST is empty or not */
    bool empty() const { return root == nullptr; }

    /** Return an iterator pointing to the first item in the BST. */
    iterator begin() const { return typename BST<Data>::iterator(first(root)); }

    /** Return an iterator pointing past the last item in the BST.
     */
    iterator end() const { return typename BST<Data>::iterator(0); }

    /** this function the inorder traversal of the BST */
    vector<Data> inorder() const {
        vector<Data> data;//holds the nodes of the tree
        //call recursive function for inorder traversal
        inOrderRecur(root, data);

	    return data;
      
    }

  private:
    /** This function returns the  first(smallest) element in the tree */
    static BSTNode<Data>* first(BSTNode<Data>* root) {

	if(!root) return nullptr;
        // base case
        if (!root->left) {
            return root;
        }
        // recursively move left all the way
        return first(root->left);
    }
    void  inOrderRecur(BSTNode<Data>* root, vector<Data>& data) const {
          // holds the list of points

        if (root){  // base case
        // visit left of root
        inOrderRecur(root->left, data);
        // visit root itself
        data.push_back(root->data);
        // visit right of root
        inOrderRecur(root->right, data);}
    }

    int height (BSTNode<Data>* root)const {  
	    
      if(!root) return -1;

      return 1 + max(height(root->left), height(root->right));
    
    }
     /*
    * Function Name: deleteAll()
    * Function Prototype:static void deleteAll(KDNode* n) ;
    * Description: this function deletes all nodes in the tree
    * Parameters:
                n:  the root of the tree to delete
    * Return Value: NONE
    */
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
