#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myDict;
        // Populate my dictionary 
        for(auto x:wordList)
            myDict.insert(x);
        
        queue<string> bfsqueue;
        bfsqueue.push(beginWord);
        int level = 0;
        while( !bfsqueue.empty())
        {
            int numItemsInQueue = bfsqueue.size();  //These are my current level strings. 
            level += 1;
            for(int k = 0; k < numItemsInQueue; k++)
            {
                string poppedString = bfsqueue.front();
                string currString = poppedString;
                bfsqueue.pop();
                int len = currString.length();
                for( int j = 0; j < len ; j++ )
                {
                    for(int i='a';i<='z';i++)
                    {
                        //Change the currentword one character at a time.                                               
                        currString[j] = i;

                        //If the word is the end word break from here.
                        if(currString == endWord)
                        {
                            return level;
                        }
                        //Search in my dictionary if the word is present
                        auto it = myDict.find(currString);
                        if( it != myDict.end())
                        {
                            //If found then add to my queue of currentlevel.
                            bfsqueue.push(currString);
                            //Remove from dictionary to avoid duplicate.
                            myDict.erase(currString);
                        }                                                                                              
                    }
                    // Once we go to next character we need to revert back the word.
                    currString = poppedString;                   
                }
            }
        }
        return 0;               
    }
};



int main()
{
    Solution s;
    vector<string> dict = {"hot","dot","dog","lot","log","cog" };
    int len = s.ladderLength("hit","cog",dict);
    cout<<endl<<endl<<len;
}
