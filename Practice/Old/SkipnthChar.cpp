#include <iostream>
#include <vector>

using namespace std;


void PrintSkippinNthChar(string &inp, int n)
{
    if(n == 0)
    {
     cout<<inp;
     return;
    }
    for(int i=0;i<inp.length();i++)
    {
        if((i+1) % n != 0 )
            cout<<inp[i];
    }
}
int main()
{
    string inp = "abcdefg";
    PrintSkippinNthChar(inp,3);

}