#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
    next permutation algorithm:
    the main goal is to maintain the partial permutation that is ascending.
    1. from right to left, find the first non-ascending pair (i-1,i)
    2. find the first number from right that larger than num[i-1], says j, then swap(i-1,j)
    3. reverse num[i,size()]
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1;i >= 1;i--){
            if(nums[i-1] >= nums[i]) continue;
            int j;
            for(j = nums.size()-1;j >= i && nums[j] <= nums[i-1];j--);
            swap(nums[i-1],nums[j]);
            reverse(nums.begin()+i,nums.end());
            return ;
        }
        reverse(nums.begin(),nums.end());
        return ;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,5,1};
    for(int i = 0;i < 6;i++){
        sol.nextPermutation(vec);
        for(int i = 0;i < vec.size();i++) cout<<vec[i]<<' '; cout<<endl;
    }
    return 0;
}