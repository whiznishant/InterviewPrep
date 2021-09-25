/*
Given a string, sort it based on the decreasing frequency of its characters.

Example 1:

Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
Example 2:

Input: "abcbab"
Output: "bbbaac"
Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared only once.
*/

using namespace std;
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

struct compare
{
  bool operator()( const pair<char,int> &lhs,const pair<char,int> &rhs)
  {
    return lhs.second < rhs.second;
  }
};
class FrequencySort {
 public:
  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    // TODO: Write your code here
    unordered_map<char,int> freqmap;
    for(auto x:str)
      freqmap[x] += 1;

    priority_queue<pair<char,int>,vector<pair<char,int>>,compare> maxHeap;
    for(auto x: freqmap)  
      maxHeap.push(x);

    while( !maxHeap.empty() )
    {
        for(int i=0;i< maxHeap.top().second;i++)
        {
           sortedString += maxHeap.top().first;      
        }
        maxHeap.pop();
    }
    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
