#include <corecrt_math.h>
#include <functional>
#include <iostream>
#include <utility>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

/*
    n = 40 indicates a search problem. But the size is too large for a few seconds. In such case consider a bidirectional search:
    split the problem into two equal parts, search them seperately and try to combine the results(meet in the middle).

    In this problem, we split the numbers into halves. Use O(2^(N/2)) time to search all possible sums. Then for each sum from 
    the left, we can find the other half to make abs(goal-sum) minimal. This can be done using binary search, which is hard to correctly implement.
    Or we can just use two pointers, since the sum from left is increasing, there's no need to consider an increasing sum from the right side.

    The time complexity should be O(N * 2^(N/2))
*/

class Solution {
public:
    void dfs(set<int>& Set, vector<int>& nums, int now, int end, int sum) {
        if(now >= end) {
            Set.insert(sum);
            return ;
        }
        dfs(Set, nums, now+1, end, sum);
        dfs(Set, nums, now+1, end, sum+nums[now]);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), n1 = n/2, n2 = n-n1;
        set<int> left, right;
        vector<int> sortedRight, sortedLeft;

        dfs(left, nums, 0, n1, 0);
        dfs(right, nums, n1, n, 0);

        for(set<int>::iterator iter = right.begin();iter != right.end();iter++) {
            sortedRight.push_back(*iter);
        }
        sort(sortedRight.begin(), sortedRight.end());

        int Min = 0x3f3f3f3f, j = sortedRight.size()-1;
        for(set<int>::iterator iter = left.begin();iter != left.end();iter++) {
            int leftsum = *iter;
            while(j >= 0 && leftsum+sortedRight[j] >= goal) j--;
            Min = min(Min, 
                      min(
                          abs(goal-leftsum-sortedRight[max(j,0)]),
                          abs(goal-leftsum-sortedRight[min(j+1, (int)sortedRight.size()-1)])
                      ));
        }

        return Min;
    }
};