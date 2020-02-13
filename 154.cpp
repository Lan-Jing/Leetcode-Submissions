#include <iostream>
using namespace std;
#include <vector>

/*
    With duplicates the worst time complexity should probably O(n).
    Use two pointers to determine the search range by removing duplicates on the left and right ends of the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() < nums.back()) return nums.front();
        int n = nums.size(), l = 0, r = n-1;
        while(l < n-1 && nums[l+1] == nums[l]) l++;
        if(l == n-1) return nums.back();
        while(r && nums[r-1] == nums[r]) r--;
        int ll = l + 1, rr = nums[l] > nums[r] ? n-1 : r;
        while(ll < rr){
            int mid = (ll + rr) / 2;
            if(nums[mid] > nums[l]) ll = mid + 1;
            else rr = mid;
        }
        return nums[ll];
    }
};

int main() {
    Solution sol;
    vector<int> input = {6,6,7,8,1,5,5};
    cout<<sol.findMin(input)<<endl;
    return 0;
}