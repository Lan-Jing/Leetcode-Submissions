#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

/*
    O(n^2) DP.
    1. Iterate each segmentation [0,i][i+1,j][j+1,len-1] and check. O(n^5)
    2. Take O(n^2) to construct two tables for O(1) check to [0,i] and [j+1,len-1] parts. This reduces complexity to O(n^3)
    3. DP. Going further beyond 2., we have a O(n^2) DP to construct a lookup table for arbitrary substring [i,j]. 
        dp[i][j] = 1, if i == j or i == j-1
        dp[i][j] = dp[i+1][j-1], if s[i] == s[j]
        dp[i][j] = 0, otherwise
*/

class Solution {
public:
    bool palindrome(string s) {
        int len = s.size(), l = 0, r = len-1;
        while(l <= r) {
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    bool checkPartitioning(string s) {
        int len = s.size();
        
        // for(int i = 0;i < len-2;i++) {
        //     string subStr = s.substr(0, i+1);
        //     if(palindrome(subStr) == false)
        //         continue;
        //     for(int j = i+1;j < len-1;j++) {
        //         string a = s.substr(i+1, j-i), b = s.substr(j+1, len-j-1);
        //         if(palindrome(a) == false || palindrome(b) == false)
        //             continue;
        //         return true;
        //     }
        // }

        // vector<int> lRev;
        // vector<int> rRev;
        // for(int i = 0;i < len;i++) {
        //     if(palindrome(s.substr(0, i+1)))
        //         lRev.push_back(i);
        // }
        // for(int i = len-1;i >= 0;i--) {
        //     if(palindrome(s.substr(i, len-i)))
        //         rRev.push_back(i);
        // }
        // for(int i = 0;i < lRev.size();i++) {
        //     for(int j = 0;j < rRev.size();j++) {
        //         int l = lRev[i], r = rRev[j];
        //         if(r-l <= 1)
        //             continue;
        //         if(palindrome(s.substr(l+1, r-l-1)))
        //             return true;
        //     }
        // }

        vector<vector<bool> > dp(len);
        for(int i = 0;i < len;i++) 
            dp[i].resize(len);

        for(int j = 0;j < len;j++) {
            for(int i = j;i >= 0;i--) {
                if(s[i] == s[j]) {
                    dp[i][j] = j-i <= 1 ? true : dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        for(int i = 0;i < len-2;i++) {
            for(int j = i+1;j < len-1;j++) {
                if(dp[0][i] && dp[i+1][j] && dp[j+1][len-1])
                    return true;
            }
        }
        return false;
    }
};