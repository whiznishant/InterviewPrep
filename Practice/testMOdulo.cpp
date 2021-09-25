#include<iostream>

int main()
{
    for(int i=0;i<10000;i++)
    {
        int x = rand()%5000;
        int y = rand()%5000;

        int z = x % y;
        int k = x & (y-1) ;
        if( z == k )
            printf("works %d  %d ",x,y);
    }
    return 0;
}
