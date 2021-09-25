using namespace std;

#include <iostream>
#include <string>

#include<vector>


class BackspaceCompare {
 public:
  static int GetNextValidCharIndex( int currIdx, const string &str )
  {
    if(str[currIdx] != '#')
    {
      return currIdx;
    }
    int numBackSpaces = 1;
    currIdx -= 1;
    while( currIdx != -1 && numBackSpaces != 0 )
    {
      if(str[currIdx] == '#')
        numBackSpaces++;
      else
        numBackSpaces--;
      
      currIdx -= 1;
    }
    return currIdx;
  }

  static bool compare(const string &str1, const string &str2) 
  {
    // TODO: Write your code here
    int idx1 = str1.size() - 1; 
    int idx2 = str2.size() - 1;
    while( idx1 != -1 && idx2 != -1 )
    {
      idx1 = GetNextValidCharIndex(idx1,str1);
      idx2 = GetNextValidCharIndex(idx2,str2);
      if(idx1 != -1 && idx2 != -1)
      {
          if(str1[idx1] != str2[idx2])
            return false;
          else
          {
            idx1--;
            idx2--;
          }
      }
      else if( idx1 == -1 && idx2 == -1 )
        return true;
      else
        return false;
    }

    return true;
  }
};


int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
  cout << BackspaceCompare::compare("xyzz##zz###z", "xz") << endl;
}
