/*
Words Concatenation (hard) #
Given a string and a list of words, find all the starting indices of substrings in the given string that are a concatenation of all the given words exactly once without any overlapping of words. It is given that all words are of the same length.

Example 1:

Input: String="catfoxcat", Words=["cat", "fox"]
Output: [0, 3]
Explanation: The two substring containing both the words are "catfox" & "foxcat".
Example 2:

Input: String="catcatfoxfox", Words=["cat", "fox"]
Output: [3]
Explanation: The only substring containing both the words is "catfox".

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int wordLen = words[0].length();
    int windowLength = wordLen * words.size();
    unordered_map<string,int> dict;
    for(auto x:words)
      dict[x] += 1;    
    int matchReqd = dict.size(); 
    int match = 0;
    int left = 0,right = wordLen - 1, tempLeft = 0;
    while( right < str.length() )
    {
      string currWord = str.substr(tempLeft,wordLen);
      if(dict.find(currWord) != dict.end())
      {
        dict[currWord] -= 1;
        if(dict[currWord] == 0)
          match++;
      }
      if( right - left + 1 == windowLength)
      {
        if( match == matchReqd )
        {
          resultIndices.push_back(left);
        }
        string evictedWord = str.substr(left,wordLen);
        if(dict.find(evictedWord) != dict.end())
        {
          if( dict[evictedWord] == 0)
            match--;
          dict[evictedWord] += 1;
        }
        left  = left + wordLen;        
      }
      tempLeft += wordLen;
      right += wordLen;
    }
    return resultIndices;
  }
};


int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
  result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}