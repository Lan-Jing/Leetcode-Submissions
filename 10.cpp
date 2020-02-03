#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    not-easy DP. 
    First trick for easy DP implementation is leaving the 0 areas of DP arrays, and
    use them to represent empty situations, such as dp[0][0] for initialization.
    Otherwise we have to code annoying edge situations explictly. 

    for met '*', we can take results from its previous char:
        1. count as single for the previous char.
        2. count as multiple when the char continues to match s[j].
        3. count as empty.
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.size(), lp = p.size();
        vector<vector<bool> > dp; dp.resize(lp+1);
        for(int i = 0;i <= lp;i++) dp[i].resize(ls+1);
        dp[0][0] = 1;
        for(int i = 1;i < lp;i++)
            if(p[i] == '*') dp[i+1][0] = dp[i-1][0];
        for(int i = 0;i < lp;i++)
            for(int j = 0;j < ls;j++){
                if(p[i] == '*'){
                    if(i) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i-1][j+1]);
                    if(p[i-1] == '.' || p[i-1] == s[j]){
                        dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
                        if(j && (s[j-1] == s[j] || p[i-1] == '.')) 
                            dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
                    }
                }else if(p[i] == '.' || p[i] == s[j])
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
            }
        for(int i = 0;i <= lp;i++){
            for(int j = 0;j <= ls;j++) cout<<dp[i][j]<<' '; cout<<endl;
        }
        return dp[lp][ls];
    }
};

int main() {
    Solution sol;
    string s = "ab", p = ".*";
    cout<<sol.isMatch(s,p)<<endl;
    return 0;
}