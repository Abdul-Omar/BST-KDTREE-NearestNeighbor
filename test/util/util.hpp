#include <gtest/gtest.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "BST.hpp"
#include "KDT.hpp"

/**
 * Read one data from file stream to vector
 */
template <typename T>
static void fromFileStream(ifstream& ifs, vector<T>& vec) {
    T val;
    ifs >> val;
    vec.push_back(val);
}

/**
 * This overload is needed for strings because the data we use for
 * strings, the actor names, are one per line, and whitespace is
 * included as a part of the name, whereas the input operator breaks
 * the file up by tokens, separating names into two values.
 */
void fromFileStream(ifstream& ifs, vector<string>& vec) {
    string val;
    getline(ifs, val);

    if (val == "") {
        return;
    }

    // On Windows machines, it's possible for the test files
    // to be in CLRF. If this is the case, strip the extraneous
    // CR symbol
    val = val.substr(0, val.find('\r'));
    vec.push_back(val);
}

/** Check if the give file is valid */
void checkValidFile(ifstream& ifs, string filename) {
    // Allow the tests to be run from multiple directories
    // by trying other paths if the current one is not found
    if (!ifs.is_open()) {
        ifs.open("data/" + filename);
    }
    if (!ifs.is_open()) {
        ifs.open("../data/" + filename);
    }

    ASSERT_TRUE(ifs.is_open());
    ASSERT_FALSE(ifs.bad());
    ifs.seekg(0, ios_base::end);

    // Assert that the file is not empty
    ASSERT_GT(ifs.tellg(), 0);
    ifs.seekg(0, ios_base::beg);
}

/**
 * Loads a vector with all of the tokens found in a given
 * file.
 */
template <typename T>
void loadVectorFromFile(string filename, vector<T>& vec) {
    ifstream ifs(filename);
    checkValidFile(ifs, filename);

    while (!ifs.eof()) {
        fromFileStream(ifs, vec);
    }
    ifs.close();
}

/**
 * Inserts all data from a vector into a BST.
 */
template <typename T>
void insertIntoBST(vector<T>& vec, BST<T>& bst) {
    auto vit = vec.begin();
    auto ven = vec.end();

    for (; vit != ven; ++vit) {
        bst.insert(*vit);
    }
}

/**
 *  Read all lines from the file and convert them to a vector
 *  of data points
 */
vector<Point> readPoints(const char* fileName) {
    vector<Point> result;
    string line;
    unsigned int numDim = 0;
    double data = 0;

    ifstream in(fileName);
    checkValidFile(in, fileName);

    // count number of dimensions
    getline(in, line);
    stringstream lineStream(line);
    while (lineStream >> data) numDim++;

    // Resets the stream to beginning of file
    in.seekg(0, ios_base::beg);

    // read the data and convert them to data points
    while (!in.eof()) {
        vector<double> features;
        for (unsigned int i = 0; i < numDim; i++) {
            in >> data;
            if (!in.fail()) {
                features.push_back(data);
            }
        }
        if (!in.fail()) {
            result.push_back(Point(features));
        }
    }
    in.close();
    return result;
}