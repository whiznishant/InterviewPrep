#include<iostream>
using namespace std;
int main()
{
    int array[50];
    cout<<sizeof(array)<<endl;
    int *p = array + 10;
    cout<<sizeof(p);
}
