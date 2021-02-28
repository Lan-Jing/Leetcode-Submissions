#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

/*
    1. O(n^2) DP
    2. Similar to a merge sort. But think of a special case, when word1[p1] == word2[p2].
       You cannot arbitrarily take one of them, since the following choice will be affected. One can still make decision by
       checking the first pair of distinct chars that follows, pick the word that has the larger character.
       Sound familar? It's exactly taking the order of word1[p1:] and word2[p2:].
*/

class Solution {
public:
    const int n = 3010;
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        string ans = "";    

        /*
        vector<vector<string> > dp(2);
        for(int i = 0;i < 2;i++) dp[i].resize(n);   
        
        dp[0][0] = "";
        for(int i = 1;i <= n1+n2;i++) {
            for(int j = max(0, i-n2);j <= min(i, n1);j++) {
                int ii = i % 2;
                dp[ii][j] = "";
                if(i > j && dp[1-ii][j]+word2[i-j-1] > dp[ii][j]) {
                    dp[ii][j] = dp[1-ii][j]+word2[i-j-1];
                }
                if(j && dp[1-ii][j-1]+word1[j-1] > dp[ii][j]) {
                    dp[ii][j] = dp[1-ii][j-1]+word1[j-1];
                }
                // cout<<i<<','<<j<<':'<<dp[ii][j]<<endl;
            }
        }   
        ans = dp[(n1+n2)%2][n1];
        */  

        int p1 = 0, p2 = 0;
        while(ans.size() < n1+n2) {
            if(p1 == n1) {
                ans += word2[p2++];
                continue;
            } else if(p2 == n2) {
                ans += word1[p1++];
                continue;
            }

            if(word1[p1] > word2[p2] || (word1[p1]==word2[p2] && word1.substr(p1) >= word2.substr(p2))) {
                ans += word1[p1++];
            } else if(word1[p1] < word2[p2] || (word1[p1]==word2[p2] && word2.substr(p2) > word1.substr(p1))) {
                ans += word2[p2++];
            }
            
        }   
        return ans;
    }
};