#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stdint.h>

class Solution {
public:
    bool check(vector<vector<int> > &dungeon, int HP) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<long long> > dp(m);
        for(int i = 0;i < m;i++) dp[i].resize(n);
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(!i && !j) dp[i][j] = HP + dungeon[i][j];
                else if(!i) dp[i][j] = (dp[i][j-1] > 0 ? dp[i][j-1] : INT32_MIN) + dungeon[i][j];
                else if(!j) dp[i][j] = (dp[i-1][j] > 0 ? dp[i-1][j] : INT32_MIN) + dungeon[i][j];
                else dp[i][j] = max(dp[i-1][j] > 0 ? dp[i-1][j] : INT32_MIN,
                                    dp[i][j-1] > 0 ? dp[i][j-1] : INT32_MIN) + dungeon[i][j];
            }
        return dp[m-1][n-1] > 0; 
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        long long l = 1, r = -1;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                r += dungeon[i][j] < 0 ? dungeon[i][j] : 0;
        r = -r;
        while(l < r){
            int mid = (l + r) / 2;
            cout<<mid<<endl;
            if(check(dungeon,mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input;
    vector<int> line;
    line = {-2,-3,3}; input.push_back(line);
    line = {-5,-10,1}; input.push_back(line);
    line = {10,30,-5}; input.push_back(line);
    cout<<sol.calculateMinimumHP(input)<<endl;
    return 0;
}