#include <gtest/gtest.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "KDT.hpp"
#include "NaiveSearch.hpp"
#include "Point.hpp"
#include "util.hpp"

using namespace std;
using namespace testing;

/**
 * A simple test fixture from which multiple tests can
 * be written. The structure of the KDT built from this
 * may vary. See test_BST.cpp for more information on
 * test fixtures.
 */
class SmallKDTFixture : public ::testing::Test {
  protected:
    vector<Point> vec;
    KDT kdt;

  public:
    SmallKDTFixture() {
        vec.emplace_back(Point({1.0, 3.2}));
        vec.emplace_back(Point({3.2, 1.0}));
        vec.emplace_back(Point({5.7, 3.2}));
        vec.emplace_back(Point({1.8, 1.9}));
        vec.emplace_back(Point({4.4, 2.2}));
       
        vec.emplace_back(Point({7.4, 4.2}));
       
        vec.emplace_back(Point({5.1, 6.1}));
	
        vec.emplace_back(Point({1.4, 3.3}));
	kdt.build(vec);
    }
};
/* test size */
TEST_F(SmallKDTFixture, TEST_SIZE) {
    // Assert that the kd tree has the correct size
    ASSERT_EQ(kdt.size(), 8);
}
/* test height */
TEST_F(SmallKDTFixture, TEST_HEIGHT) {
    // Assert that the kd tree has the correct height
    ASSERT_EQ(kdt.height(), 3);
}
/* the following tests test the correct of findNearestNeighbor function */
TEST_F(SmallKDTFixture, TEST_NEAREST_POINT) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({5.81, 3.21});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT2) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({2.5, 3.2});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT3) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({1.5, 3.0});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT4) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({1.2, 2.8});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT5) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({4.11, 1.21});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT6) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({2.78, 2.2});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT7) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({0.5, 2.0});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT8) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({2.2, 3.8});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT9) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({1.81, 1.21});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}
TEST_F(SmallKDTFixture, TEST_NEAREST_POINT10) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({0.51, 7.0});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT11) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({2.3, 3.7});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT12) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({4.81, 1.21});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}
TEST_F(SmallKDTFixture, TEST_NEAREST_POINT13) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({0.11, 8.55});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT14) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({7.2, 5.8});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}


TEST_F(SmallKDTFixture, TEST_NEAREST_POINT15) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({4.81, 6.21});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}

TEST_F(SmallKDTFixture, TEST_NEAREST_POINT_ALREADY_THERE) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({5.7, 3.2});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);
}





