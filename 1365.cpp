#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(110);
        vector<int> ans;
        int n = nums.size();
        if(!n) return ans;
        for(int i = 0;i < n;i++)
            cnt[nums[i]]++;
        for(int i = 1;i < cnt.size();i++) 
            cnt[i] += cnt[i-1];
        for(int i = 0;i < n;i++) 
            ans.push_back(nums[i] ? cnt[nums[i]-1] : 0);
        return ans;
    }
};

int main() {

}