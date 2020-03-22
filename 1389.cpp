#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = index.size();
        vector<int> vec(n);

        for(int i = 0;i < n;i++) {
            for(int j = i;j > index[i];j--) vec[j] = vec[j-1]; 
            vec[index[i]] = nums[i];
        }
        return vec;
    }
};