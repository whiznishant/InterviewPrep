#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int numLights = 7;
    vector<bool> lights(numLights,true);
    for(int i=1;i<=numLights;i++)
    {
        for(int j=1;j<=numLights;j++)
        {
            if(j%i == 0)
              lights[j-1] = !lights[j-1];
        }
        cout<<endl;
        for(auto x:lights)
            cout<<" "<<x;
    }


}