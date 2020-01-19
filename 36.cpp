#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[10][10], colCheck[10][10], gridCheck[9][10];
        memset(rowCheck,0,sizeof(rowCheck));
        memset(colCheck,0,sizeof(colCheck));
        memset(gridCheck,0,sizeof(gridCheck));
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                if(rowCheck[i][board[i][j]-'0']) return false;
                else rowCheck[i][board[i][j]-'0'] = 1;
            }
        for(int j = 0;j < 9;j++)
            for(int i = 0;i < 9;i++){
                if(board[i][j] == '.') continue;
                if(colCheck[j][board[i][j]-'0']) return false;
                else colCheck[j][board[i][j]-'0'] = 1;
            }
        for(int grid = 0;grid < 9;grid++)
            for(int k = 0;k < 9;k++){
                int y = k/3 + (grid/3)*3;
                int x = k%3 + (grid%3)*3;
                if(board[y][x] == '.') continue;
                if(gridCheck[grid][board[y][x]-'0']) return false;
                else gridCheck[grid][board[y][x]-'0'] = 1;
            }
        return true;
    }
};

int main(){

}