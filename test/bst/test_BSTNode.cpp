/*
 *  Filename: test_BSTNode.cpp
 *  Author: Abdikhalik Ahmed/Andrew Masters
 *  UserId: 
 *  Date: 10/4/2019
 *  Sources of help:TextBook
*/
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
/* test successor */
TEST(BST_NODE_TESTS, TEST_SUCCESSOR) {
    BSTNode<int> node(3);
    ASSERT_EQ(node.successor(), nullptr);
}
/* test successor again */
TEST(BST_NODE_TESTS, TEST_SUCCESSOR_AGAIN) {
    BSTNode<int> node(3);
    node.left = new BSTNode<int>(2);
    node.right = new BSTNode<int>(4);

    ASSERT_EQ(node.successor()->data, 4);
    ASSERT_EQ(nullptr, node.right->successor());
    delete (node.left);
    delete (node.right);
}
/* test successor one more time */
TEST(BST_NODE_TESTS, TEST_SUCCESSOR_AGAIN2) {
    BSTNode<int>*  node = new BSTNode<int>(10);

    node->left = new BSTNode<int>(7);
    node->right = new BSTNode<int>(14);

    node->left->left = new BSTNode<int>(5);
    node->left->right = new BSTNode<int>(8);

    node->right->left = new BSTNode<int>(11);
    node->right->right = new BSTNode<int>(15);


    BSTNode<int>* node2 = node->successor();

    EXPECT_EQ(node2->data, 11);
    
    //free memory
    delete(node->left->left);
    
    delete(node->left->right);
    delete(node->left);
    
    delete(node->right->left);

    delete(node->right->right);

    delete(node->right);

    delete(node);
}
