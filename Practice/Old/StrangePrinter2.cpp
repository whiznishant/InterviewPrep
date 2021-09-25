#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        
        return true;
    }
        
    class Rectangle
    {
        public :
            int topLeftx,topLefty,bottomRightx,bottomRighty;
    };
        
    vector<Rectangle> GetAllRectangles(vector<vector<int>>& targetGrid)
    {
        unordered_set<int> colorsfound;
        vector<Rectangle> out;
        for(int i =0;i < targetGrid.size(;i++)
        {
            for(int j=0;j < targetGrid[0].size;j++)
            {
                colorsfound.
            }
        }
        
        
        return out;
    }
    
    
};

int main()
{
    vector<vector<int>> targetGrid ={ {1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};
    Solution  a;
    a.GetAllRectangles(targetGrid);

    return 0;
}