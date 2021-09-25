#include<iostream>
using namespace std;

void Hanoi(int numDisks,char src, char aux , char dest )
{
    if( numDisks == 1 )
    {
        cout<<endl<<"Moving Disk 1 from "<<src<<" to " <<dest;
        return;
    }
    Hanoi( numDisks -1,src,dest,aux);
    cout<<endl<<"Moving Disk "<< numDisks << " from "<<src<<" to "<<dest;
    Hanoi( numDisks -1,aux,src,dest);
}


int main()
{
    Hanoi(6,'A','B','C');
    cout<<endl<<endl<<endl;

}