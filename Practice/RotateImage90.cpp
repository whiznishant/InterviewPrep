
using namespace std;
#include<iostream>
#include<vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // exchange rows to cols
        int rows = matrix.size(); 
        if(rows == 0)
            return;
        int cols = matrix[0].size();
        if(cols == 0)
            return;


        for(int i=0;i<rows;i++)
        {
            for(int j=i;j<cols;j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        int startCol = 0;
        int endCol = cols - 1;
        while(startCol < endCol)
        {
            for(int i=0;i<rows;i++)
            {
                int t = matrix[i][startCol];
                matrix[i][startCol] = matrix[i][endCol];
                matrix[i][endCol] = t;
            }
            startCol++;endCol--;
        }
    }
};

int main()
{
    Solution a;
    vector<vector<int>> mat = {{}};
    a.rotate(mat);

    cout<<"done";
}