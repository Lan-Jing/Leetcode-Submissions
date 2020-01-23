#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

/*
    dfs Sudoku solver.
*/

class Solution {
public:
    int rowCheck[9][10], colCheck[9][10], gridCheck[9][10];
    int flag;
    void getNextPos(vector<vector<char> > board, int &ny, int &nx, int y, int x){
        ny = y, nx = x;
        while(board[ny][nx] != '.'){
            if(nx < 8) nx++; else ny++, nx = 0;
            if(ny == 9) return ;
        }
    }
    void solve(vector<vector<char> > &board, int y, int x) {
        if(flag) return ;
        if(y == 9){
            flag = 1; return ;
        }
        int grid = (y/3)*3 + x/3;
        for(int i = 1;i <= 9;i++){
            if(rowCheck[y][i] || colCheck[x][i] || gridCheck[grid][i]) continue;
            board[y][x] = i + '0';
            rowCheck[y][i] = colCheck[x][i] = gridCheck[grid][i] = 1;
            int ny, nx;
            getNextPos(board,ny,nx,y,x);
            solve(board,ny,nx);
            if(flag) return ;
            rowCheck[y][i] = colCheck[x][i] = gridCheck[grid][i] = 0;
        }        
        board[y][x] = '.';
    }
    void solveSudoku(vector<vector<char> >& board) {
        memset(rowCheck,0,sizeof(rowCheck));
        memset(colCheck,0,sizeof(colCheck));
        memset(gridCheck,0,sizeof(gridCheck));
        flag = 0;
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++){
                int grid = (i/3)*3 + j/3;
                if(board[i][j] == '.') continue;
                rowCheck[i][board[i][j]-'0'] = 1, rowCheck[i][0]++;
                colCheck[j][board[i][j]-'0'] = 1, colCheck[j][0]++;
                gridCheck[grid][board[i][j]-'0'] = 1, gridCheck[grid][0]++;
            } // initialize check lists.
        int sy, sx; getNextPos(board,sy,sx,0,0);
        solve(board,sy,sx);
    }
};

int main() {
    Solution sol;
    return 0;
}