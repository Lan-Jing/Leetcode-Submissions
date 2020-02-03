#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    a simpler version of Problem 10.
    "match" means: p[i] == s[j] or p[i] == '?'
    Then we only need to consider the '*' situations.
    When we meet a '*', we can:
        1. take it as an empty char, that is dp[i][j] = dp[i-1][j]
        2. take it as any single char, dp[i][j] = dp[i-1][j-1]
        3. take it as string with multiple chars, that is dp[i][j] = dp[i][j-1], which 
           takes result from situation 2 from the last loop.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int lp = p.length(), ls = s.length();
        vector<vector<bool> > dp; dp.resize(lp+1);
        for(int i = 0;i <= lp;i++) dp[i].resize(ls+1);
        dp[0][0] = 1;
        for(int i = 0;i < lp;i++){
            if(p[i] != '*') break;
            else dp[i+1][0] = 1;
        }
        for(int i = 0;i < lp;i++)
            for(int j = 0;j < ls;j++){
                if(p[i] == '*'){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
                }else if(p[i] == '?' || p[i] == s[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
                }
            }
        for(int i = 0;i <= lp;i++){
            for(int j = 0;j <= ls;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
        return dp[lp][ls];
    }
};

int main() {
    Solution sol;
    string s = "ho", p = "**ho";
    cout<<sol.isMatch(s,p)<<endl;
    return 0;
}