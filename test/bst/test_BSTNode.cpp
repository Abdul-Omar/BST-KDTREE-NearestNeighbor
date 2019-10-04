#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "BSTNode.hpp"

using namespace std;
using namespace testing;

TEST(BST_NODE_TESTS, TEST_SUCCESSOR) {
    BSTNode<int> node(3);
    ASSERT_EQ(node.successor(), nullptr);


}	

TEST(BST_NODE_TESTS, TEST_SUCCESSOR_AGAIN) {
  
    BSTNode<int> node(3);
    node.left =  new BSTNode<int> (2);
    node.right =  new BSTNode<int> (4);
   
    ASSERT_EQ(node.successor()->data, 4);
   
    delete(node.left);
    delete(node.right);

}



 TEST(BST_NODE_TESTS, TEST_SUCCESSOR_AGAIN2) {
  
    BSTNode<int> node(10);
   
    node.left =  new BSTNode<int> (7);
    node.right = new BSTNode<int> (14);
    
    node.left->left  = new BSTNode<int> (5);
    node.left->right  = new BSTNode<int> (8);
    
    node.right->left  = new BSTNode<int> (11);
    node.right->right  = new BSTNode<int> (15);
    
    ASSERT_EQ(node.successor()->data, 11);

    ASSERT_EQ(node.successor()->successor()->data, 14);

    ASSERT_EQ(node.successor()->successor()->successor()->data, 15);



}

