#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    upper_bound and lower_bound realization.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        vector<int> ans; 
        if(!nums.size()) return ans = {-1,-1};
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        ans.push_back(l < nums.size() && nums[l] == target ? l : -1);
        l = 0, r = nums.size();
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        ans.push_back(l && nums[l-1] == target ? l-1 : -1);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {2,2,3,5,7,7,8,8,8};
    vector<int> output = sol.searchRange(input,2);
    cout<<output[0]<<','<<output[1]<<endl;
    output = sol.searchRange(input,6);
    cout<<output[0]<<','<<output[1]<<endl;
    input = {};
    output = sol.searchRange(input,4);
    cout<<output[0]<<','<<output[1]<<endl;
    return 0;
}