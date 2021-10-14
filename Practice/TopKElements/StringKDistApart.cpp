/*
Rearrange String K Distance Apart (hard) #
Given a string and a number ‘K’, find if the string can be rearranged such that the same characters are at least ‘K’ distance apart from each other.

Example 1:

Input: "mmpp", K=2
Output: "mpmp" or "pmpm"
Explanation: All same characters are 2 distance apart.
Example 2:

Input: "Programming", K=3
Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
Explanation: All same characters are 3 distance apart.
Example 3:

Input: "aab", K=2
Output: "aba"
Explanation: All same characters are 2 distance apart.
Example 4:

Input: "aappa", K=3
Output: ""
Explanation: We cannot find an arrangement of the string where any two 'a' are 3 distance apart.
*/

/**************************  REVISE THIS AGAIN IMPORTANT ************************************/
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeStringKDistanceApart {
 public:
  struct compare
  {
     bool operator() ( pair<char,int> &lhs, pair<char,int> &rhs )
     {
          return lhs.second < rhs.second;
     }
  };
  static string reorganizeString(const string &str, int k) {
    // TODO: Write your code here
    unordered_map<char,int> freqMap;
    for(auto x:str)
     freqMap[x] += 1;

    priority_queue<pair<char,int>,vector<pair<char,int>>,compare> maxHeap;
    for(auto x: freqMap)
     maxHeap.push(x);

    queue<pair<char,int>> previousKthElement;  
    string out;

    while(!maxHeap.empty())
    {
         auto top = maxHeap.top();
         maxHeap.pop();
         out += top.first;
         top.second -= 1;
         previousKthElement.push(top);
         if(previousKthElement.size() == k )
         {
           auto elem = previousKthElement.front();
           if(elem.second > 0 )
               maxHeap.push(elem);
           previousKthElement.pop();
         }
    }
    if(out.length() == str.length())  
      return out;
    return "";
  }
};

int main(int argc, char *argv[]) {
  /*cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("Programming", 3) << endl;*/
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("mmpp", 2) << endl;
  /*cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aab", 2) << endl;
  cout << "Reorganized string: " << RearrangeStringKDistanceApart::reorganizeString("aappa", 3)
       << endl;*/
}


