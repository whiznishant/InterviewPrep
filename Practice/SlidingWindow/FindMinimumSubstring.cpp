using namespace std;
#include<limits.h>
#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) 
  {
    // TODO: Write your code here
    int matchReq = 0, match = 0;
    
    int min = INT_MAX;
    int minleft = 0;
    int minright = 0;

    unordered_map<char,int> minReq;
    unordered_map<char,int> currFound;
    int left = 0,right = 0;

    for(auto x:pattern)
      minReq[x] += 1;
    matchReq = minReq.size();

    while( right < str.length())
    {
       if(minReq.find(str[right]) !=  minReq.end())
       {
         currFound[str[right]] += 1;
         if( currFound[str[right]] == minReq[str[right]])
         {
           match++;
         }
         if( match == matchReq)
         {
           //Now shrink the window
          while(left <= right && match == matchReq)
          {
              if(min > right-left+1)
              {
                min = right-left+1;
                minleft = left;
                minright = right;
              }
              if(currFound.find(str[left]) != currFound.end())
              {
                if( currFound[str[left]]  == minReq[str[left]] )
                {
                  match--;
                }
                currFound[str[left]] -= 1;
                if(currFound[str[left]] == 0 )
                  currFound.erase(str[left]);
              } 
              left++;

           }
         }
       }
       right++;
    }
    return str.substr(minleft,minright - minleft +1 );
  }
};


int main()
{

    cout << MinimumWindowSubstring::findSubstring("abcd$ef$axb$c$","$$abf");
    return 0;
}