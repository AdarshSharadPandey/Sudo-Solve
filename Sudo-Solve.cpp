#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &sudoku, int row, int col, int val)
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[row][i]==val)
            return false;
        if(sudoku[i][col]==val)
            return false;
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            return false;
    }
    return true;
}
bool sudokuSolver(vector<vector<int>> &sudoku)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(sudoku[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(isSafe(sudoku,i,j,k))
                    {
                        sudoku[i][j]=k;
                        if(sudokuSolver(sudoku))
                            return true;
                        else sudoku[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> sudoku(9,vector<int>(9,0));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int k; cin>>k;
            sudoku[i][j]=k;
        }
    }
    cout<<endl;
    sudokuSolver(sudoku);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}
