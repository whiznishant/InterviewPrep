/*
Problem Statement#
Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost. The cost of connecting two ropes is equal to the sum of their lengths.

Example 1:
Input: [1, 3, 11, 5]
Output: 33
Explanation: First connect 1+3(=4), then 4+5(=9), and then 9+11(=20). So the total cost is 33 (4+9+20)

Example 2:
Input: [3, 4, 5, 6]
Output: 36
Explanation: First connect 3+4(=7), then 5+6(=11), 7+11(=18). Total cost is 36 (7+11+18)

Example 3:
Input: [1, 3, 11, 5, 2]
Output: 42
Explanation: First connect 1+2(=3), then 3+3(=6), 6+5(=11), 11+11(=22). Total cost is 42 (3+6+11+22)
*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    int result = 0;
    // TODO: Write your code here
    priority_queue<int,vector<int>,std::greater<int>> minHeap(ropeLengths.begin(),ropeLengths.end());
    while(minHeap.size() > 1)
    {
      int sum = 0;
      sum = minHeap.top();
      minHeap.pop();
      sum += minHeap.top();
      minHeap.pop();
      minHeap.push(sum);
      result += sum;
    }
    return result;
  }
};


int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}


