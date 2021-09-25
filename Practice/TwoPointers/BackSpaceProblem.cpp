using namespace std;

#include <iostream>
#include <string>

//O(M+N) Space and O(M+N) time
#include<vector>

class BackspaceCompare {
 public:
  static vector<char>* PopulateStringStack( const string &str )
  {
    vector<char> *strStack = new vector<char>();
    for(auto x:str)
    {
      if(x!='#')
        strStack->push_back(x);
      else
      {
        strStack->pop_back();
      }
    }
    return strStack;
  }
  static void FreeMemm(vector<char> *s1,vector<char> *s2)
  {
    delete(s1);delete(s2);
  }
  static bool compare(const string &str1, const string &str2) {
    // TODO: Write your code here
    vector<char> *s1 = PopulateStringStack(str1);    
    vector<char> *s2 = PopulateStringStack(str2);
    if(s1->size() != s2->size())
    {
      FreeMemm(s1,s2);
      return false;
    }
    for(int i=0;i< s1->size();i++)
    {
      if(s1->at(i) != s2->at(i))
      {
        FreeMemm(s1,s2);
        return false;
      }
    }
    FreeMemm(s1,s2);
    return true;
  }
};
int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}