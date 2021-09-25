#include <iostream>
#include <string>
#include <vector>

using namespace std;


void permutateHelper1(string &inp,string &tempPerm,vector<string> &out)
{
    int len = inp.length();
    if(len == 1)
    {
        tempPerm += inp;
        out.push_back(tempPerm);
    }
    for(int i=0;i<len;i++)
    {
        string newInp = inp;
        newInp.erase(i,1);
        string newtempPerm = tempPerm + inp[i];
        permutateHelper1(newInp,newtempPerm,out);
    }
}

vector<string> permutate1(string &inp)
{
    vector<string> out;
    string tempPerm =  "";
    permutateHelper1(inp,tempPerm,out);
    return out;
}

void permutateHelper2(string &inp,int start,int end , vector<string> &out)
{
    if(start == end)
    {
        cout<<endl<<inp;
        out.push_back(inp);
        return;
    }
    for(int i=start;i<=end;i++)
    {
        char temp1 = inp[start];
        char temp2 = inp[i];
        inp[start] = temp2;
        inp[i] = temp1;
        permutateHelper2(inp,start+1,end,out);
        inp[start] = temp1;
        inp[i] = temp2;
    }
}



vector<string> permutate2(string &inp)
{
    vector<string> out;
    permutateHelper2(inp,0,inp.length()-1,out);
    return out;
}

int main()
{
    string inp = "Watch";
    vector<string> out;
    out = permutate2(inp);
}
