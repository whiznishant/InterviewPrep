#include<iostream>
#include<string.h>
using namespace std;
#define MAX_LEN 256


void CrushCandies(int crushIdx,int numToCrush,char (&candies)[MAX_LEN] )
{  
    while( numToCrush !=0 )                
    {
        if(candies[crushIdx] != '.')
        {
            candies[crushIdx] = '.';
            numToCrush--;
        }
        crushIdx -= 1;
    } 
}

bool CandyCrushHelper(char (&candies)[MAX_LEN])
{
    int len = strlen(candies);
    if(len == 0)
    {
        return false;
   
    }
    char runningChar = candies[0];
    cout<<endl;
    int numFound = 0;
    bool crushed = false;
    for(int i=0;i<len;i++)
    {   
        if(candies[i] == '.')
            continue;

        if(candies[i] == runningChar)
        {
            numFound += 1;
        }
        else
        {
            if(numFound > 2)
            {
                crushed = true;
                CrushCandies(i-1,numFound,candies);
            }
            runningChar = candies[i];
            numFound = 1;
        }
    }
    //Special case if last character was running character
    if(numFound > 2)
    {
        CrushCandies(len-1,numFound,candies);
    }
    if(crushed)
        CandyCrushHelper(candies);
    else  
        return true;  
}

void CandyCrush(char (&candies)[MAX_LEN])
{
    CandyCrushHelper(candies);
}

int main()
{
    char candies[256];
    strcpy(candies,"aaabbbacd");
    CandyCrush(candies);
    cout<<candies<<endl;
    return 0;
}