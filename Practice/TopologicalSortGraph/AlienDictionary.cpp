/*
There is a dictionary containing words from an alien language for which we don’t know the ordering of the alphabets. Write a method to find the correct order of the alphabets in the alien language. It is given that the input is a valid dictionary and there exists an ordering among its alphabets.

Example 1:

Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
from the given words we can conclude the following ordering among its characters:

1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"
Example 2:

Input: Words: ["cab", "aaa", "aab"]
Output: cab
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'

From the above two points, we can conclude that the correct character order is: "cab"
Example 3:

Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
Output: ywxz
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'

From the above five points, we can conclude that the correct character order is: "ywxz"

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    string sortedOrder;
    
    set<char> nodeNames;
    unordered_map<char, vector<char>> adjMap;
    int lastNodeIdx = 0;
    for(int i=0;i < words.size()-1; i++)
    {
      int word1Size = words[i].length();
      int word2Size = words[i+1].length();

      int maxIter = min(word1Size,word2Size);
      int idx = 0;
      while( idx < maxIter) 
      {
        nodeNames.insert(words[i][idx]);
        nodeNames.insert(words[i+1][idx]);
        if(words[i][idx] != words[i+1][idx])
        {
          char c = words[i+1][idx];
          if( find(adjMap[words[i][idx]].begin(),adjMap[words[i][idx]].end(),c) 
               ==  adjMap[words[i][idx]].end()  && words[i][idx] != words[i+1][idx])
          {
            adjMap[words[i][idx]].push_back(words[i+1][idx]); // Insert non duplicates
          }
          break;
        }
        idx++;
      }
    }
    //populate adjMap and inDegrees for all the nodes
    unordered_map<char,int> inDegrees;
    for(auto x:nodeNames)
    {
      if(adjMap.find(x) == adjMap.end())
        adjMap[x] = {};
      inDegrees[x] = 0;
    }

    for(auto node:nodeNames )   
    {
      for(auto childnode: adjMap[node])
      {
         inDegrees[childnode]++;         
      }
    }
    
    queue<char> zeroDegNodes;
    //Find the zero degree node
    for(auto node:nodeNames )   
    {
      if(inDegrees[node] == 0)
        zeroDegNodes.push(node);
    }

    while(!zeroDegNodes.empty())
    {
      int curr = zeroDegNodes.front();
      sortedOrder.push_back(curr);
      zeroDegNodes.pop();
      for(auto x:adjMap[curr])
      {
        inDegrees[x]--;
        if(inDegrees[x] == 0)
          zeroDegNodes.push(x);
      }
    }
    return sortedOrder;
  }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}



