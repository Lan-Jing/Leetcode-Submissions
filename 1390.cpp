#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int cnt = 0, tmp = 0;
            for(int j = 1;j*j <= nums[i];j++) {
                if(nums[i] % j) continue;
                if(nums[i] / j != j) cnt += 2, tmp += nums[i] / j + j;
                else cnt += 1, tmp += j;
            }
            if(cnt == 4) ans += tmp;
        }
        return ans;
    }
};