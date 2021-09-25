#include<iostream>
#include<math.h>

using namespace std;

bool getStatus(int idx, char (&devstatus)[16])
{
    if(idx < 0 &&  idx > 127 )
        return false;
    //Find the byte. 
    int byteIdx = floor(idx / 8);
    int bitIdx =  idx % 8;
    char mask = 1 << bitIdx;
    return (devstatus[byteIdx] & mask);
}

bool setBit(int idx,char (&devStatus)[16],bool set)
{
    if(idx < 0 &&  idx > 127 )
        return false;
    //Find the byte. 
    int byteIdx = floor(idx / 8);
    int bitIdx =  idx % 8;
    char mask;
    mask = 1 << bitIdx;
    if(set)
        devStatus[byteIdx] |= mask;
    else
        devStatus[byteIdx] &= ~mask;
    
}

int main()
{
    char devStatus[16];
    std::fill(&(devStatus[0]),&(devStatus[0])+16,0);
    cout<<endl;
    char randomvals[10];
    for(int i= 0; i < 10; i++)
    {
        int random = rand() % 128; //0 to 127
        cout<<random<<" ";
        randomvals[i] = random;
        setBit(random, devStatus,true);
    }
    cout<<endl;
    for(int i=0;i<128;i++)
    {
        if(getStatus(i,devStatus) == true)
            cout<<i<<" ";
    }    
    cout<<endl;

    for(int i=0;i<5;i++)
    {
         setBit(randomvals[i], devStatus,false);
    }

    cout<<endl;
    for(int i=0;i<128;i++)
    {
        if(getStatus(i,devStatus) == true)
            cout<<i<<" ";
    }    
    cout<<endl;

    return 0;
}