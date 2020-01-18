#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

/*
    a small modification of 3Sum will do fine
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int minError = 0x3f3f3f3f;
        for(int i = 0;i < nums.size()-2;i++){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(target - sum) < minError){
                    minError = abs(target - sum);
                    ans = sum;
                }
                if(sum > target) r--;
                else l++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {-1,2,1,-4};
    cout<<sol.threeSumClosest(input,-2)<<endl;
    return 0;
}