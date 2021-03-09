#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

class Solution {
public:
    void dfs(int nowCost, int now, int target, int &ans, vector<int>& baseCosts, vector<int>& toppingCosts) {
        int n = baseCosts.size(), m = toppingCosts.size();
        if(now == m+1) {
            if(abs(target-nowCost) < abs(target-ans) || (abs(target-nowCost)==abs(target-ans) && nowCost < ans)) {
                ans = nowCost;
            }
            return ;
        }
        if(now == 0) {
            for(int i = 0;i < n;i++) {
                dfs(nowCost+baseCosts[i], now+1, target, ans, baseCosts, toppingCosts);
            }
        } else {
            for(int i = 0;i <= 2;i++) {
                dfs(nowCost+toppingCosts[now-1]*i, now+1, target, ans, baseCosts, toppingCosts);
            }
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = -0x3f3f3f3f;

        dfs(0, 0, target, ans, baseCosts, toppingCosts);

        return ans;
    }
};