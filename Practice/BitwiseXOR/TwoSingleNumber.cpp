using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    // TODO: Write your code here
    int m1XORm2 = 0;
    for(int i=0;i<nums.size();i++)
       m1XORm2 = m1XORm2 ^ nums[i];
    
    // Find one set bit in m1XORm2 ..
    // Set bit denotes that both the numbers have different bit values.
    int bitIdx = 0;
    int tempXoredNum = m1XORm2;
    cout<<endl<<"-------------------"<< (tempXoredNum  & 1)<<endl;
    while( (tempXoredNum & 1) == 0 )
    {
        bitIdx++;
        tempXoredNum = tempXoredNum >> 1;
    }
    cout<<m1XORm2<<endl;
    cout<<bitIdx;

    return vector<int>{-1, -1};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}