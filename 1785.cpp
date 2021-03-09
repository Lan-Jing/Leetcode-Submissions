#include <corecrt_math.h>
#include <iostream>
using namespace std;
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sumOfNums = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            sumOfNums += nums[i];
        }
        return abs(goal-sumOfNums)/limit + (abs(goal-sumOfNums) % limit > 0);
    }
};