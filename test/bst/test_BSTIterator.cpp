#include <algorithm>
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

TEST(BST_ITERATOR_TEST, TEST_ITERATOR_INCREMENT) {
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    ASSERT_NE(iter, nullptr);

    iter++;

    ASSERT_EQ(iter, nullptr);
}

TEST(BST_ITERATOR_TEST, TEST_ITERATOR_EQUALS) {
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    BSTNode<int> anotherNode(3);

    BSTIterator<int> iter2(&anotherNode);

    EXPECT_TRUE(iter == iter2);
}

TEST(BST_ITERATOR_TEST, TEST_ITERATOR_NOT_EQUALS) {
    BSTNode<int> node(3);
    BSTIterator<int> iter(&node);

    BSTNode<int> anotherNode(4);

    BSTIterator<int> iter2(&anotherNode);

    EXPECT_FALSE(iter != iter2);
}
