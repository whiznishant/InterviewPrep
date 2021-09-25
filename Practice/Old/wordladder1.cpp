/*
Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/


#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

int ladderLength(string beginWord,string endWord,vector<string> &wordList)
{

    unordered_set<string> hWordList;
    for(auto x:wordList)
    {
        hWordList.insert(x);
    }
    if(hWordList.find(endWord) == hWordList.end())
        return 0;

    queue<string> bfsq;
    bfsq.push(beginWord);
    int level = 1;
    while(!bfsq.empty())
    {
        int sz=bfsq.size();
        for(int qs=0;qs<sz;qs++)
        {
            string currString = bfsq.front();
            bfsq.pop();
            string newString = currString;
            for(int i=0;i<currString.size();i++)
            {
                for(int j='a';j<'z';j++)
                {
                    if(j == currString[i])
                        continue;
                    newString[i] = j;
                    if(endWord == newString)
                        return level+1;
                    if(hWordList.find(newString) != hWordList.end())
                    {
                        bfsq.push(newString);
                        hWordList.erase(newString);
                    }
                }
                newString[i] = currString[i];
            }
        }
        level = level+1;
    }
    return 0;
}

int main()
{
    vector<string> wordlist = { "hot","dot","dog","lot","log","cog" };
    int len = ladderLength("hit","cog",wordlist);
    cout<<endl<<"Length of the ladder "<<len<<endl;
}