using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int maxLength = 0;
    int numCount[2] = {0,0};
    int windowSize = 0;
    int left = 0, right = 0;
    // TODO: Write your code here
    while(right < arr.size())
    {
      numCount[arr[right]] += 1;
      windowSize = right - left + 1;
      while( numCount[0] > k ) // not valid anymore shrink it
      {
         numCount[arr[left]] -= 1;
         left++;
         windowSize--;
      }
      maxLength = max(maxLength,windowSize);
      right++;
    }
    return maxLength;
  }
};


int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
    return 0;
}

