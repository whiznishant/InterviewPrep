#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;

int ladderLength(string startString,string endString,vector<string> &dict)
{
    unordered_set<string> dicthash;
    vector<string> path;
    for(auto x:dict)
        dicthash.insert(x);
    
    std::queue<string> q;
    q.push(startString);
    int level = 1;
    while( !q.empty())
    {
        int qsize = q.size();
        for(int i=0;i < qsize;i++)
        {
            string currWord = q.front();
            int len = currWord.length();
            q.pop();
            if(i != 0)
                path.pop_back();
            path.push_back(currWord);
            for(int i=0;i < len;i++)
            {
                string mutateWord = currWord;
                for(int j='a' ; j <= 'z'; j++ )
                {
                    if(j == currWord[i])
                        continue;
                    mutateWord[i] = j;
                    if(mutateWord == endString)
                    {
                        path.push_back(mutateWord);
                        return level+1;
                    }
                    if(dicthash.find(mutateWord) != dicthash.end())
                    {
                        q.push(mutateWord);
                        dicthash.erase(mutateWord);
                    }
                }    
            }
        }
        level += 1;
    }
    return -1;
}

int main()
{
    vector<string> dict = { "hot","dot","dog","lot","log","cog" };
    string startString = "hit";
    string endString = "cog";
    int len = ladderLength(startString,endString,dict);
    cout<<endl<<"done"<<len;
}