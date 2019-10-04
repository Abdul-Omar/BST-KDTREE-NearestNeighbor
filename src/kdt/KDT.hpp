#ifndef KDT_HPP
#define KDT_HPP

#include <math.h>     // pow, abs
#include <algorithm>  // sort, max, min
#include <limits>     // numeric_limits<type>::max()
#include <vector>     // vector<typename>
#include "Point.hpp"

using namespace std;

class KDT {
  private:
    /** Inner class which defines a KD tree node */
    class KDNode {
      public:
        KDNode* left;
        KDNode* right;
        Point point;

        KDNode(Point point) : point(point) {}
    };

    // root of KD tree
    KDNode* root;

    // number of dimension of data points
    unsigned int numDim;

    // smallest squared distance to query point so far
    double threshold;

    unsigned int isize;
    int iheight;

    // current nearest neighbor
    Point nearestNeighbor;

    // Extra Credit: smallest bounding box containing all points
    vector<pair<double, double>> boundingBox;

    // Extra Credit: result container
    // (Set during searching, and clear before another search)
    vector<Point> pointsInRange;

  public:
    /** Constructor of KD tree */
    KDT()
        : root(0),
          numDim(0),
          threshold(numeric_limits<double>::max()),
          isize(0),
          iheight(-1) {}

    /** Destructor of KD tree */
    virtual ~KDT() { deleteAll(root); }

    /** TODO */
    void build(vector<Point>& points) {
        unsigned int size = points.size();
        // if there is only one point
        if (size == 1) {
            root = new KDNode(points[0]);
            isize++;
            iheight++;
            return;
        }
        // else recursively build tree
        root = buildSubtree(points, 0, size, 0, 0);
    }

    /** TODO */
    Point* findNearestNeighbor(Point& queryPoint) {
        findNNHelper(root, queryPoint, 0);
    }

    /** Extra credit */
    vector<Point> rangeSearch(vector<pair<double, double>>& queryRegion) {
        return {};
    }

    /** TODO */
    unsigned int size() const { return isize; }

    /** TODO */
    int height() const { return iheight; }

  private:
    /** TODO */
    KDNode* buildSubtree(vector<Point>& points, unsigned int start,
                         unsigned int end, unsigned int curDim, int height) {
        unsigned int middle = (start + end) / 2;
        // base case
        if (start >= end) {
            return nullptr;
        }
        // get current dimension for sorting
        curDim = height % points[0].numDim;

        // CompareValueAt* comp = new CompareValueAt;
        // fil dimension of current evaluation
        // CompareValueAt comp = CompareValueAt(curDim);

        // sort elements at current dimension
        sort(points.begin(), points.end(), CompareValueAt(curDim));

        // this node holds the median point
        KDNode* node = new KDNode(points[middle]);
        // everything else goes to its left and right
        node->left = buildSubtree(points, start, middle, curDim, height + 1);
        node->right = buildSubtree(points, middle + 1, end, curDim, height + 1);
        isize++;      // increment size
        return node;  // pointer to root;
    }

    /** TODO */
    void findNNHelper(KDNode* node, Point& queryPoint, unsigned int curDim) {
        /*base case,at leaf node*/
        if (node->left == nullptr && node->right == nullptr) {
            /*current best distance */
            node->point.setDistToQuery(queryPoint);
            double thresh = node->point.distToQuery;

            // if we have found a smaller distance
            if (thresh < threshold) {
                // current closest point
                nearestNeighbor = node->point;

                // current closest distance
                threshold = thresh;
            }
        } else {
            // if value of queryPoint in current axis is less,
            if (queryPoint.valueAt(curDim) <= node->point.valueAt(curDim)) {
                // if q.x - node.x is less than threshold
                if (queryPoint.valueAt(curDim) - node->point.valueAt(curDim) <=
                    threshold) {
                    // check left subtree
                    findNNHelper(node->left, queryPoint, curDim);
                }
                //
                if (queryPoint.valueAt(curDim) + threshold >
                    node->point.valueAt(curDim)) {
                    findNNHelper(node->right, queryPoint, curDim);
                }
            }
            // nearest neighbor is in right subtree
            else {
                if (queryPoint.valueAt(curDim) + threshold >
                    node->point.valueAt(curDim))

                    findNNHelper(node->right, queryPoint, curDim);
            }
            if (queryPoint.valueAt(curDim) - node->point.valueAt(curDim) <=
                threshold) {
                findNNHelper(node->left, queryPoint, curDim);
            }
        }
    }

    /** Extra credit */
    void rangeSearchHelper(KDNode* node, vector<pair<double, double>>& curBB,
                           vector<pair<double, double>>& queryRegion,
                           unsigned int curDim) {}

    /** TODO */
    static void deleteAll(KDNode* n) {
        /* Pseudocode:
            if current node is null: return;
            recursively delete left sub-tree
            recursively delete right sub-tree
            delete current node
         */
        if (!n) {
            return;
        }

        deleteAll(n->left);   // delete left subtree
        deleteAll(n->right);  // delete right subtree
        delete n;             // delete root
    }

    // Add your own helper methods here
};
#endif  // KDT_HPP
