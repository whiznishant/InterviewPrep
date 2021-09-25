using namespace std;
#include<iostream>
#include<vector>

void GetNearestGreaterToRight(vector<int>& inp,vector<int> &out)
{
    out.resize(inp.size());
    vector<int> monoStack;        
    for(int i=inp.size()-1;i >=0 ;i-- )
    {
        while(!monoStack.empty() && inp[i] >= monoStack.back())
        {
            monoStack.pop_back();
        }
        if(monoStack.empty())
        {
            out[i] = -1;
        }
        else
        {
            out[i] = monoStack.back();
        }
        monoStack.push_back(inp[i]);
    }
}

int main()
{
    vector<int> inp = { 1,3,0,0,1,2,4 };
    vector<int> out;
    GetNearestGreaterToRight(inp,out);
    for(auto x: out)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}