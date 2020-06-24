#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i = 0;
        int buyPrice, ans = 0;
        while(i < n) {
            while(i+1 < n && prices[i+1] <= prices[i]) i++;
            buyPrice = prices[i];
            while(i+1 < n && prices[i+1] >= prices[i]) i++;
            ans += prices[i] - buyPrice;
            i++;
        }

        return ans;
    }
};