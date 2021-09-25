#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<queue>
using namespace std;


int ladderLength(string startString,string endString,vector<string> &dict,vector<string> &out)
{
    int ret = 0;
    unordered_set<string> hashDict;
    for(auto x:dict)
        hashDict.insert(x);

    std::queue<string> foundWords;
    foundWords.push(startString);
    int level = 1;
    while(!foundWords.empty())
    {
        int qsz = foundWords.size();
        for(int q = 0 ; q < qsz ; q++)  ////--------------- This is most important for levels
        {
            string currWord = foundWords.front();
            foundWords.pop();
            if(q != 0)
             out.pop_back();
            out.push_back(currWord);
            //for each character in the start
            string currWordCopy(currWord);
            for(int i = 0;i < currWord.size(); i++ )
            {
                for(int j='a';j<= 'z';j++)
                {
                    if(j == currWord[i])
                    {
                        continue;
                    }
                        currWordCopy[i] = j;
                        if(currWordCopy == endString)
                        {
                            out.push_back(currWordCopy);
                            return level+1;
                        }
                        if( hashDict.find(currWordCopy) != hashDict.end()) //Word exists in dictionary
                        {
                            foundWords.push(currWordCopy);
                            hashDict.erase(currWordCopy);
                        }                    
                }
                currWordCopy[i] = currWord[i];
            }              
        }
        level = level + 1;        
    }
    return ret;
}


int main()
{
    vector<string> dict = { "hot","dot","dog","lot","log","cog" };
    string startString = "hit";
    string endString = "cog";
    vector<string> out;
    int lev = ladderLength(startString,endString,dict,out);
    cout<<endl<<lev<<endl;
    if(lev != 0 )
    {
        for(auto x:out)
            cout<<x<<"--->";
    }
}