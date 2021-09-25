#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> x = { 1,2,3,4,5,6,7,8,9};
    int mid = x.size()/2;
    vector<int> y(x.begin(),x.begin()+mid);
    vector<int> z(x.begin()+mid,x.end());

    for(auto q:y)
    {
        cout<<"  "<<q;
    }
    cout<<endl;
    for(auto q:z)
    {
        cout<<"  "<<q;
    }
}