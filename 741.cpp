#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

/*
    The O(n^4) solution can be improved to O(n^3).
    In order to minimize time complexity, we have the two points (y1,x1) and (y2,x2) to move in every iteration, 
    which means they share a same step parameter. Therefore, we first take the numebr of steps, then for the two 
    y parameters we get two x's in O(1) time, making the solution O(n^3).
    Ranges of both parameter x and y should be carefully taken care of.
*/

class Solution {
public:
    int gox[2]={-1,0}, goy[2]={0,-1};
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m+n][m][m];
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0][0] = grid[0][0];
        for(int step = 1;step < m+n-1;step++)
            for(int y1 = max(0,step-n+1);y1 <= min(m-1,step);y1++) 
            // y and x should both fall in valid ranges.
                for(int y2 = max(0,step-n+1);y2 <= min(m-1,step);y2++){
                    int x1 = step-y1, x2 = step-y2;
                    if(grid[y1][x1] == -1 || grid[y2][x2] == -1) continue;
                    for(int m1 = 0;m1 < 2;m1++)
                        for(int m2 = 0;m2 < 2;m2++){
                            int py1 = y1 + goy[m1], px1 = x1 + gox[m1];
                            int py2 = y2 + goy[m2], px2 = x2 + gox[m2];
                            if(py1 < 0 || px1 < 0 || py2 < 0 || px2 < 0) continue;
                            dp[step][y1][y2] = max(dp[step][y1][y2],
                                                   dp[step-1][py1][py2] + grid[y1][x1] + grid[y2][x2] - (y1==y2 && x1==x2 && grid[y1][x1] == 1));
                        }
                }
        return dp[m+n-2][m-1][m-1] > 0 ? dp[m+n-2][m-1][m-1] : 0;
    }
};

int main() {
    Solution sol;
    vector<int> tmp;
    vector<vector<int> > input;
    tmp = {0,1,-1}; input.push_back(tmp);
    tmp = {1,1,-1}; input.push_back(tmp);
    tmp = {1,0,1}; input.push_back(tmp);
    cout<<sol.cherryPickup(input)<<endl;
}