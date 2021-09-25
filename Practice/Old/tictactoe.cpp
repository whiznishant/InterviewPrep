
#include<iostream>
#include<string.h>

using namespace std;

class TicTacToe
{
    public : char board[3][3];
    public:
    TicTacToe()
    {
       memset(board,0,sizeof(board));
    }
    void PrintBoard()
    {
        for(int r=0;r<3;r++){
            cout<<endl;
            for(int c=0;c<3;c++)
            {
                cout<<"\t"<<board[r][c];
            }
        }
        cout<<endl<<endl<<endl;
    }

    void NullBoard()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j] = '.';
            }
        }
    }

    void TakeInput()
    {
        cout<<endl<<"Enter to mark ";
        int row,col;
        cin>>row>>col;
        //cin>>col;
        if(board[row][col] != '.')
        {
            cout<<endl<<"Cannot...";
            TakeInput();
        }
        else
        {
            board[row][col] = 'X';
            PrintBoard();
        }
    }
};

int main()
{
    TicTacToe t;
    t.NullBoard();
    t.PrintBoard();
    t.TakeInput();
    
    return 0;
}