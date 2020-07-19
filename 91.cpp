#include <iostream>
using namespace std;
#include <string>
#include <vector> 

class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        vector<int> dp(l);

        dp[0] = s[0] == '0' ? 0 : 1;
        for(int i = 1;i < l;i++) {
            if(s[i] != '0') dp[i] += dp[i-1];
            if(s[i-1] != '0') {
                string tmp = s.substr(i-1,2);
                if(tmp <= "26")
                    dp[i] += i >= 2 ? dp[i-2] : 1;
            }
        }

        return dp[l-1];
    }
};