#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int x;
        for(x = 0;x < n-1;x++) {
            if(nums[x] > nums[x+1])
                break;
        }
        cout<<x<<endl;
        for(int i = x+1;i < n;i++) {
            if(nums[i] > nums[0])
                return false;
            if(i < n-1 && nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
};