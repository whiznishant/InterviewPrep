/*
Given a string, find the length of the longest substring, which has no repeating characters.

Example 1:

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".
Example 2:

Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".
Example 3:

Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde".
*/



using namespace std;

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    // TODO: Write your code here
    unordered_set<char> uniq;
    int left = 0,right = 0; 
    while( right < str.length())
    {
        if(uniq.count(str[right]))
        {
          while( left <= right and str[left] != str[right])  // Can avoid this loop by choosing a map and keeping the last index of found 
          {
            uniq.erase(str[left]);
            left++;
          }
          left = left + 1;
        }
        uniq.insert(str[right]);
        maxLength = max(maxLength, right-left+1);

        right++;      
    }
    return maxLength;
  }
};

/*class NoRepeatSubstring {               //---Fix this.
 public:
  static int findLength(const string& s) {
    unordered_map<char,int> uniq;
    int maxi = 0;
    int left=0,right=0;
    while(right < s.length())
    {
        if(uniq.find(s[right]) != uniq.end())
        {
            left = max(uniq[s[right]];           
            uniq[s[right]] = right;
            left = left + 1;
        }
        else
        {
            uniq[s[right]] = right;
            maxi = maxi < right - left + 1 ? right - left + 1:maxi;            
        }
        right++;
    }
    
    return maxi;
  }
};*/




int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("tmmzuxt") << endl;
}