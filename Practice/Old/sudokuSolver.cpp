#include<iostream>
#include<vector>
#include<math.h>
#include<assert.h>

using namespace std;
class SudokuSolver
{
    private:
    char board[9][9];
    int count;

    public:
    SudokuSolver(char newboard[9][9])
    {
        std::copy(&newboard[0][0],&newboard[0][0]+9*9,&board[0][0]);
        count = 0 ;
        assert(ValidateBoard() && "Invalid board !!");
        PrintBoard();
    }

    bool ValidateBoard()
    {
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c] != '.')
                {
                    char value = board[r][c];
                    board[r][c] = '.';
                    bool valid = CanPlaceValue(value,r,c);
                    board[r][c] = value;
                    if(!valid)
                        return false;
                }
            }
        }
        return true;
    }

    bool Solve()
    {
        bool ret = SolveHelper(0,0);
        cout <<endl<<count;
        return ret;
    }

    bool SolveHelper(int row, int col )
    {
        //cout<<endl<<"Called for "<<row<<","<<col;
        if(col == 9)
        {
            row = row + 1;
            col = 0;
        }
        if(row == 9)
        {
            return true;
        }        
        if(board[row][col] != '.')
            return SolveHelper(row,col+1);
        
        char valueToTry = '.';

        for(int i=1; i<=9 ;i++ )
        {
            count++;
            valueToTry = ((to_string(i)).c_str())[0];
            //cout<<endl<<"Value to try == "<<valueToTry;
            if(CanPlaceValue(valueToTry,row,col))
            {
                board[row][col] = valueToTry;
                //cout<<endl<<"Calling solving helper for "<<row<<" "<<col+1;
                bool ret = SolveHelper(row,col+1);
                if(!ret)
                {
                    board[row][col] = '.';
                }
                else
                {
                    //cout<<endl<<"Value set at " <<row<<","<< col << " = "<< valueToTry;  
                    return true;                                      
                }
            }
        }
        return false;
    }

    bool CanPlaceValue(char val,int row, int col)
    {
        //Check if that value does not exist in the col and row
        for(int r=0;r<9;r++)
        {
            if(board[r][col] == val)
            {
                return false;
            }
        }

        for(int c=0;c<9;c++)
        {
            if(board[row][c] == val)
            {
                return false;
            }
        }
        //Check if the value does not exist in the local subgrid.
        int rowStart=0,colStart=0;
        GetLocalSubGridStartRowAndColIdx(row,col,rowStart,colStart);

        for(int r = rowStart; r < rowStart + 3;r++)
        {
            for(int c= colStart; c < colStart + 3;c++)
            {
                if(board[r][c] == val)
                {
                    return false;
                }
            }
        }             
        return true;
    }

    void GetLocalSubGridStartRowAndColIdx(int row, int col , int &rowStart,int &colStart)
    {
        int subgridRowIdx = ceil(row/3);
        int subgridColIdx = ceil(col/3);
        rowStart = 3*subgridRowIdx;
        colStart = 3*subgridColIdx;
    }

    void PrintAndVerifySubGridIndexes()
    {
        int subgridRIdx,subgridCIdx;
        for(int r=0;r < 9; r++)
        {
            for(int c=0;c < 9; c++)
            {
                GetLocalSubGridStartRowAndColIdx(r,c,subgridRIdx,subgridCIdx);
            }
        }
    }

    void PrintBoard()
    {
        for(int r=0;r < 9; r++)
        {
            cout<<endl;
            for(int c=0;c < 9; c++)
            {
                cout<<board[r][c]<<"  ";
            }
        }
         cout<<endl;
    }


};
int main()
{
    char board123[9][9] = { 
        { '8','.','.','.','7','.','.','9','.' },
        { '3','.','.','.','.','6','8','.','.' },
        { '.','5','.','.','.','8','3','6','.' },
        { '4','.','.','.','1','.','.','5','.' },
        { '.','.','5','.','.','.','7','.','.' },
        { '.','3','.','.','2','.','.','.','9' },
        { '.','8','3','5','.','.','.','7','.' },
        { '.','.','2','8','.','.','.','.','4' },
        { '.','7','.','.','9','.','.','.','8' }
    };  

    char board2[9][9] = { 
        { '9','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.','.' }
    };   

    SudokuSolver A(board2);    
    A.Solve();
    A.PrintBoard();
}
