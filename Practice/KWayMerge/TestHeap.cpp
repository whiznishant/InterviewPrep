#include <iostream>
#include <algorithm>
#include <vector>
 
 using namespace std;

int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::make_heap(v.begin(), v.end());

    for(auto x:v)
        cout<<"  " <<x;

    return 0;
}

