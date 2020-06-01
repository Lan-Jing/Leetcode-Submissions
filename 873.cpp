#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    unordered_map<int,int> Map;
    int lenLongestFibSubseq(vector<int>& A) {
        int l = A.size(), ans = 0;
        for(int i = 0;i < l;i++) Map[A[i]] = i;
        vector<vector<int> > dp;
        dp.resize(l);
        for(int i = 0;i < l;i++) dp[i].resize(l);
        
        for(int i = 2;i < l;i++)
            for(int j = 1;j < i;j++) {
                if(Map.count(A[i]-A[j]) && Map[A[i]-A[j]] < j) {
                    dp[j][i] = dp[Map[A[i]-A[j]]][j] ? dp[Map[A[i]-A[j]]][j]+1 : 3;
                    ans = max(ans, dp[j][i]);
                }
            }
        
        return ans;
    } 
};