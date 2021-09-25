#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
#include <algorithm>

using namespace std;

//suboptimal O(n) approach , can use a min heap here . (or std::priority_queue  ??)
int GetNextUnvisitedNodeWithLeastDistance(vector<bool> &visited, vector<int> &distances)
{
    int numNodes = distances.size();
    int minDist = INT_MAX;
    int minNode = -1;
    for(int i=0;i<numNodes;i++)
    {
        if(visited[i] == false)
        {
            if(distances[i] < minDist )
            {
                minDist = distances[i];
                minNode = i;
            }
        }
    }
    return minNode;
}

//O(n2) approach
vector<int> DjikstrasShortestPath( vector<string> &connections,int start,int end)
{
    int numNodes  = connections[0].size();

    vector<bool> visited(numNodes,false);
    vector<int>  distances(numNodes,INT_MAX);
    vector<int>  path(numNodes,-1);

    //For djikstra to work correctly changing the self loops to 0;
    for(int i=0;i<connections.size();i++)
    {
        (connections[i])[i] = '0';
    }

    int numVisited = 0;
    distances[start] = 0;
    // Till we have not visited the end node . Once we have visited the end we are sure we have seen the shortest path to it from the start.
    while(visited[end] != true && numVisited != numNodes ) 
    {
        int node = GetNextUnvisitedNodeWithLeastDistance(visited,distances);
        if(distances[node] < INT_MAX) //If this node itself is unreachable , it is useless to check its children
        {
            int len = connections[node].length();
            for(int i=0;i<len;i++)
            {
                if(connections[node][i] == '1')
                {
                    if(distances[i] > distances[node] + 1 )
                    {
                        distances[i] = distances[node] + 1;
                        path[i] = node;
                    }
                }
            }
            visited[node] = true;
            numVisited += 1;
        }
    }
    vector<int> pathout;
    int pathIdx = end;
    while(pathIdx != -1 )
    {
        pathout.push_back(pathIdx);
        pathIdx = path[pathIdx];         
    }
    std::reverse(pathout.begin(),pathout.end());
    return pathout;
}

int main()
{
    vector<string> connections =
            {"11000000000000000000000000000000000000000000000000",
            "01100000000000000000000000000000000000000000000000",
            "00110000000000000000000000000000000000000000000000",
            "00011000000000000000000000000000000000000000000000",
            "00001100000000000000000000000000000000000000000000",
            "00000110000000000000000000000000000000000000000000",
            "00000011000000000000000000000000000000000000000000",
            "00000001100000000000000000000000000000000000000000",
            "00000000110000000000000000000000000000000000000000",
            "00000000011000000000000000000000000000000000000000",
            "00000000001100000000000000000000000000000000000000",
            "00000000000110000000000000000000000000000000000000",
            "00000000000011000000000000000000000000000000000000",
            "00000000000001100000000000000000000000000000000000",
            "00000000000000110000000000000000000000000000000000",
            "00000000000000011000000000000000000000000000000000",
            "00000000000000001100000000000000000000000000000000",
            "00000000000000000110000000000000000000000000000000",
            "00000000000000000011000000000000000000000000000000",
            "00000000000000000001100000000000000000000000000000",
            "00000000000000000000110000000000000000000000000000",
            "00000000000000000000011000000000000000000000000000",
            "00000000000000000000001100000000000000000000000000",
            "00000000000000000000000110000000000000000000000000",
            "00000000000000000000000011000000000000000000000000",
            "00000000000000000000000001100000000000000000000000",
            "00000000000000000000000000110000000000000000000000",
            "00000000000000000000000000011000000000000000000000",
            "00000000000000000000000000001100000000000000000000",
            "00000000000000000000000000000110000000000000000000",
            "00000000000000000000000000000011000000000000000000",
            "00000000000000000000000000000001100000000000000000",
            "00000000000000000000000000000000110000000000000000",
            "00000000000000000000000000000000011000000000000000",
            "00000000000000000000000000000000001100000000000000",
            "00000000000000000000000000000000000110000000000000",
            "00000000000000000000000000000000000011000000000000",
            "00000000000000000000000000000000000001100000000000",
            "00000000000000000000000000000000000000110000000000",
            "00000000000000000000000000000000000000011000000000",
            "00000000000000000000000000000000000000001100000000",
            "00000000000000000000000000000000000000000110000000",
            "00000000000000000000000000000000000000000011000000",
            "00000000000000000000000000000000000000000001100000",
            "00000000000000000000000000000000000000000000110000",
            "00000000000000000000000000000000000000000000011000",
            "00000000000000000000000000000000000000000000001100",
            "00000000000000000000000000000000000000000000000110",
            "00000000000000000000000000000000000000000000000011",
            "10000000000000000000000000000000000000000000000001"};

    int start = 45, end = 10;

    vector<int> path = DjikstrasShortestPath(connections,start,end);
    for(auto x:path)
        cout<<" "<<x;

    return 0;
}










/*

Problem Statement
    	In a large wireless network, there might be a large number of wireless nodes that can act as repeaters. Some of these nodes are within range of some other nodes, and thus some nodes can transmit to each other, while other nodes cannot. Additionally, some nodes transmit stronger signals than others, so just because node a can broadcast to node b does not mean that node b can broadcast to node a.



You will be given a String[], connections. Each element of connections will have the same number of characters as there are elements in connections, and each character will be either a '1' (one) or a '0' (zero). There is a connection from node i to node j if and only if character j of element i of connections is a '1'.



Now, a major contributor to latency in the network is the number of hops that a data packet must undergo on its route from one node to another. A data packet undergoes one hop for every node that transmits it on its path from one node to another. To help reduce latency, you are to find the path that requires the least number of hops to get a data packet from node start to node end. You should return this path as an int[], whose elements represent the nodes that transmit the data, in order. If more than one path takes the same minimum number of hops, you should return the one that comes first lexicographically. If there is no path from start to end, return an empty int[], {}.
 
Definition
    	
Class:	WirelessNetwork
Method:	findPath
Parameters:	String[], int, int
Returns:	int[]
Method signature:	int[] findPath(String[] connections, int start, int end)
(be sure your method is public)
    
 
Notes
-	An int[], n, comes before an int[], m, lexicographically if and only if, for the first element in which they differ, the element of n is smaller.
 
Constraints
-	connections will contain between 2 and 50 elements, inclusive.
-	Each element of connections will have the same number of characters as there are elements in connections.
-	Each character of each element of connections will be a '1' (one) or a '0' (zero).
-	start will be between 0 and the number of elements in connections - 1, inclusive.
-	end will be between 0 and the number of elements in connections - 1, inclusive.
-	start and end will not be the same.
-	Character i of element i will be '1', for all i.
 
Examples
0)	
    	
{"111",
 "111",
 "111"}
0
2
Returns: {0, 2 }
Here, all of the nodes are connected, so the shortest path is direct from the start to the end.
1)	
    	
{"110",
 "111",
 "111"}
0
2
Returns: {0, 1, 2 }
In this case, there is no direct connection from 0 to 2, so the shortest path goes through 1.
2)	
    	
{"1111",
 "0111",
 "1111",
 "1111"}
1
0
Returns: {1, 2, 0 }
Here, there are two paths of equal, shortest length from 1 to 0:

{1,2,0}

{1,3,0}

Of these, {1,2,0} comes first lexicographically, so it is returned.
3)	
    	
{"11000000000000000000000000000000000000000000000000",
 "01100000000000000000000000000000000000000000000000",
 "00110000000000000000000000000000000000000000000000",
 "00011000000000000000000000000000000000000000000000",
 "00001100000000000000000000000000000000000000000000",
 "00000110000000000000000000000000000000000000000000",
 "00000011000000000000000000000000000000000000000000",
 "00000001100000000000000000000000000000000000000000",
 "00000000110000000000000000000000000000000000000000",
 "00000000011000000000000000000000000000000000000000",
 "00000000001100000000000000000000000000000000000000",
 "00000000000110000000000000000000000000000000000000",
 "00000000000011000000000000000000000000000000000000",
 "00000000000001100000000000000000000000000000000000",
 "00000000000000110000000000000000000000000000000000",
 "00000000000000011000000000000000000000000000000000",
 "00000000000000001100000000000000000000000000000000",
 "00000000000000000110000000000000000000000000000000",
 "00000000000000000011000000000000000000000000000000",
 "00000000000000000001100000000000000000000000000000",
 "00000000000000000000110000000000000000000000000000",
 "00000000000000000000011000000000000000000000000000",
 "00000000000000000000001100000000000000000000000000",
 "00000000000000000000000110000000000000000000000000",
 "00000000000000000000000011000000000000000000000000",
 "00000000000000000000000001100000000000000000000000",
 "00000000000000000000000000110000000000000000000000",
 "00000000000000000000000000011000000000000000000000",
 "00000000000000000000000000001100000000000000000000",
 "00000000000000000000000000000110000000000000000000",
 "00000000000000000000000000000011000000000000000000",
 "00000000000000000000000000000001100000000000000000",
 "00000000000000000000000000000000110000000000000000",
 "00000000000000000000000000000000011000000000000000",
 "00000000000000000000000000000000001100000000000000",
 "00000000000000000000000000000000000110000000000000",
 "00000000000000000000000000000000000011000000000000",
 "00000000000000000000000000000000000001100000000000",
 "00000000000000000000000000000000000000110000000000",
 "00000000000000000000000000000000000000011000000000",
 "00000000000000000000000000000000000000001100000000",
 "00000000000000000000000000000000000000000110000000",
 "00000000000000000000000000000000000000000011000000",
 "00000000000000000000000000000000000000000001100000",
 "00000000000000000000000000000000000000000000110000",
 "00000000000000000000000000000000000000000000011000",
 "00000000000000000000000000000000000000000000001100",
 "00000000000000000000000000000000000000000000000110",
 "00000000000000000000000000000000000000000000000011",
 "10000000000000000000000000000000000000000000000001"}
45
10
Returns: {45, 46, 47, 48, 49, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
This input represents a large directed circle, where the only connections are from nodes i to node i+1, for 0 <= i < 49, and a connection from node 49 to node 0. Thus, to get from node 45 to node 10, we first go from 45 to 46 to 47, and so on up to 49, where we loop around to node 0 and continue counting up to 10.
4)	
    	
{"10","01"}
0
1
Returns: { }
5)	
    	
{"111000100",
 "110001010",
 "011001100",
 "010100010",
 "010011111",
 "110011010",
 "011010111",
 "010100011",
 "111100011"}
8
4
Returns: {8, 0, 6, 4 }

*/