#include<iostream>
#include<string.h>
#include<array>

using namespace std;
//void fxn( std::array<std::array<int,10>,10> &a )
void fxn( int (&a)[10][10] )
{
    for(int i=0;i<10;i++)
    {
        cout<<endl;
        for(int j=0;j<10;j++)
        {
            cout<<a[i][j]<<"  ";
        }
    }        
}

int main()
{
   int a[10][10];
    //std::array<std::array<int,10>,10> a;
    //memset(&a,0,sizeof(int)*10*10);
   int b[10][10];
   std::fill(&(a[0][0]),&(a[0][0]) + 100,5);
   std::copy( &(a[0][0]),&(a[0][0]) + 100,&(b[0][0])) ;
   fxn(b);
   return 1;
}