/*
String Anagrams (hard) #
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
    int left = 0,right = 0;
    unordered_map<char,int> charCount;
    for(auto x:pattern)
      charCount[x] += 1;
    int matchReqd = charCount.size();
    int match = 0;
    while( right < str.length())
    {
      //if the curr character is found decrement its count 
      //if the count becomes zero increment the currMatch
      if(charCount.find(str[right]) != charCount.end())
      {
        charCount[str[right]] -= 1;
        if(charCount[str[right]] == 0 )
          match++;
      }
      //if match is met then add the start to result
      if(match == matchReqd)
      {
        resultIndices.push_back(left);
      }
      //Shrink the window if window becomes bigger than pattern
      if(right-left+1 >= pattern.size())
      {
        if( charCount.find(str[left]) != charCount.end() )
        {
          if(charCount[str[left]] == 0)
            match--;
          charCount[str[left]] += 1;
        }
        left += 1;
      }
      right++; 
    }
    return resultIndices;
  }
};


int main(int argc, char *argv[]) {

  auto result = StringAnagrams::findStringAnagrams("abxcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout<<endl;

  result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;


  cout << endl;
}


