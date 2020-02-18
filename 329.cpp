#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int gox[4]={-1,1,0,0}, goy[4]={0,0,1,-1};
    int dfs(vector<vector<int> > &matrix, int &ans, vector<vector<int> > &dp, int y, int x) {
        if(dp[y][x]) return dp[y][x];
        for(int i = 0;i < 4;i++){
            int nx = x + gox[i], ny = y + goy[i];
            if(nx < 0 || ny < 0 || ny >= matrix.size() || nx >= matrix[0].size() || matrix[ny][nx] >= matrix[y][x])
                continue;
            dp[y][x] = max(dp[y][x],dfs(matrix,ans,dp,ny,nx));
        }
        dp[y][x]++;
        ans = max(ans,dp[y][x]);
        return dp[y][x];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        if(!m) return ans;
        int n = matrix[0].size();
        vector<vector<int> > dp(m);
        for(int i = 0;i < m;i++)
            dp[i].resize(n);
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(!dp[i][j])
                    dfs(matrix,ans,dp,i,j);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input;
    vector<int> tmp;
    tmp = {9,9,4}; input.push_back(tmp);
    tmp = {6,6,8}; input.push_back(tmp);
    tmp = {2,1,1}; input.push_back(tmp);
    cout<<sol.longestIncreasingPath(input)<<endl;
    return 0;
}