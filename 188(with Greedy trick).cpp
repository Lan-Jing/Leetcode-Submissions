#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    When times of transaction allowed outnumbers price nodes, it becomes a greedy one.
    Then each time stock price goes up, we gain profit.

    Otherwise we have a O(kN^2) DP. Iterate the selling point j and transaction time k,
    we have:
        1. dp[k][j] = max(dp[k][j-1])  no move
        2. dp[k][j] = max(dp[k-1][i-1] + price[j]-price[i])  
           pick i(<j) as buying time, finishing the kth transaction.
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
        int ans = 0, buyPrice;
        if(k > newPrices.size()/2){
            for(int i = 0;i < newPrices.size();i++){
                if(!i){
                    if(newPrices[i] < newPrices[i+1]) buyPrice = newPrices[i];
                }else if(i == newPrices.size()-1){
                    if(newPrices[i-1] < newPrices[i]) ans += newPrices[i]-buyPrice;
                }else{
                    if(newPrices[i] <= newPrices[i-1] && newPrices[i] < newPrices[i+1]) buyPrice = newPrices[i];
                    if(newPrices[i] > newPrices[i-1] && newPrices[i] >= newPrices[i+1]) ans += newPrices[i]-buyPrice;
                }
            }
            return ans;
        } // solve situations with unlimited transactions.
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
        for(int i = 0;i <= k;i++) ans = max(ans,dp[i].back());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {3,2,6,5,0,3,3,2,3,3,6,9};
    cout<<sol.maxProfit(1000,input)<<endl;
    return 0;
}