using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/*class EvaluateExpression {
 public:
   static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    // TODO: Write your code here
    if(input.find("+") == string::npos && input.find("-") == string::npos &&
       input.find("*") == string::npos )
    {
      //This means there is only one number in input return it as result.
      result.push_back(stoi(input));
      return result;
    }
    for(int i = 0;i< input.size() -1 ;i++)
    {
      if(!isdigit(input[i]))
      {
          vector<int> leftEval = diffWaysToEvaluateExpression(input.substr(0,i));
          vector<int> rightEval = diffWaysToEvaluateExpression(input.substr(i+1, input.length() - (i+1) ));
          for(auto x:leftEval)
          {
             for(auto y:rightEval)
             {
                switch (input[i])
                {
                  case '+':
                    result.push_back(x+y);break;
                  case '-':
                    result.push_back(x-y);break;
                  case '*':
                    result.push_back(x*y);break;
                }
             }
          }            
      }
    }
    return result;
  }

};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("100+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

*/
using namespace std;
//#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class EvaluateExpression {
 public:
    inline static unordered_map<string, vector<int>> memoize;

    static vector<int> diffWaysToEvaluateExpression(const string& input,bool mainCall = false) 
    {
      if(mainCall)
        memoize.clear();
            
      if(memoize.find(input) != memoize.end())
      {
        return memoize[input];
      }

      vector<int> result;
      // TODO: Write your code here
      if(input.find("+") == string::npos && input.find("-") == string::npos &&
        input.find("*") == string::npos )
      {
        //This means there is only one number in input return it as result.
        result.push_back(stoi(input));
        return result;
      }
      for(int i = 0;i< input.size() -1 ;i++)
      {
        if(!isdigit(input[i]))
        {
            vector<int> leftEval = diffWaysToEvaluateExpression(input.substr(0,i));
            vector<int> rightEval = diffWaysToEvaluateExpression(input.substr(i+1, input.length() - (i+1) ));
            for(auto x:leftEval)
            {
              for(auto y:rightEval)
              {
                  switch (input[i])
                  {
                    case '+':
                      result.push_back(x+y);break;
                    case '-':
                      result.push_back(x-y);break;
                    case '*':
                      result.push_back(x*y);break;
                  }
              }
            }            
        }
      }
      memoize.insert(std::make_pair(input,result));
      return result;
    }
};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3",true);
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5",true);
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}


