#include<iostream>
#include<vector>

using namespace std;

void printOut(vector<vector<char>> &out)
{
    for(auto v : out)
    {
        cout<<endl;
        for(auto x : v)
        {
            cout<<x<<" ";
        }
    }
}

void permutateHelper( vector<char> &inp,vector<char> &currPerm,vector<vector<char>> &out )
{
    if(inp.size() == 0 && currPerm.size() > 0)
    {
        out.push_back(currPerm);
        return;
    }
    for(int i=0;i<inp.size();i++)
    {
        vector<char>newInput(inp);
        //std::copy(inp.begin(),inp.end(),back_inserter(newInput));
        newInput.erase(newInput.begin()+i);
        vector<char>newCurrPerm(currPerm);
        //std::copy(currPerm.begin(),currPerm.end(),back_inserter(newCurrPerm));
        newCurrPerm.push_back(inp[i]);
        permutateHelper(newInput,newCurrPerm,out);       
    } 
}

void Permutate ( vector<char> &permut, vector<vector<char>> &out)
{
    vector<char> currPerm;
    permutateHelper( permut,currPerm,out);
} 

int main()
{
    vector<char> permut = { 'n','i','s','h','a','n','t' };
    vector<vector<char>> out = {};
    Permutate(permut,out);
    printOut(out);
    return 0;
}
