#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> newPrices(0);
        
        int j = 0;
        while(j < n) {
            while(j+1 < n && prices[j+1] <= prices[j]) j++;
            if(j == n-1) break;
            else newPrices.push_back(prices[j]);
            while(j+1 < n && prices[j+1] > prices[j]) j++;
            newPrices.push_back(prices[j]);
        }

        n = newPrices.size();
        int maxProfit = 0, maxBalance = INT32_MIN;
        for(int i = 0;i < n;i++) {
            if(i) maxProfit = max(maxProfit, maxBalance + newPrices[i]);
            maxBalance = max(maxBalance, maxProfit - newPrices[i]-fee);
            // cout<<maxBalance<<' '<<maxProfit<<endl;
        }
        return maxProfit;
        /*
            ans = profit[n-1];
            profit[j] = max(balance[i]|0<=i<j) + prices[j]
            balance[j] = max(profit[i] - prices[i]-fee|0<=i<=j)
        */
    }
};