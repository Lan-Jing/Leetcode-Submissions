#include <iostream>
using namespace std;
#include <vector>

/*
    find the minimum number in a rotated array.
    If the array is rotated in the middle, use the first element in the array for binary searching.
    Otherwise just return the first element.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        if(nums[l] < nums[r]){
            return nums[l];
        }else{
            while(l < r){
                int mid = (l+r)/2;
                if(nums[mid] >= nums[0]) l = mid + 1;
                else r = mid;
            }
        }
        return nums[l];
    }
};

int main() {
    Solution sol;
    vector<int> input = {4,5,6,7,0,1,2};
    cout<<sol.findMin(input)<<endl;
}