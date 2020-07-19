#include <string>
#include <vector>

#include <string>
#include <vector>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT32_MAX;
        vector<vector<int> > dp(2);
        for(int i = 0;i < 2;i++) 
            dp[i].resize(n);
        dp[0][0] = triangle[0][0];
        if(n == 1) return dp[0][0]; 

        for(int i = 1;i < n;i++) {
            int nowRow = i % 2;
            for(int j = 0;j <= i;j++) {
                dp[nowRow][j] = INT32_MAX;
                if(j < i)
                    dp[nowRow][j] = min(dp[nowRow][j], dp[1-nowRow][j]+triangle[i][j]);
                if(j)
                    dp[nowRow][j] = min(dp[nowRow][j], dp[1-nowRow][j-1]+triangle[i][j]);
                if(i == n-1)
                    ans = min(ans, dp[nowRow][j]);
            }
        }
        return ans;
    }
};