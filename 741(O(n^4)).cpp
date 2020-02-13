#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

/*
    a classic 2-D DP problem with 2 positions as status.
    In Order to finish traverse on two different paths, we can use two coordinate params (y1,x1) and (y2,x2) moving concurrently.
    Then the problem turns out to be easy. However, the only situtation we have to worry about is when two points meet.
    It can be easily handled by only allowing the cherry to be picked up once.
*/

class Solution {
public:
    int gox[2]={-1,0}, goy[2]={0,-1};
    int cherryPickup(vector<vector<int> >& grid) {
        int dp[51][51][51][51];
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0][0][0] = grid[0][0];
        int m = grid.size(), n = grid[0].size();
        for(int y1 = 0;y1 < m;y1++)
            for(int x1 = 0;x1 < n;x1++)
                for(int y2 = 0;y2 < m;y2++)
                    for(int x2 = 0;x2 < n;x2++){
                        if(grid[y1][x1] == -1 || grid[y2][x2] == -1) continue;
                        cout<<y1<<','<<x1<<' '<<y2<<' '<<x2<<endl;
                        for(int move1 = 0;move1 < 2;move1++)
                            for(int move2 = 0;move2 < 2;move2++){
                                int prevy1 = y1 + goy[move1], prevx1 = x1 + gox[move1];
                                int prevy2 = y2 + goy[move2], prevx2 = x2 + gox[move2];
                                if(prevy1 < 0 || prevx1 < 0 || prevy2 < 0 || prevx2 < 0) continue;
                                dp[y1][x1][y2][x2] = max(dp[y1][x1][y2][x2],
                                                         dp[prevy1][prevx1][prevy2][prevx2] + grid[y1][x1] + grid[y2][x2] - (y1==y2 && x1==x2 && grid[y1][x1] == 1)); 
                            }
                    }
        return dp[m-1][n-1][m-1][n-1] > 0 ? dp[m-1][n-1][m-1][n-1] : 0;
    }
};

int main() {
    Solution sol;
    vector<int> tmp;
    vector<vector<int> > grid;
    tmp = {0,1,-1}; grid.push_back(tmp);
    tmp = {1,0,-1}; grid.push_back(tmp);
    tmp = {1,1,1}; grid.push_back(tmp);
    cout<<sol.cherryPickup(grid)<<endl;
    return 0;
}