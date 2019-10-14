/*
 *  Filename: KDT.hpp
 *  Author: Abdikhalik Ahmed/Andrew Masters
 *  UserId: 
 *  Date: 10/4/2019
 *  Sources of help:TextBook
*/



#ifndef KDT_HPP
#define KDT_HPP

#include <math.h>     // pow, abs
#include <algorithm>  // sort, max, min
#include <limits>     // numeric_limits<type>::max()
#include <vector>     // vector<typename>
#include "Point.hpp"
#include <math.h>
#include <limits>

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
    double threshold = numeric_limits<double>::infinity();

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

    /*
    * Function Name: build()
    * Function Prototype:build(vector<Point>& points);
    * Description: this is a wrapper function that calls buildSubtree()
    * which builds the KD-tree by repeatedly sorting points on current Dimension   
    * Parameters:
                points: vector of multi_dimensinal points to build the tree
    * Return Value: NONE
    */
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

    /*
    * Function Name: findNearestNeighbor()
    * Function Prototype:findNearestNeighbor(Point& queryPoint);
    * Description: this function finds the nearest closest point to queryPoint  
    * Parameters:
                 queryPoint: the point whose closest points in the
                 tree we are trying to find

    * Return Value: return the closest point;
    */
    Point* findNearestNeighbor(Point& queryPoint) {
        //if(size() == 1) return &(root->point);
	 
	findNNHelper(root, queryPoint, 0);

	return &nearestNeighbor;
    }

    /*** Extra credit */
    vector<Point> rangeSearch(vector<pair<double, double>>& queryRegion) {
       return {};
    }


     /*
    * Function Name: size()
    * Function Prototype:size();
    * Description: this function returns the number of elements in the tree
    * Parameters: NONE

    * Return Value: size of tree
    */
    unsigned int size() const { return isize; }

     /*
    * Function Name: height()
    * Function Prototype:height();
    * Description: this function returns height of the tree

    * Return Value: height of tree
    */
    int height() const { return height(root); }

  private:
    /*
    * Function Name: buildSubtree()
    * Function Prototype:KDNode* buildSubtree(vector<Point>& points, unsigned int start,
                         unsigned int end, unsigned int curDim, int height)
    * Description: this function recursively builds the KD tree by repeatedly sorting
    *              points on the current dimension of comparison  
    * Parameters:
                 points: vector holding points to construct tree with
                 start:  the position of the point to start sorting from
                 end:     the  position of the point to end sorting at
                 curDim:   the current axis of comparison
                 height:    the current height of the tree

    * Return Value: return root node of the tree
    */
    KDNode* buildSubtree(vector<Point>& points, unsigned int start,
                         unsigned int end, unsigned int curDim, int height) {
        unsigned int middle =  floor((start + end) / 2);
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
        sort(points.begin() + start, points.begin() + end, CompareValueAt(curDim));

        // this node holds the median point
        KDNode* node = new KDNode(points[middle]);
        // everything else goes to its left and right
        node->left = buildSubtree(points, start, middle, curDim, height + 1);
	
        node->right = buildSubtree(points, middle + 1, end, curDim, height + 1);
        isize++;      // increment size
	iheight = height;
        return node;  // pointer to root;
    }

     /*
    * Function Name: findNNHelper()
    * Function Prototype:  (KDNode* node, Point& queryPoint, unsigned int curDim)
    * Description: this function is a helper method of findNearestNeighbor function  
    * Parameters:
                 node: root of the tree
                 queryPoint: the point whose closest we are finding
                 curDim:   the current axis of comparisonnnnn                
    * Return Value: NONE
    */
    void findNNHelper(KDNode* node, Point& queryPoint, unsigned int curDim) {
        
        if(!node) return;//base case

	double distance = 0.0;//the currentBestDistance
	
	numDim = node->point.numDim;
       
	/*current distance */
        node->point.setDistToQuery(queryPoint);
        
	distance = node->point.distToQuery;

        // if we have found a smaller distance
        if (distance < threshold) {
	  // current closest point
	  nearestNeighbor = node->point;

	  // current closest distance
	  threshold = distance;
        }
    
           
       // if value of queryPoint in current axis is less,
       if (queryPoint.valueAt(curDim) <= node->point.valueAt(curDim)) {
	 
	 	 //check left first
         findNNHelper(node->left, queryPoint, ((curDim  + 1) % numDim));
	 
	 //check if there is a closer pont on the other side
	 if (queryPoint.valueAt(curDim) + sqrt(threshold) >= node->point.valueAt(curDim)) {
	   
	   findNNHelper(node->right, queryPoint, ((curDim + 1) % numDim));
	 }
       }
    
       else {
         	 	       //check right first
	 findNNHelper(node->right, queryPoint, (curDim + 1) % numDim);
	 //check if there might be a point on the other side
	 if(queryPoint.valueAt(curDim) - sqrt(threshold) <= node->point.valueAt(curDim )) {
	  
	   findNNHelper(node->left, queryPoint, ((curDim + 1)% numDim));
	}
      }
	
    }

    /** Extra credit */
    void rangeSearchHelper(KDNode* node, vector<pair<double, double>>& curBB,
                           vector<pair<double, double>>& queryRegion,
                           unsigned int curDim) {}

    /*
    * Function Name: deleteAll()
    * Function Prototype:static void deleteAll(KDNode* n) ;
    * Description: this function deletes all nodes in the tree
    * Parameters:
                n:  the root of the tree to delete
    * Return Value: NONE
    */
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
    //

    int height (KDNode* root)const { 
    
      if(!root) return -1;

      return 1 + max(height(root->left), height(root->right));
    
    }
};
#endif  // KDT_HPP
