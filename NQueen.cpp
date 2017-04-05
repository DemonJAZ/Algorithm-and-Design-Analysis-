#include <iostream>
using namespace std;
bool safetoplace(int **board,int row,int col,int n)
{
    for (int i = 0; i < row; ++i)
    {
        if(board[i][col]==1)
            return false;
    }
    for (int i = 0; i < col; i++)
    {
        if(board[row][i]==1)
            return false;
    }

    for(int i=row,j=col; i>=0 && j>=0 ;i--,j--)
    {
        if(board[i][j]==1)
            return false;
    }

    for(int i=row , j=col ; i>=0 && j<n ; i-- ,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

bool placequeen(int **board,int n,int row)
{
    if(row>=n)
        return true;

    for(int col = 0 ; col<n ; col++)
    {
        if(safetoplace(board,row,col,n))
        {
            board[row][col]=1;
            if(placequeen(board,n,row+1))
            {
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int **board;
    board = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        board[i] = new int[n];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            board[i][j]=0;
        }
    }


    if(placequeen(board,n,0))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
     cout<<"Queens Can't be placed"<<endl;
    return 0;
}
