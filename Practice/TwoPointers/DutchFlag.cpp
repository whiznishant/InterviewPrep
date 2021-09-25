using namespace std;

#include <iostream>
#include <vector>


class DutchFlag
{
public:
    static void sort(vector<int> &arr)
    {
        // TODO: Write your code here
        int sz = arr.size();
        int zeroPtr = -1;
        int twoPtr = sz;
        int i = 0;
        while (i < sz && i < twoPtr)
        {
            if (arr[i] != 1)
            {
                if (arr[i] == 2)
                {
                    twoPtr--;
                    int temp = arr[i];
                    arr[i] = arr[twoPtr];
                    arr[twoPtr] = temp;
                }
                else
                {
                    zeroPtr++;
                    int temp = arr[i];                  
                    arr[i] = arr[zeroPtr];
                    arr[zeroPtr] = temp;
                    
                }
            }
            else
            {
                i++;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> arr = {2,2,0,1,2,0};
    DutchFlag::sort(arr);
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}