/**
 * This program takes in two files: build data file and query data file.
 * For each query data, this program outputs its nearest neighbor in the
 * build data. The nearest neighbor searching is achieved using KD tree.
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "KDT.hpp"
#include "Point.hpp"

using namespace std;

/** Check if a given data file is valid */
bool fileValid(const char* fileName) {
    ifstream in;
    in.open(fileName, ios::binary);

    // Check if input file was actually opened
    if (!in.is_open()) {
        cout << "Invalid input file. No file was opened. Please try again.\n";
        return false;
    }

    // Check for empty file
    in.seekg(0, ios_base::end);
    unsigned int len = in.tellg();
    if (len == 0) {
        cout << "The file is empty. \n";
        return false;
    }
    in.close();
    return true;
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

    ifstream in;
    in.open(fileName, ios::binary);

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

int main(int argc, char* argv[]) {
    const int NUM_ARG = 3;

    // check for Arguments
    if (argc != NUM_ARG) {
        cout << "Invalid number of arguments.\n"
             << "Usage: ./main <build data filename> <query data filename>"
             << endl;
        return -1;
    }

    // check for valid file
    if (!fileValid(argv[1]) || !fileValid(argv[2])) return -1;

    KDT tree;
    vector<Point> buildPoints = readPoints(argv[1]);
    vector<Point> queryPoints = readPoints(argv[2]);

    tree.build(buildPoints);

    cout << "Size of KD tree: " << tree.size() << endl;
    cout << "Height of KD tree: " << tree.height() << endl;
    cout << "Nearest neighbor of each query point: " << endl;
    for (Point& query : queryPoints) {
        cout << *tree.findNearestNeighbor(query) << endl;
    }

    return 0;
}
