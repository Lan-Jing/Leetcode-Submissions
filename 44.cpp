#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

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