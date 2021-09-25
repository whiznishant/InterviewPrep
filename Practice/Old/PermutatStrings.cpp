#include<iostream>
#include<string>
#include<vector>

using namespace std;



void permutationHelper(string &inpString,string &currPermutation,vector<string> &allPermutations)
{
    if(inpString.length() == 1)
    {
        currPermutation = currPermutation + inpString[0];
        allPermutations.push_back(currPermutation);
        return;
    }
    int length = inpString.length();
    for(int i=0; i < length;i++)
    {
        string newInput = inpString;
        newInput.erase(i,1);
        string newCurrPerm = currPermutation + inpString[i];
        permutationHelper(newInput,newCurrPerm,allPermutations);
    }
}

void permutate(string inpString,vector<string> &allPermutations)
{
    string tempPerm;
    permutationHelper(inpString,tempPerm,allPermutations);
}

int main()
{
    string inp = "Hello";
    vector<string> out;
    permutate(inp,out);
    for(auto s:out)
    {
        cout<<endl<<s;
    }
    cout<<endl;
}
