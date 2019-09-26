/**
 * Point class used to represent data with features
 */

#ifndef Point_hpp
#define Point_hpp

#include <math.h>
#include <string>
#include <vector>

using namespace std;

/** The data point with given features **/
class Point {
  private:
    double DELTA = 0.00005;

  public:
    vector<double> features;

    // number of features
    unsigned int numDim;

    // squared Euclidean distance to current query point
    double distToQuery;

    /** Default constructor */
    Point() {}

    /** Constructor that defines a data point with features and certain label */
    Point(vector<double> features)
        : features(features), numDim((int)features.size()) {}

    /** Set the square distance to the current query point */
    void setDistToQuery(const Point& queryPoint) {
        double result = 0;
        for (unsigned int i = 0; i < numDim; i++) {
            result += pow(features[i] - queryPoint.features[i], 2.0);
        }
        distToQuery = result;
    }

    /** Return the value at dimension d of this point */
    double valueAt(int d) { return features[d]; }

    /** Equals operator */
    bool operator==(const Point& other) const {
        if (numDim != other.numDim) return false;
        for (unsigned int i = 0; i < numDim; i++) {
            if (abs(features[i] - other.features[i]) > DELTA) {
                return false;
            }
        }
        return true;
    }

    /** Not-equals operator */
    bool operator!=(const Point& other) const { return !((*this) == other); }
};

/** PLEASE DO NOT MODIFY THIS METHOD **/
std::ostream& operator<<(std::ostream& out, const Point& data) {
    string s = "(";
    for (unsigned int i = 0; i < data.numDim - 1; i++) {
        s += to_string(data.features[i]) + ", ";
    }
    s += to_string(data.features[data.numDim - 1]) + ")";
    out << s;
    return out;
}

/** The comparator used in sorting points based on values on
    certain dimension */
struct CompareValueAt {
    int dimension;
    CompareValueAt(int dimension) { this->dimension = dimension; }
    bool operator()(const Point& p1, const Point& p2) {
        return p1.features[dimension] < p2.features[dimension];
    }
};

// Example of another comparator. When used in sort(), 
// points will be ordered from small to large distToQurey
// struct CompareDist {
//     bool operator()(const Point& p1, const Point& p2) {
//         return p1.distToQuery < p2.distToQuery;
//     }
// } compDist;

#endif /* Point_hpp */
