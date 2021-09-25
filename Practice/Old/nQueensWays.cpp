#include<iostream>
#include<vector>
using namespace std;

bool isInDiagonal(int r1,int c1,int r2 , int c2)
{
	if(abs(r2-r1) == abs(c2-c1) )	
		return true;
	return false;
}

bool CanPlaceQueen(int rowIdx,int colIdx, vector<std::pair<int,int>> & placed_queens )
{
	for(auto x:placed_queens)
	{
		if( x.first == rowIdx || x.second == colIdx)
			return false;
		if(isInDiagonal(x.first,x.second,rowIdx,colIdx))
			return false;
	}
	return true;
}

bool nQueensHelper(int colIdx,int n, int &numOfWays, vector<std::pair<int,int>> & placed_queens)
{
	//we have placed queens in from 0 to n-1 cols. 
	// We are done.  We have our solutions.
	if(colIdx == n) 
	{
		numOfWays++;
		return true;
	}
			
	for(int rowIdx = 0;rowIdx < n; rowIdx++)
	{
		if(CanPlaceQueen(rowIdx,colIdx,placed_queens))
		{
			placed_queens.push_back(std::pair<int,int>(rowIdx,colIdx));
			bool res = nQueensHelper(colIdx+1,n,numOfWays,placed_queens);
            //In any case we need to backtrack and try new solutions instead of returning.   
            placed_queens.pop_back();
		}	        
	}
	return false;	
}

int nonAttackingQueens(int n) {
  // Write your code here.
	vector<std::pair<int,int>> placed_queens;
	int numWays = 0;
	nQueensHelper(0,n,numWays,placed_queens);
  return numWays;
}

int main()
{
    int ways = nonAttackingQueens(14);
    cout<<endl<<ways;
    return 0;
}