#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(!obstacleGrid.size()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long int> > dp;
        dp.resize(m);
        for(int i = 0;i < m;i++) dp[i].resize(n);
        dp[0][0] = !obstacleGrid[0][0];
        for(int i = 0;i < m;i++)
            for(int j = 0;Nj < n;j++){
                if(i < m-1 && !obstacleGrid[i+1][j]) dp[i+1][j] += dp[i][j];
                if(j < n-1 && !obstacleGrid[i][j+1]) dp[i][j+1] += dp[i][j];
            }
        return dp[m-1][n-1];
    }
};

int main(){

}