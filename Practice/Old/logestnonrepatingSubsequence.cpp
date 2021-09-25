#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

string longestNonRepeatingSubsequence(string &inp)
{
    int len = inp.length();
    int leftPtr = 0;
    int rightPtr = 0;
    unordered_set<char> charfreq;
    int maxlen = 0;
    string maxString = "";
    while(rightPtr < len )
    {
        if(charfreq.find(inp[rightPtr]) == charfreq.end())
        {
            charfreq.insert(inp[rightPtr]);
            rightPtr++;
        }
        else
        {
            if(charfreq.size() > maxlen)
            {
                maxlen = charfreq.size();
                maxString = inp.substr(leftPtr,rightPtr-leftPtr);
            }
            charfreq.erase(inp[leftPtr]);
            leftPtr++;
        }
    }
    cout<<maxlen<<endl;
    return maxString;
}

int main()
{
    string inp = "GEEKSFORGEEKS";
    cout<<endl;
    cout<< longestNonRepeatingSubsequence(inp);
    return 0;
}