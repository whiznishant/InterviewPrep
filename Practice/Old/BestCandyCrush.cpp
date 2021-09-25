#include<iostream>
#include<string.h>
using namespace std;
#define MAX_LEN 256


void CrushCandies(int crushIdx,int numToCrush,char (&candies)[MAX_LEN], char (&crushedCandies)[MAX_LEN] )
{  
    while( numToCrush !=0 )                
    {
        if(crushedCandies[crushIdx] != 'x')
        {
            crushedCandies[crushIdx] = 'x';
            numToCrush--;
        }
        crushIdx -= 1;
    } 
}

int GetCrushedStringLength(char (&crushedCandies)[MAX_LEN],int inputStringLength)
{
    int len = 0;
    for(int i=0;i<inputStringLength;i++)
    {
        if(crushedCandies[i] == '.')
        {
            len++;
        }
    }
    return len;
}

int CandyCrushHelper(char (&candies)[MAX_LEN], char (&crushedCandies)[MAX_LEN], int inpStringLength, int startPoint )
{
    crushedCandies[inpStringLength] = '\0';
    cout<<endl<<"Calling for "<<crushedCandies;
    int currentIdx = startPoint;
    char runningChar = '/';
    int numFound = 0;
    while(currentIdx < inpStringLength )
    {
        if( runningChar == '/' && crushedCandies[currentIdx] != 'x')
        {
            runningChar = candies[currentIdx];
        }

        if(crushedCandies[currentIdx] == 'x')
        {
            currentIdx++;
            continue;
        }
        if(candies[currentIdx] == runningChar)
        {
            numFound += 1;
        }
        else
        {
             runningChar = candies[currentIdx];
            if(numFound >= 3 )  // if we can crush these candies try crushing them or skipping them.
            {
                break;
            }
        }
        currentIdx++;
    }

    int currentStringLength = GetCrushedStringLength(crushedCandies,inpStringLength);
    
    int crushLen = currentStringLength;
    int nonCrushLen = currentStringLength;
    char crushedCandiesMask1[MAX_LEN];
    memcpy(crushedCandiesMask1, crushedCandies,MAX_LEN);
    char crushedCandiesMask2[MAX_LEN];
    memcpy(crushedCandiesMask2, crushedCandies,MAX_LEN);
    
    if(numFound >= 3)
    {    
        CrushCandies(currentIdx-1,numFound,candies,crushedCandiesMask1);
        crushLen = CandyCrushHelper(candies,crushedCandiesMask1,inpStringLength,0);
        nonCrushLen = CandyCrushHelper(candies,crushedCandiesMask2,inpStringLength,currentIdx);        
    }

    if(crushLen <= nonCrushLen)
    {
        memcpy(crushedCandies,crushedCandiesMask1,MAX_LEN);
        return crushLen;
    }
    
    memcpy(crushedCandies,crushedCandiesMask2,MAX_LEN);
    return crushLen;
}

void CandyCrush(char (&candies)[MAX_LEN])
{
    char crushedCandies[256];
    std::fill(&(crushedCandies[0]),&(crushedCandies[0]) + MAX_LEN , '.' );
    int inputLength = strlen(candies);
    CandyCrushHelper(candies,crushedCandies,inputLength,0);
    crushedCandies[inputLength] = '\0';
    cout<<endl<<"Result is ::" << crushedCandies<<endl;
    for(int i=0;i < inputLength;i++)
    {
        if(crushedCandies[i] == '.')
            cout<<candies[i];
    }
    cout<<endl;
}

int main()
{
    char candies[256];
    
    strcpy(candies,"ccaaabbbacd");
    CandyCrush(candies);
    return 0;
}