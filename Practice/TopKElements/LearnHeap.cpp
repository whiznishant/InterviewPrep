using namespace std;
#include<iostream>
#include<vector>
#include<queue>

int main()
{
    vector<int> x = { 10,9,8,7,6,5 };
    make_heap(x.begin(),x.end(),std::greater<int>());
    cout <<endl;
    
    x.push_back(4);
    std::push_heap (x.begin(),x.end(),std::greater<int>());
    x.push_back(3);
    std::push_heap (x.begin(),x.end(),std::greater<int>());
    x.push_back(2);
    std::push_heap (x.begin(),x.end(),std::greater<int>());
    
    int sz = x.size();
    for(int i=0;i<sz;i++)
    {
        cout << x.front() << endl;        
        pop_heap( x.begin(),x.end(),std::greater<int>());
        x.pop_back();       
       
    }
}