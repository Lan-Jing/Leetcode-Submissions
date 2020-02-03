#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>

/*
    easy DP. dp[k][i][j] represents substring s1[0-i] and s2[0-j] interleave s3[0-k]
    Then for each char s3[k], it can be matched by either s1[i] or s2[j].
    Answer should be dp[l3][l1][l2].

    Be careful on the range restrictions. s1[0-i] and s2[0-j] combined can't be longer than s3[0-k]
    and their length range should also be considered respectively.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3) return false;
        vector<vector<vector<bool> > > dp;
        dp.resize(l3+1);
        for(int i = 0;i <= l3;i++){
            dp[i].resize(l1+1);
            for(int j = 0;j <= l1;j++) dp[i][j].resize(l2+1);
        }
        dp[0][0][0] = 1;
        for(int k = 0;k < l1;k++)
            if(s3[k] != s1[k]) break;
            else dp[k+1][k+1][0] = 1;
        for(int k = 0;k < l2;k++)
            if(s3[k] != s2[k]) break;
            else dp[k+1][0][k+1] = 1;
        for(int k = 0;k < l3;k++)
            for(int i = 0;i <= min(k,l1-1);i++)
                for(int j = 0;j <= min(k-i-1,l2-1);j++){
                    cout<<k<<' '<<i<<' '<<j<<endl;
                    if(s3[k] == s1[i]) dp[k+1][i+1][j+1] = dp[k+1][i+1][j+1] | dp[k][i][j+1];
                    if(s3[k] == s2[j]) dp[k+1][i+1][j+1] = dp[k+1][i+1][j+1] | dp[k][i+1][j];
                //    if(dp[k+1][i+1][j+1]) cout<<k<<' '<<i<<' '<<j<<endl;
                }
        return dp[l3][l1][l2];
    }
};

int main() {
    Solution sol;
    string s1 = "cacccaa", s2 = "acccaacabbbab", s3 = "accccaaaccccabbaabab";
    cout<<sol.isInterleave(s1,s2,s3)<<endl;
    return 0;
}