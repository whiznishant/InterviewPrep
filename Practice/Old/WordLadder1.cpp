#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;


vector<vector<string>>  ladderLength(string beginWord,string endWord,vector<string> &dict)
{
    vector<vector<string>> out;
        unordered_set<string> hWordList;
        for(auto x:dict)
        {
            hWordList.insert(x);
        }
        if(hWordList.find(endWord) == hWordList.end())
            return {{}};
        queue<string> bfsq;
        bfsq.push(beginWord);
        vector<string> currPath;
        bool stopMore = false;
        while(!bfsq.empty())
        {
            int sz=bfsq.size();
            for(int qs=0;qs<sz;qs++)
            {
                stopMore = false;
                string currString = bfsq.front();
                currPath.push_back(currString);
                if(qs != 0 )
                    currPath.pop_back();
                bfsq.pop();
                string newString = currString;
                for(int i=0;i<currString.size();i++)
                {
                    for(int j='a';j<'z';j++)
                    {
                        if(j == currString[i])
                            continue;
                        newString[i] = j;
                        
                        if(hWordList.find(newString) != hWordList.end())
                        {
                            bfsq.push(newString);
                            hWordList.erase(newString);
                        }
                        
                        if(endWord == newString)
                        {
                            currPath.push_back(newString);
                            out.push_back(currPath);
                            currPath.pop_back();
                            stopMore = true; 
                            break;
                        }
                    }
                    newString[i] = currString[i];
                    if(stopMore)
                        break;
                }
            }
        }
        return out;
    }


int main()
{
    vector<string> dict = { "hot","dot","dog","lot","log","cog" };
    string startString = "hit";
    string endString = "cog";
    vector<vector<string>> out = ladderLength(startString,endString,dict);
    cout<<"done";
}