/*
Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n!n! permutations.

Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.
Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char,int> minReqd, currFound;
    int matchReq = 0, matchFound = 0;
    int left = 0,right = 0;
    //Find min required elements;
    for(auto x:pattern)
      minReqd[x] += 1;
    matchReq =  minReqd.size();
    
    
    while(right < str.length())
    {
      //These pattern has to be contiguous 
      // So if the char is not found in the window we can move our left and right to next element.
      // and start a fresh search.
      if( minReqd.find(str[right]) == minReqd.end()) // not found
      {
        right++;
        left = right;
        matchFound = 0;
        currFound.clear();
        continue;
      }
      currFound[str[right]] += 1;
      if(currFound[str[right]] > minReqd[str[right]])
      {
          while(str[left] != str[right] )
          {
            if(currFound[str[left]] ==  minReqd[str[left]])
            {
              matchFound--;
            }
            currFound[str[left]] -= 1;
            if(currFound[str[left]] == 0)
              currFound.erase(str[left]);            
            left++;
          }
      }
      
      if ( currFound[str[right]] == minReqd[str[right]] )
        matchFound++;
      
      if(matchFound == matchReq)
        return true;

      right++;
    }
    return false;
  }
};


int main(int argc, char *argv[]) {
  cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;

  cout << "Permutation exist: " << StringPermutation::findPermutation("ooolleoooleh","hello") << endl;

  cout << "Permutation exist: " << StringPermutation::findPermutation("dcda","adc") << endl;
}




