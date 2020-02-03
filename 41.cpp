#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

/*
    In-place barral-sort-style arrangement for constant extra place.
    First, if we have n numbers, answer should be in [1,n+1] range.
    Second, all non-positive numbers make no difference on the answer.
    What we do is trying to place positive numbers into barral positions num[i]-1.
    scanning the whole array, when we meet a positve number num[i] in range [1,n](ignore if too large or small),
    try to place it in position num[i]-1. Swap and get a new one from num[num[i]-1], repeat until numbers are in place.
    After the scan all positive numbers in range [1,n] should be in place, with other numbers placed in missing positions.
    Finally the leftmost position without its corresponding number in it will be the missing one.
*/

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0;i < n;i++)
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[i],nums[nums[i]-1]);
        for(int i = 0;i < n;i++)
            if(i != nums[i]-1){
                ans = i+1;
                break;
            }
        for(int i = 0;i < n;i++) cout<<nums[i]<<' '; cout<<endl;
        if(ans == -1) ans = n+1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {-1};
    cout<<sol.firstMissingPositive(input)<<endl;
    return 0;
}