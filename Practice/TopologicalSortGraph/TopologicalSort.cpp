/*

Problem Statement#
Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering of its vertices such that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering.

Given a directed graph, find the topological ordering of its vertices.

Example 1:

Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
Output: Following are the two valid topological sorts for the given graph:
1) 3, 2, 0, 1
2) 3, 2, 1, 0
   
Example 2:
Input: Vertices=5, Edges=[4, 2], [4, 3], [2, 0], [2, 1], [3, 1]
Output: Following are all valid topological sorts for the given graph:
1) 4, 2, 3, 0, 1
2) 4, 3, 2, 0, 1
3) 4, 3, 2, 1, 0
4) 4, 2, 3, 1, 0
5) 4, 2, 0, 3, 1
  
Example 3:
Input: Vertices=7, Edges=[6, 4], [6, 2], [5, 3], [5, 4], [3, 0], [3, 1], [3, 2], [4, 1]
Output: Following are all valid topological sorts for the given graph:
1) 5, 6, 3, 4, 0, 1, 2
2) 6, 5, 3, 4, 0, 1, 2
3) 5, 6, 4, 3, 0, 2, 1
4) 6, 5, 4, 3, 0, 1, 2
5) 5, 6, 3, 4, 0, 2, 1
6) 5, 6, 3, 4, 1, 2, 0

*/


using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
 public:
  /* Educative.io way  -- NonRecursive  */
 /* static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> sortedOrder;
    // TODO: Write your code here
    //Create a adjaceny list and populate indegree
    unordered_map<int,vector<int>> adjMat;
    vector<int> inDegree;inDegree.resize(vertices,0);
    for(int i=0;i < vertices;i++)
    {
      adjMat[i] = {}; 
    }
    for(auto x:edges)
    {
      adjMat[x[0]].push_back(x[1]);
      inDegree[x[1]]++;
    }    
    queue<int> zeroDegNodes;
    //First add all the nodes with 0 degrees to 
    for(int i=0;i<vertices;i++)
    {
      if(inDegree[i] == 0)
      {
        zeroDegNodes.push(i);
      }
    }

    while(!zeroDegNodes.empty())
    {
      int nodeToAdd = zeroDegNodes.front();
      sortedOrder.push_back(nodeToAdd);
      zeroDegNodes.pop();
      for(auto x:adjMat[nodeToAdd])
      {
        inDegree[x] -= 1;
        if(inDegree[x] == 0) 
        {
          zeroDegNodes.push(x);
        }
      }
    }
    if(sortedOrder.size() != vertices)
    {
      cout<<endl<<"Cycle Detected";
      sortedOrder.clear();
    }
    return sortedOrder;
  }*/

  static void sortRecursive( int &vertices,unordered_map<int,vector<int>> &adjMat,
                                    bool *visited,int *inDegrees,vector<int> &out)
  {    
    for(int i=0;i< vertices;i++ )
    {
      if(visited[i] == false && inDegrees[i]==0)
      {
         out.push_back(i);
         visited[i] = true;
         for(auto x: adjMat[i])
         {
           inDegrees[x] -= 1;
         }
         sortRecursive( vertices,adjMat,visited,inDegrees,out);
      }
    }
    if(out.size() != vertices)
    {
      out.clear();
    }
  }

  static vector<int> sort(int vertices, const vector<vector<int>>& edges) 
  {
    vector<int> sortedOrder;

    unordered_map<int,vector<int>> adjMat;
    bool visited[vertices];
    int inDegrees[vertices];
    //Init
    for(int i=0;i<vertices;i++)
    {
      visited[i] = false;
      inDegrees[i] = 0;
      adjMat[i] = {};
    }
    //Populate Adj matrix
    for(auto x: edges)
    {
      inDegrees[x[1]] += 1;
      adjMat[x[0]].push_back(x[1]);
    }
    sortRecursive(vertices,adjMat,visited,inDegrees,sortedOrder);
    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
                             vector<int>{2, 1}, vector<int>{3, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
                             vector<int>{3, 2}, vector<int>{4, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}



