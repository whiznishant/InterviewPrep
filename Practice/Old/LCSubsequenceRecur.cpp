#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/*
int LCSHelper(int sIdx1,int sIdx2, string &str1,string &str2,string &longestSq, unordered_map<vector<int>,string> &memo )
{
    if(sIdx1 == str1.length() || sIdx2 == str2.length())
    {
        return longestSq.length();
    }

    if(str1[sIdx1] == str2[sIdx2])
    {
        longestSq += str1[sIdx1];
        return LCSHelper(sIdx1+1,sIdx2+1,str1,str2,longestSq);        
    }
    else
    {
        string str1add = longestSq;
        string str2add = longestSq;
        int len1 = LCSHelper(sIdx1+1,sIdx2,str1,str2,str1add);
        int len2 = LCSHelper(sIdx1,sIdx2+1,str1,str2,str2add);
        if( len1 >= len2) 
        {
            longestSq = str1add;
            return len1;
        }
        else
        {
            longestSq = str2add;
            return len2;
        }
    }
    return 0;
}



string longestCommonSubsequence(string str1, string str2) {
  // Write your code here.
  string longest = "";
  unordered_map<vector<int>,string> memo;
  LCSHelper(0,0,str1,str2,longest,memo);
  return longest;
}*/

// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};


// if chars are same remove both characters and find lcs of rest,
// if they are not same find the max len lcs of
int LCSHelper(int sIdx1, int sIdx2, string &str1, string &str2, string &longestSq, unordered_map<pair<int, int>, string,pair_hash> &memo)
{
    auto it = memo.find(make_pair(sIdx1, sIdx2));
    if (it != memo.end())
    {
        longestSq = it->second;
        return it->second.length();
    }

    if (sIdx1 == str1.length() || sIdx2 == str2.length())
    {
        memo[make_pair(sIdx1, sIdx2)] = longestSq;
        return longestSq.length();
    }

    if (str1[sIdx1] == str2[sIdx2])
    {
        longestSq += str1[sIdx1];
        int ret = LCSHelper(sIdx1 + 1, sIdx2 + 1, str1, str2, longestSq, memo);
        memo[make_pair(sIdx1, sIdx2)] = longestSq;
        return ret;
    }
    else
    {
        string str1add = longestSq;
        string str2add = longestSq;
        int len1 = LCSHelper(sIdx1 + 1, sIdx2, str1, str2, str1add, memo);
        int len2 = LCSHelper(sIdx1, sIdx2 + 1, str1, str2, str2add, memo);
        if (len1 >= len2)
        {
            memo[make_pair( sIdx1 + 1 , sIdx2)] = str1add;
            longestSq = str1add;
            return len1;
        }
        else
        {
            memo[make_pair(sIdx1, sIdx2)] = str2add;
            longestSq = str2add;
            return len2;
        }
    }
    return 0;
}

string longestCommonSubsequence(string str1, string str2)
{
    // Write your code here.
    string longest = "";
    unordered_map<pair<int, int>, string,pair_hash> memo;
    LCSHelper(0, 0, str1, str2, longest, memo);
    return longest;
}

int main()
{
    string str1 = "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG";
    string str2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << longestCommonSubsequence(str1, str2);
    return 0;
}
