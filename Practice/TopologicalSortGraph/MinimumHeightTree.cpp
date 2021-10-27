/*
Minimum Height Trees (hard)#
We are given an undirected graph that has characteristics of a k-ary tree. In such a graph, we can choose any node as the root to make a k-ary tree. The root (or the tree) with the minimum height will be called Minimum Height Tree (MHT). There can be multiple MHTs for a graph. In this problem, we need to find all those roots which give us MHTs. Write a method to find all MHTs of the given graph and return a list of their roots.

Example 1:
Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
Output:[1, 2]
Explanation: Choosing '1' or '2' as roots give us MHTs. In the below diagram, we can see that the 
height of the trees with roots '1' or '2' is three which is minimum.


Example 2:
Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
Output:[0, 2]
Explanation: Choosing '0' or '2' as roots give us MHTs. In the below diagram, we can see that the 
height of the trees with roots '0' or '2' is three which is minimum.

Example 2:
Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
Output:[0, 2]
Explanation: Choosing '0' or '2' as roots give us MHTs. In the below diagram, we can see that the 
height of the trees with roots '0' or '2' is three which is minimum.

*/

/*********** Explaination here -------- https://leetcode.com/problems/minimum-height-trees/solution/ ************/
/*

Overview
As the hints suggest, this problem is related to the graph data structure. Moreover, it is closely related to the problems of Course Schedule and Course Schedule II. This relationship is not evident, yet it is the key to solve the problem, as one will see later.

First of all, as a straight-forward way to solve the problem, we can simply follow the requirements of the problem, as follows:

Starting from each node in the graph, we treat it as a root to build a tree. Furthermore, we would like to know the distance between this root node and the rest of the nodes. The maximum of the distance would be the height of this tree.

Then according to the definition of Minimum Height Tree (MHT), we simply filter out the roots that have the minimal height among all the trees.

The first step we describe above is actually the problem of Maximum Depth of N-ary Tree, which is to find the maximum distance from the root to the leaf nodes. For this, we can either apply the Depth-First Search (DFS) or Breadth-First Search (BFS) algorithms.

Without a rigid proof, we can see that the above straight-forward solution is correct, and it would work for most of the test cases.

However, this solution is not efficient, whose time complexity would be \mathcal{O}(N^2)O(N 
2
 ) where NN is the number of nodes in the tree. As one can imagine, it will result in Time Limit Exceeded exception in the online judge.

As a spoiler alert, in this article, we will present a topological sorting alike algorithm with time complexity of \mathcal{O}(N)O(N), which is also the algorithm to solve the well-known course schedule problems.

Approach 1: Topological Sorting
Intuition

First of all, let us clarify some concepts.

The distance between two nodes is the number of edges that connect the two nodes.

Note, normally there could be multiple paths to connect nodes in a graph. In our case though, since the input graph can form a tree from any node, as specified in the problem, there could only be one path between any two nodes. In addition, there would be no cycle in the graph. As a result, there would be no ambiguity in the above definition of distance.

The height of a tree can be defined as the maximum distance between the root and all its leaf nodes.

With the above definitions, we can rephrase the problem as finding out the nodes that are overall close to all other nodes, especially the leaf nodes.

If we view the graph as an area of circle, and the leaf nodes as the peripheral of the circle, then what we are looking for are actually the centroids of the circle, i.e. nodes that is close to all the peripheral nodes (leaf nodes).

example of graph

For instance, in the above graph, it is clear that the node with the value 1 is the centroid of the graph. If we pick the node 1 as the root to form a tree, we would obtain a tree with the minimum height, compared to other trees that are formed with any other nodes.

Before we proceed, here we make one assertion which is essential to the algorithm.

For the tree-alike graph, the number of centroids is no more than 2.

If the nodes form a chain, it is intuitive to see that the above statement holds, which can be broken into the following two cases:

If the number of nodes is even, then there would be two centroids.
If the number of nodes is odd, then there would be only one centroid.
example of centroids

For the rest of cases, we could prove by contradiction. Suppose that we have 3 centroids in the graph, if we remove all the non-centroid nodes in the graph, then the 3 centroids nodes must form a triangle shape, as follows:

triangle

Because these centroids are equally important to each other, and they should equally close to each other as well. If any of the edges that is missing from the triangle, then the 3 centroids would be reduced down to a single centroid.

However, the triangle shape forms a cycle which is contradicted to the condition that there is no cycle in our tree-alike graph. Similarly, for any of the cases that have more than 2 centroids, they must form a cycle among the centroids, which is contradicted to our condition.

Therefore, there cannot be more than 2 centroids in a tree-alike graph.

Algorithm

Given the above intuition, the problem is now reduced down to looking for all the centroid nodes in a tree-alike graph, which in addition are no more than two.

The idea is that we trim out the leaf nodes layer by layer, until we reach the core of the graph, which are the centroids nodes.

trim

Once we trim out the first layer of the leaf nodes (nodes that have only one connection), some of the non-leaf nodes would become leaf nodes.

The trimming process continues until there are only two nodes left in the graph, which are the centroids that we are looking for.

The above algorithm resembles the topological sorting algorithm which generates the order of objects based on their dependencies. For instance, in the scenario of course scheduling, the courses that have the least dependency would appear first in the order.

In our case, we trim out the leaf nodes first, which are the farther away from the centroids. At each step, the nodes we trim out are closer to the centroids than the nodes in the previous step. At the end, the trimming process terminates at the centroids nodes.

Implementation

Given the above algorithm, we could implement it via the Breadth First Search (BFS) strategy, to trim the leaf nodes layer by layer (i.e. level by level).

Initially, we would build a graph with the adjacency list from the input.

We then create a queue which would be used to hold the leaf nodes.

At the beginning, we put all the current leaf nodes into the queue.

We then run a loop until there is only two nodes left in the graph.

At each iteration, we remove the current leaf nodes from the queue. While removing the nodes, we also remove the edges that are linked to the nodes. As a consequence, some of the non-leaf nodes would become leaf nodes. And these are the nodes that would be trimmed out in the next iteration.

The iteration terminates when there are no more than two nodes left in the graph, which are the desired centroids nodes.

*/

using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

class MinimumHeightTrees {
 public:
  static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
    vector<int> minHeightTrees;
    // TODO: Write your code here
    unordered_map<int,vector<int>> adjMat;
    vector<int> inDegrees(nodes,0);
    
    //Init
    for(int i=0;i<nodes;i++)
    {
        adjMat[i] = {};
    }
    
    //Create the adjacency matrix
    for(auto x:edges)
    {
        adjMat[x[0]].push_back(x[1]);   //undirected graph, so both ways.
        inDegrees[x[1]]++; 
        adjMat[x[1]].push_back(x[0]);
        inDegrees[x[0]]++;
    }

    //Find nodes with one inDegrees. These are leafs which can be pruned.
    queue<int> oneInDegreeNode;
    for(int i=0;i < nodes;i++)
    {
        if(inDegrees[i] == 1)
            oneInDegreeNode.push(i);
    }

    //Start pruning till we are left with just 1 or two nodes
    int totalNodesToBePruned = nodes;
    while( totalNodesToBePruned > 2 )
    {
        int sz = oneInDegreeNode.size();
        totalNodesToBePruned -= sz;
        for(int i=0;i < sz;i++ )
        {
            int node = oneInDegreeNode.front();
            oneInDegreeNode.pop();
            for(auto x: adjMat[node])
            {
                inDegrees[x]--;
                if( inDegrees[x] == 1 )
                    oneInDegreeNode.push(x);
            }
        }

    }
    while(!oneInDegreeNode.empty())
    {
        minHeightTrees.push_back(oneInDegreeNode.front());
        oneInDegreeNode.pop();
    }
    return minHeightTrees;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = MinimumHeightTrees::findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
