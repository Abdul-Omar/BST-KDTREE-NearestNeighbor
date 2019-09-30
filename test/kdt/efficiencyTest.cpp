/**
 * Test efficiency of KD tree compared to brute force implementation
 * of nearest neightbor searching and range searching
 */

#include <stdlib.h>
#include <iostream>
#include <vector>

#include "KDT.hpp"
#include "NaiveSearch.hpp"
#include "Point.hpp"
#include "Timer.hpp"

/** Return a random number between min and max. Note that rand() returns
 *  bad random numbers, but for simplicity, we use it to serve our purpose
 *  here
 */
double randNum(double min, double max) {
    return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

/** Returns a vector of random double values with range [min, max] */
vector<double> randNums(unsigned int size, double min, double max) {
    vector<double> result;
    for (unsigned int i = 0; i < size; i++) {
        result.push_back(randNum(min, max));
    }
    return result;
}

/** Returns a vector of points with given dimensions of given size */
vector<Point> randomPoints(unsigned int numPoints, unsigned int numDim,
                           double min, double max) {
    vector<Point> result;
    for (unsigned int i = 0; i < numPoints; i++) {
        result.push_back(Point(randNums(numDim, min, max)));
    }
    return result;
}

/** Returns a random valid range with number of given dimensions
 *  The length of range at each dimension is given by length
 */
vector<pair<double, double>> rangeRange(unsigned int numDim, int length,
                                        double min, int max) {
    vector<pair<double, double>> range;
    for (unsigned int i = 0; i < numDim; i++) {
        double rand = randNum(min, max - length);
        range.push_back(make_pair(rand, rand + length));
    }
    return range;
}

/** Test the efficiency of kd tree by comparing the runtime to naive search */
int main() {
    const int NUM_DATA = 5000000;  // number of random Build data
    const int NUM_TEST = 10;       // number of tests
    const int NUM_DIM = 3;         // number of dimension of random data
    const double MIN_VAL = 0;      // lower bound of random data features
    const double MAX_VAL = 100;    // upper bound of random data features
    const double RANGE_LEN = 3;    // length of random range (EC)

    KDT kdtree;
    NaiveSearch naiveSearch;

    cout << endl << "Build points size: " << NUM_DATA << endl;
    cout << "Number of dimension: " << NUM_DIM << endl;
    cout << "Range of feature value: [" << MIN_VAL << ", " << MAX_VAL << "]"
         << endl;
    cout << "Generating random points for building dataset..." << endl;

    vector<Point> buildData = randomPoints(NUM_DATA, NUM_DIM, MIN_VAL, MAX_VAL);
    vector<Point> testData = randomPoints(NUM_TEST, NUM_DIM, MIN_VAL, MAX_VAL);

    kdtree.build(buildData);
    naiveSearch.build(buildData);

    Timer t;
    long long sumTime = 0;

    cout << "\nTest 1: nearest neighbor search" << endl << endl;
    cout << "\tQuery points size: " << NUM_TEST << ";" << endl << endl;

    cout << "\tTiming KD tree..." << endl;

    t.begin_timer();
    for (Point& p : testData) {
        kdtree.findNearestNeighbor(p);
    }
    sumTime = t.end_timer();
    cout << "\tTime taken: " << sumTime << " nanoseconds\n" << endl;

    cout << "\tTiming naive search..." << endl;
    t.begin_timer();
    for (Point& p : testData) {
        naiveSearch.findNearestNeighbor(p);
    }
    sumTime = t.end_timer();
    cout << "\tTime taken: " << sumTime << " nanoseconds\n" << endl;

    cout << "Test 2: range search (EC)" << endl << endl;
    cout << "\tQuery range size: " << NUM_TEST
         << "; Range length of each dimension: " << RANGE_LEN << ";" << endl
         << endl;
    vector<vector<pair<double, double>>> ranges;
    for (int i = 0; i < NUM_TEST; i++) {
        ranges.push_back(rangeRange(NUM_DIM, RANGE_LEN, MIN_VAL, MAX_VAL));
    }

    cout << "\tTiming KD tree..." << endl;
    t.begin_timer();
    for (vector<pair<double, double>>& range : ranges) {
        kdtree.rangeSearch(range);
    }
    sumTime = t.end_timer();
    cout << "\tTime taken: " << sumTime << " nanoseconds\n" << endl;

    cout << "\tTiming naive search..." << endl;
    t.begin_timer();
    for (vector<pair<double, double>>& range : ranges) {
        naiveSearch.rangeSearch(range);
    }
    sumTime = t.end_timer();
    cout << "\tTime taken: " << sumTime << " nanoseconds\n" << endl;

    return 0;
}