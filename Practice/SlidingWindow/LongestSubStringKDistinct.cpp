/* Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

You can assume that K is less than or equal to the length of the given string.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".
Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

*/

using namespace std;


#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    unordered_map<char,int> charCounts;
    int left = 0,right = 0;
    while(right < str.length())
    {
      charCounts[str[right]] += 1;
      if(charCounts.size() == k )
      {
        maxLength = max((right-left+1), maxLength);
      }
      while( charCounts.size() > k && left<=right)
      {
        charCounts[str[left]] -= 1;
        if(charCounts[str[left]] == 0 )
            charCounts.erase(str[left]);
        left++;
      }
      right++;
    }
    return maxLength;
  }
};

int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("aaaaaaabvvbbbbebi", 1)
       << endl;
}

