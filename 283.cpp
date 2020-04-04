#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for(int i = 0;i < n;i++) {
            if(nums[i]) nums[l++] = nums[i];
        }
        for(;l < n;l++) nums[l] = 0;
    }
};

int main () {

}