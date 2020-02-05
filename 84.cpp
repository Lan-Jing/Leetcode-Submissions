#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

/*
    To further improve the solution, we have three strategies.
    1. Divide and conquer solution with segment tree.
        In fact by segment tree we can in O(logn) time find the minimum height in any segment [l,r]
        Then for any single bar, the final answer comes from one of the three cases:
        1) it takes exactly height of this bar.
        2) it takes minimum height of bars to its left.
        3) it takes minimum height of bars to its right.
        So every single bar will be tested as "current" minimum height in recursion, making this algorithm O(nlogn).
    2. stack
        Further consider the ascending-left-wall property, for any bar, the area it produces starts from the first bar 
        from left and ends in the first bar from right, both with smaller heights. This is convenient to maintain through 
        an ascending left-wall stack. When a smaller bar is met, top of the stack is popped, meaning the shorter right wall is found.
        The shorter left one is easy because the stack property permits the second top (if exists) to be the left wall we need.
    3. preprocessing method
        If the stack method is hard to come up with, we can directly calculate information we need. That is, for every bar,
        find the first bar from left and right, both with smaller heights. For instance, if we start from the left side,
        l[i] takes the position of the first smaller height from left. Then for every i, start from i-1, use the recurive-style 
        expression p = l[p], whenever p >= 0 && H[p] >= H[i]. This expression should make p jump descending quickly to the first 
        position with a smaller height. 
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if(!heights.size()) return 0;
        heights.push_back(-1);
        stack<int> stk;
        int ans = 0;
        for(int i = 0;i < heights.size();i++){
            if(stk.empty() || heights[stk.top()] <= heights[i])
                stk.push(i);
            else{
                while(!stk.empty() && heights[stk.top()] > heights[i]){
                    int now = stk.top(); stk.pop();
                    ans = max(ans,stk.empty() ? heights[now]*i : heights[now]*(i-stk.top()-1));
                }
                stk.push(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {4,2,0,3,2,5};
    cout<<sol.largestRectangleArea(input)<<endl;
    return 0;
}