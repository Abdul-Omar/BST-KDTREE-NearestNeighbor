/*
 *  Filename: test_BSTIterator.cpp
 *  Author: Abdikhalik Ahmed/Andrew Masters
 *  UserId: 
 *  Date: 10/4/2019
 *  Sources of help:TextBook
*/#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "BSTIterator.hpp"
#include "BSTNode.hpp"

using namespace std;
using namespace testing;
/* test increment operator */
TEST(BST_ITERATOR_TEST, TEST_ITERATOR_INCREMENT) {
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    ASSERT_NE(iter, nullptr);

    iter++;

    ASSERT_EQ(iter, nullptr);
}
/* test == operator */
TEST(BST_ITERATOR_TEST, TEST_ITERATOR_EQUALS) {
    
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    BSTNode<int>& anotherNode = node;

    BSTIterator<int> iter2(&anotherNode);

    EXPECT_TRUE(iter == iter2);
}
/* tets != operator */
TEST(BST_ITERATOR_TEST, TEST_ITERATOR_NOT_EQUALS) {
   
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    BSTNode<int> anotherNode(4);

    BSTIterator<int> iter2(&anotherNode);

    EXPECT_TRUE(iter != iter2);
}
