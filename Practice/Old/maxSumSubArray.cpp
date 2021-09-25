#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_set>
using namespace std;

typedef int (*fxn1) (int a , int b ); 

int add12(int a, int b)
{
    return a+b;
}

int fxn2(fxn1 fx)
{
    cout << fx(1,2);
}
int main()
{
    fxn2(&add12);
}