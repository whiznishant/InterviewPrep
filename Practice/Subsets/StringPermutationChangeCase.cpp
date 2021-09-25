/*

Given a string, find all of its permutations preserving the character sequence but changing case.

Example 1:

Input: "ad52"
Output: "ad52", "Ad52", "aD52", "AD52" 
Example 2:

Input: "ab7c"
Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LetterCaseStringPermutation {
 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    // TODO: Write your code here
    permutations.push_back("");
    for(char x: str)
    {   
      int sz = permutations.size();   
      for(int i=0;i<sz;i++)
      {
          string temp = permutations[i];
          permutations[i]  += x;
          if(isalpha(x))
          {
            if(islower(x))
            {
              temp += toupper(x);
            }
            else
            {
              temp += tolower(x);
            }
            permutations.push_back(temp);
          }
      }        
    }
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}