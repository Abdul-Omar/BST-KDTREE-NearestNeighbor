#include <gtest/gtest.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stdlib.h>
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

class LargeKDTFixture : public ::testing::Test {
  protected:
    vector<Point> vec;
    KDT kdt;

  public:
    LargeKDTFixture() {
	float random = 0.0;
	float random2 = 0.0;

	for(int i = 0; i < 999; i++){
		random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
		random2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));

		vec.emplace_back(Point({random, random2}));	
	}

	kdt.build(vec);
    }
};

class ThreeDKDTFixture : public ::testing::Test {
  protected:
    vector<Point> vec;
    KDT kdt;

  public:
    ThreeDKDTFixture() {
        vec.emplace_back(Point({1.0, 3.2, 2.0}));
        vec.emplace_back(Point({3.2, 1.0, 3.4}));
        vec.emplace_back(Point({5.7, 3.2, 1.4}));
        vec.emplace_back(Point({1.8, 1.9, 5.6}));
        vec.emplace_back(Point({4.4, 2.2, 6.7}));
       
       /* vec.emplace_back(Point({7.4, 4.2, 3.7}));
       
        vec.emplace_back(Point({5.1, 6.1, 4.1}));
	
        vec.emplace_back(Point({1.4, 3.3, 5.1}));
	vec.emplace_back(Point({2.6, 4.7, 7.9}));
	vec.emplace_back(Point({5.4, 3.2, 9.8}));
	vec.emplace_back(Point({6.2, 3.4, 7.4}));
	vec.emplace_back(Point({7.1, 8.3, 4.3}));
	vec.emplace_back(Point({3.2, 6.9, 1.7}));*/
	kdt.build(vec);
    }
};


/*
TEST_F(SmallKDTFixture, TEST_SIZE) {
    // Assert that the kd tree has the correct size
    ASSERT_EQ(kdt.size(), 8);
}

TEST_F(SmallKDTFixture, TEST_HEIGHT) {
    // Assert that the kd tree has the correct height
    ASSERT_EQ(kdt.height(), 3);
}
the following tests test the correct of findNearestNeighbor function 
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

TEST_F(ThreeDKDTFixture, TEST_NEAREST_POINT_3D) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint({5.7, 3.2, 1.7});
    Point* closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);

}
*/
TEST_F(ThreeDKDTFixture, TEST_NEAREST_POINT_3D2) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    Point queryPoint2({2.2, 3.1, 5.0});
    Point * closestPoint = naiveSearch.findNearestNeighbor(queryPoint2);
    ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint2), *closestPoint);

}

TEST_F(LargeKDTFixture, TEST_NEAREST_POINT_Large) {
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    float random = 0.0;
    float random2 = 0.0;

   // for(int i = 0; i < 10; i++){
   	random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
	random2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
    	
	Point queryPoint({random, random2});
    
	Point * closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    	ASSERT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);

    //}

}
TEST_F(LargeKDTFixture, TEST_NEAREST_POINT_Large2) {
    
    NaiveSearch naiveSearch;
    naiveSearch.build(vec);
    float random = 0.0;
    float random2 = 0.0;

    for(int i = 0; i < 10; i++){
   	random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
	random2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
	std::cout << "Made it through " << i << " case." << std::endl;
	Point queryPoint({random, random2});
    	Point * closestPoint = naiveSearch.findNearestNeighbor(queryPoint);
    	EXPECT_EQ(*kdt.findNearestNeighbor(queryPoint), *closestPoint);

    }

}

