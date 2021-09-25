

#include<iostream>
#include<vector>

using namespace std;

int SplitArrayIntoTwoSubArray(vector<int> &inp )
{
    if(inp.size() <= 1)
        return -1;
    //find the sum of the array
    int sum = 0;
    for(auto x:inp)
        sum += x;
    
    if(sum%2 != 0)
        return -1;
    
    int half = sum/2;
    int leftsum = 0;
    for(int i=0;i < inp.size();i++)
    {
        leftsum += inp[i];
        if(leftsum == half)
        {
            return i;
        }
        if(leftsum > half)
        {
            return -1;
        }
    }
}

int main()
{
    vector<int> inp = { 4,1,2,3 };

    int split = SplitArrayIntoTwoSubArray(inp);
    if(split == -1)
    {
        cout<<"Not Possible";
        return 0;
    }
    cout<<endl;
    for(int i=0;i<=split;i++ )
        cout<<inp[i]<<" ";
    cout<<endl;
    for(int i=split+1;i< inp.size();i++ )
        cout<<inp[i]<<" ";
    
    return 0;
}