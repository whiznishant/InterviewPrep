

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;


int findMaxFreqCharInMap( unordered_map<char,int> &umap , char &mxChar )
{
    int max = 0; mxChar = ' ';
    for( auto x:umap )
    {
        if(x.second > max )
        {
            max = x.second;
            mxChar = x.first;
        }
    }
    return max;
}

int findLongest(string &inp,int k)
{
    unordered_map<char,int> charCounts;
    char maxFreqChar =' ';
    int maxFreq = 0;
    int x = 0;
    int maxWindowFound = 0;

    int left = 0,right = 0;
    while(right < inp.length())
    {
        charCounts[inp[right]] += 1;
        if(charCounts[inp[right]] >= maxFreq )
        {
            maxFreqChar = inp[right];
            maxFreq = charCounts[inp[right]];
        }

        // Check if we are still valid ;
        int windowSize = right - left + 1;
        if( windowSize - maxFreq <= k )
        {
            if(maxWindowFound < windowSize )
                maxWindowFound = windowSize;
        }
        else // we are invalid we can reduce the window now.
        {
            while(windowSize-maxFreq > k )
            {
                charCounts[inp[left]] -= 1;
                if(inp[left] == maxFreqChar )
                {
                    maxFreq = findMaxFreqCharInMap(charCounts, maxFreqChar );
                }
                left ++;
                windowSize--;
            }
        }
        right++;
    }
    return maxWindowFound;
}

int main()
{
    string inp = "abccde";
    int k = 1;

    int out = findLongest(inp,k);
    cout<<endl<<"----------->>"<<out;
}