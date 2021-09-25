#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct vowelDist
{
    int mindist;
    char nearestVowel;
};

void FillDistanceToVowel(int start,int end,unordered_set<char> &vowels, unordered_map<char,vowelDist> & consDistToNearestVowel)
{
    for(int i=start;i<=end;i++)
    {
        if(vowels.find(i) == vowels.end())
        {
            int dist = 999;
            int minDistVowel = 'a';
            for(auto x:vowels)
            {
                int newDist = abs(i - x);
                if(newDist < dist)
                {
                    dist = newDist;
                    minDistVowel = x; 
                }
            }
            vowelDist x;
            x.mindist = dist;
            x.nearestVowel = minDistVowel;
            consDistToNearestVowel.insert(std::pair<char,vowelDist>(i,x));
        }
    }
}

void GetNumVowelsConsonants(unordered_set<char> &vowels, string &inp , int &numVowels, int &numConsontants)
{
    int len = inp.length();
    numVowels = 0;
    numConsontants = 0;
    for(int i=0;i<len;i++ )
    {
        if(vowels.find(inp[i]) != vowels.end())
        {
            numVowels += 1;
        }
        else
        {
            numConsontants +=1;
        }
    }
}
int GetMin(string &inp)
{
    vector<char> v = { 'A','E','I','O','U', 'a','e','i','o','u' };
    unordered_set<char>vowels;
    for(auto x:v)
        vowels.insert(x);
    unordered_map<char,vowelDist> consDistToNearestVowel;
    FillDistanceToVowel('A','Z',vowels,consDistToNearestVowel);     //constant time 
    FillDistanceToVowel('a','z',vowels,consDistToNearestVowel);     //constant time 
    int minOperations = 0;

    int numVowels,numConsonants;
    GetNumVowelsConsonants(vowels,inp,numVowels,numConsonants); //O(n)
    int numRequiredForEach = 
    if(numVowels)

    return minOperations;
}

int main()
{
    string inp = "WITHOUTITIAMJUSTESPR";
    cout << GetMin(inp);

}









/*

Problem Statement
    	
In the English alphabet the letters {'A', 'E', 'I', 'O', 'U'} are called vowels while all others are called consonants. Note that in this problem 'Y' is always a consonant.

A string is balanced if the number of vowels in the string is the same as the number of consonants in the string.

For example, the string "BANANA" is balanced: it has three consonants ('B' and two 'N') and three vowels (three 'A'). The string "TOPCODER" is not balanced: it has five consonants but only three vowels.



Elly has a String S. The length of S is even.

The girl can alter her string as many times as she likes. In each operation she chooses one valid index i and either increments or decrements the letter S[i].

Incrementing a letter changes it to the next letter in the alphabet (e.g., 'A' to 'B', 'L' to 'M', and 'Y' to 'Z'). Decrementing a letter changes it to the previous letter in the alphabet (e.g., 'B' to 'A', 'M' to 'L', and 'Z' to 'Y'). The letter 'A' cannot be decremented and the letter 'Z' cannot be incremented.

Multiple operations may be applied to the same index. Thus, S can be transformed into any other string of the same length.



Elly wonders what is the minimal number of operations she has to do on S in order to make it balanced. Find and return that number.

 
Definition
    	
Class:	EllysBalancedStrings
Method:	getMin
Parameters:	String
Returns:	int
Method signature:	int getMin(String S)
(be sure your method is public)
    
 
Constraints
-	S will contain between 2 and 100 characters, inclusive.
-	S will contain an even number of characters.
-	Each character in S will be an uppercase letter of the English alphabet ({'A'-'Z'}).
 
Examples
0)	
    	
"TOPCODER"
Returns: 1
We can convert "TOPCODER" to "TOOCODER" in a single operation. After that transformation, it has 4 vowels (three 'O's and one 'E') and 4 consonants ('T', 'C', 'D', and 'R').
1)	
    	
"BANANA"
Returns: 0
"BANANA" already has equal number of vowels and consonants.
2)	
    	
"WITHOUTITIAMJUSTESPR"
Returns: 2
3)	
    	
"NOZAPHODJUSTVERYVERYIMPROBABLE"
Returns: 5
4)	
    	
"SYZYGY"
Returns: 8
In astronomy, a syzygy is a roughly straight-line configuration of three or more celestial bodies in a gravitational system. Please note that although the letter 'Y' is sometimes considered a vowel, in this task it is always a consonant.

In this example, one optimal solution is to produce the balanced string "UUZYEY" in 2 + 4 + 0 + 0 + 2 + 0 = 8 operations.
5)	
    	
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
Returns: 8


*/