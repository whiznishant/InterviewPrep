/*
Given a string and a pattern, find all anagrams of the pattern in the given string.

Every anagram is a permutation of a string. As we know, when we are not allowed to repeat characters while finding permutations of a string, we get N!N! permutations (or anagrams) of a string having NN characters. For example, here are the six anagrams of the string “abc”:

abc
acb
bac
bca
cab
cba
Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
Example 2:

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
*/


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
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
      if( minReqd[str[right]] == 0 ) // not required
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
          while (str[left] != str[right] );
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
      
      if(currFound[str[right]] == minReqd[str[right]])
        matchFound++;    
      if(matchReq == matchFound)  
      {
        resultIndices.push_back(left);
        matchReq -= 1;
        minReqd[str[left]] -= 1; 
        left++;
      }

      right++;
    }
    return resultIndices;
  }
};


int main(int argc, char *argv[]) {
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

 /* result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;*/
}