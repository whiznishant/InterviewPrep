/*Problem Statement#
Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.

Example 1:

Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each other.
Example 2:

Input: "Programming"
Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
Explanation: None of the repeating characters come next to each other.
Example 3:

Input: "aapa"
Output: ""
Explanation: In all arrangements of "aapa", atleast two 'a' will come together e.g., "apaa", "paaa".
*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
 public:
  struct compare
  {
    bool operator()( pair<char,int> &lhs, pair<char,int> &rhs)
    {
      return lhs.second < rhs.second;
    }
  };
  static string rearrangeString(const string &str) {
    // TODO: Write your code here
    unordered_map<char,int> freqMap;
    for(auto x: str)
      freqMap[x] += 1;
    
    priority_queue<pair<char,int>,vector<pair<char,int>>,compare> maxHeap;
    unordered_map<char,int>::iterator it = freqMap.begin();
    while(it != freqMap.end())
    {
      maxHeap.push(*it);
      it++;
    }

    string out;
    pair<char,int> prev('#',-1);
    while(!maxHeap.empty())
    {
      auto top = maxHeap.top();
      maxHeap.pop();
      top.second -=1;
      out += top.first;
      if(prev.second > 0)
        maxHeap.push(prev);      
      prev = top;
    }

    if(out.length() == str.length())
      return out;
    return "";
  } 
};

int main(int argc, char *argv[]) {
  /*cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;*/
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
