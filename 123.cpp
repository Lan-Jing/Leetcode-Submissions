#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    a special case k = 2 for Problem 188
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> newPrices;
        int flag = 0;
        for(int i = 0;i < prices.size();i++){
            if(!i || i == prices.size()-1) newPrices.push_back(prices[i]);
            else if((prices[i] < prices[i-1] && prices[i] > prices[i+1]) || 
                    (prices[i] > prices[i-1] && prices[i] < prices[i+1]))
                flag = 0;
            else if(prices[i] == prices[i-1]){
                if(!flag) newPrices.push_back(prices[i]), flag = 1;
            }else newPrices.push_back(prices[i]), flag = 0;
        }
        if(newPrices.size() < 2) return 0;
        vector<vector<int> > dp; dp.resize(3);
        for(int i = 0;i <= 2;i++) dp[i].resize(newPrices.size());
        for(int j = 1;j < newPrices.size();j++)
            for(int p = 1;p <= 2;p++){
                dp[p][j] = max(dp[p][j],dp[p][j-1]); // no deal
                for(int i = 0;i < j;i++){
                    if(newPrices[i] >= newPrices[j]) continue;
                    dp[p][j] = max(dp[p][j], (i ? dp[p-1][i-1] : 0) + newPrices[j]-newPrices[i]);
                }
            }
        int ans = 0;
        for(int i = 0;i <= 2;i++) ans = max(ans,dp[i].back());
        return ans;
    }
};