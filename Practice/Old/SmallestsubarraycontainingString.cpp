#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

unordered_map<char, int> GetMinRequiredMap(const string &searchString)
{
    unordered_map<char, int> out;
    int len = searchString.length();
    for (auto x : searchString)
    {
        auto iterator = out.find(x);
        if (iterator != out.end())
        {
            iterator->second += 1;
        }
        else
        {
            out.insert(pair<char, int>(x, 1));
        }
    }
    return out;
}

int GetMinimumStringContainingSearch(string &inp, string &search)
{
    int minWindowSize = INT_MAX;
    unordered_map<char, int> minimumRequired = GetMinRequiredMap(search);

    int minRequirementToFullfill = minimumRequired.size();
    int currentFullfilled = 0;

    unordered_map<char, int> currentfound;

    int strlen = inp.length();
    int right = 0, left = 0;
    while (right < strlen && left <= right)
    {
        auto it = minimumRequired.find(inp[right]);
        if (it != minimumRequired.end())
        {
            //Check if it exist in currentfound.
            auto itCurrFound = currentfound.find(inp[right]);
            if (itCurrFound != minimumRequired.end())
            {
                bool canAddToFullfilled = false;
                if (itCurrFound->second < it->second)
                {
                    canAddToFullfilled = true; //to check if the current addition can make it to fullfill our criteria.
                }
                itCurrFound->second += 1;
                if (itCurrFound->second >= it->second && canAddToFullfilled)
                {
                    currentFullfilled += 1;
                }
            }
            else
            {
                currentfound.insert(std::pair<char, int>(inp[right], 1));
                if (it->second == 1)
                {
                    currentFullfilled += 1;
                }
            }
        }
        //Now try to decrease the size of window
        while (currentFullfilled == minRequirementToFullfill && left <= right)
        {
            minWindowSize = min(minWindowSize, (right - left + 1));
            auto itCfound = currentfound.find(inp[left]);
            if (itCfound != currentfound.end())
            {
                bool canDeleteFullfilled = false;
                auto itminReqd = minimumRequired.find(inp[left]);

                if (itCfound->second >= itminReqd->second)
                {                   
                     canDeleteFullfilled = true;
                }

                itCfound->second -= 1;
                bool remove = false;
                if (itCfound->second == 0)
                {
                    remove = true;
                }

                if( itCfound->second < itminReqd->second && canDeleteFullfilled )
                {
                    currentFullfilled -= 1; 
                }
                if(remove)
                    currentfound.erase(inp[left]);
            }
            left++;
        }
        right++;
    }


    if (minWindowSize == INT_MAX)
        minWindowSize = -1;

    return minWindowSize;
}

int main()
{
    string inp = "a$fuu+afff+affaffa+a$Affab+a+a+$a$bccgtt+aaaacA+++aaa$";
    string search = "a+$aaAaaaa$++";
    int minWindow = GetMinimumStringContainingSearch(inp, search);
    cout << endl
         << minWindow;
}