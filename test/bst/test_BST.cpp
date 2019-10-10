/*
 *  Filename: test_BST.cpp
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
#include "BST.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/* Empty BST test starts here */

TEST(BSTTests, EMPTY_TREE_HEIGHT_TEST) {
    BST<int> bst;
    ASSERT_EQ(bst.height(), -1);
}

/* Small BST test starts here */

/**
 * A simple test fixture from which multiple tests
 * can be created. All fixture tests (denoted by the
 * TEST_F macro) can access the protected members of this
 * fixture. Its data is reset after every test.
 *
 * Builds the following BST:
 *         3
 *        / \
 *       1   4
 *      /     \
 *    -33     100
 */
class SmallBSTFixture : public ::testing::Test {
  protected:
    BST<int> bst;

  public:
    SmallBSTFixture() {
        // initialization code here
        vector<int> input{3, 4, 1, 100, -33};
        insertIntoBST(input, bst);
    }
    // code in SetUp() will execute just before the test ensues
    // void SetUp() {}
};

TEST_F(SmallBSTFixture, SMALL_SIZE_TEST) {
    // assert that the small BST has the correct size
    ASSERT_EQ(bst.size(), 5);
}
/*test duplicates */
TEST_F(SmallBSTFixture, SMALL_INSERT_DUPLICATES_TEST) {
    // assert failed duplicate insertion
    ASSERT_FALSE(bst.insert(3));
}
/* test item not in bst*/
TEST_F(SmallBSTFixture, FIND_TEST_NOTFOUND) {
    ASSERT_EQ(bst.find(7), bst.end());  // not found
}
TEST_F(SmallBSTFixture, FIND_TEST_FOUND) {

 //ASSERT_EQ(bst.find(-33), bst.first());//found

}
/* test height */
TEST_F(SmallBSTFixture, HEIGHT_TEST) { 
	
  ASSERT_EQ(bst.height(), 2); 
}
/* test empty */
TEST_F(SmallBSTFixture, EMPTY_TREE_TEST) {

 
  ASSERT_FALSE(bst.empty());//not empty tree

}
/* test inorder */
TEST_F(SmallBSTFixture, INORDER_TEST) {
    vector<int> data = {-33, 1, 3, 4, 100};

    ASSERT_EQ(bst.inorder(), data);  //
}

