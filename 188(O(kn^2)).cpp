#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    a O(kN^2) solution without greedy trick on special cases.
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
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
        k = min(k,(int)newPrices.size()/2);
        for(int i = 0;i < newPrices.size();i++) cout<<newPrices[i]<<' '; cout<<endl;
        vector<vector<int> > dp; dp.resize(k+1);
        for(int i = 0;i <= k;i++) dp[i].resize(newPrices.size());
        for(int j = 1;j < newPrices.size();j++)
            for(int p = 1;p <= k;p++){
                dp[p][j] = max(dp[p][j],dp[p][j-1]); // no deal
                for(int i = 0;i < j;i++){
                    if(newPrices[i] >= newPrices[j]) continue;
                    dp[p][j] = max(dp[p][j], (i ? dp[p-1][i-1] : 0) + newPrices[j]-newPrices[i]);
                }
            }
        int ans = 0;
        for(int i = 0;i <= k;i++) ans = max(ans,dp[i].back()), cout<<dp[i].back()<<' '; cout<<endl;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {3,2,6,5,0,3};
    cout<<sol.maxProfit(2,input)<<endl;
    return 0;
}