
#include <vector>
#include <iostream>

using namespace std;


int minRewards(vector<int>scores)
{
    vector<int> rewards = vector<int>(scores.size(),1);
    for(int i = 1 ; i< scores.size();i++)
    {
        if(scores[i]>scores[i-1])
            rewards[i] = rewards[i-1] + 1; 
    }

    for(int i = scores.size() -2;i >= 0;i--)
    {
        if(scores[i]>scores[i+1])
        {
            rewards[i] = m ax(rewards[i],rewards[i+1]+1);
        }
    }
    cout<<endl;
    for(int x:rewards)
    {
        cout<<"  "<<x;
    }
}


int main()
{
    minRewards({800, 400, 20, 10, 30, 61, 70, 90, 17, 21, 22, 13, 12, 11, 8, 4, 2, 1, 3, 6, 7, 9, 0, 68, 55, 67, 57, 60, 51, 661, 50, 65, 53});
    cout<<endl<<endl;
    return 0;
}