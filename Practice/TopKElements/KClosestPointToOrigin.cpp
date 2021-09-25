/*
Given an array of points in a 2D2D plane, find ‘K’ closest points to the origin.

Example 1:

Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
Example 2:

Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
Output: [[1, 3], [2, -1]]

*/




using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }
};

struct comparator
{
  bool operator()(Point &lhs,Point &rhs)
  {
    return lhs.distFromOrigin() < rhs.distFromOrigin();
  }
};


class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    vector<Point> result;
    // TODO: Write your code here  
    result.assign(points.begin(),points.begin()+k);
    make_heap(result.begin(),result.end(),comparator());
    for(int i=k;i < points.size();i++)
    {
      if(points[i].distFromOrigin() < result.front().distFromOrigin())
      {
        pop_heap(result.begin(),result.end(),comparator());
        result.pop_back();
        result.push_back(points[i]);
        push_heap(result.begin(),result.end(),comparator());
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}
