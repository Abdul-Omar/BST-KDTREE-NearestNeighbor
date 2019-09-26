/**
 * Naive implementation of nearest neightbor searching and range searching
 */

#ifndef NaiveSearch_hpp
#define NaiveSearch_hpp

#include <algorithm>
#include <vector>
#include "Point.hpp"

class NaiveSearch {
  private:
    vector<Point> points;
    Point nearestNeighbor;

    /** Check if the given point is contained in regionQuery */
    bool isContained(Point& point, vector<pair<double, double>>& regionQuery) {
        for (unsigned int i = 0; i < point.numDim; i++) {
            if (point.features[i] < regionQuery[i].first ||
                point.features[i] > regionQuery[i].second) {
                return false;
            }
        }
        return true;
    }

  public:
    NaiveSearch() {}

    /** Initialize the data points */
    void build(vector<Point>& points) { this->points = points; }

    /** Find the nearest neighbor of the given query point */
    Point* findNearestNeighbor(Point& queryPoint) {
        if (points.size() == 0) return nullptr;

        points[0].setDistToQuery(queryPoint);
        double minDist = points[0].distToQuery;
        nearestNeighbor = points[0];

        // simply find the point with min distToQuery
        for (Point& point : points) {
            point.setDistToQuery(queryPoint);
            if (point.distToQuery < minDist) {
                minDist = point.distToQuery;
                nearestNeighbor = point;
            }
        }
        return &nearestNeighbor;
    }

    /** Return a set of points that are contained in regionQuery */
    vector<Point> rangeSearch(vector<pair<double, double>>& regionQuery) {
        // simply check each point and see if it is contained in region
        vector<Point> result;
        for (Point& point : points) {
            if (isContained(point, regionQuery)) {
                result.push_back(point);
            }
        }
        return result;
    }
};

#endif /* NaiveSearch_hpp */
