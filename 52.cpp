#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

class Solution {
public:
    void printBoard(vector<vector<string> > &res, vector<int> &pos) {
        vector<string> board;
        for(int i = 0;i < pos.size();i++){
            string tmp;
            for(int j = 0;j < pos.size();j++)
                if(j == pos[i]) tmp.push_back('Q');
                else tmp.push_back('.');
            board.push_back(tmp);
        }
        res.push_back(board);
    }
    bool checkBoard(vector<int> &pos, int now, int newPos) {
        for(int i = 0;i < now;i++) if(pos[i] == newPos) return false;
        for(int i = 1;now-i >= 0;i++)
            if(pos[now-i] == newPos-i || pos[now-i] == newPos+i) return false;
        return true;
    }
    void NQueens(vector<vector<string> > &res, vector<int> &pos, int now) {
        if(now == pos.size()){
            printBoard(res, pos);
            return ;
        }
        for(int i = 0;i < pos.size();i++){
            if(!checkBoard(pos,now,i)) continue;
            pos[now] = i;
            NQueens(res,pos,now+1);
        }
    }
    int totalNQueens(int n) {
        vector<vector<string> > res;
        if(!n) return 0;
        vector<int> pos; pos.resize(n);
        NQueens(res,pos,0);
        return res.size();
    }
};


int main() {
    Solution sol;
    cout<<sol.totalNQueens(5)<<endl;
    return 0;
}