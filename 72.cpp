#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

/*
    dp[i][j] = dp[i-1][j-1] if word1[i] == word2[j]
             = dp[i-1][j] + 1   if delete word1[i]
             = dp[i-1][j-1] + 1 if replace word1[i]
             = dp[i][j-1] + 1   if insert word2[j]
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int> > dp; dp.resize(l1+1);
        for(int i = 0;i <= l1;i++) dp[i].resize(l2+1);
        for(int i = 0;i <= l1;i++)
            for(int j = 0;j <= l2;j++) dp[i][j] = 0x3f3f3f3f;
        for(int i = 0;i <= l1;i++) dp[i][0] = i;
        for(int i = 0;i <= l2;i++) dp[0][i] = i;
        for(int i = 0;i < l1;i++)
            for(int j = 0;j < l2;j++){
                if(word1[i] == word2[j]) dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + 1);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j+1] + 1);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i+1][j] + 1);
            }
        for(int i = 0;i <= l1;i++){
            for(int j = 0;j <= l2;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
        return dp[l1][l2];
    }
};

int main() {
    Solution sol;
    string s = "intention", p = "execution";
    cout<<sol.minDistance(s,p)<<endl;
    return 0;
}