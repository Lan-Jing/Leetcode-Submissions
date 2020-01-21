#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

class Solution {
public:
    int canJump(vector<int> &nums) {
        vector<int> newNums,valid, dp;
        valid.resize(nums.size());
        for(int i = 0;i < nums.size();i++) valid[i] = 1;
        int last = 0;
        for(int i = 1;i < nums.size() - 1;i++)
            if(i+nums[i] <= last+nums[last]) valid[i] = 0;
            else last = i;
        
        for(int i = 0;i < nums.size();i++){
            if(!valid[i]) continue;
            int range = nums[i];
            for(int j = 1;j <= range && i+j < nums.size();j++)
                if(!valid[i+j]) nums[i]--;
            newNums.push_back(nums[i]);
        }
//        for(int i = 0;i < newNums.size();i++) cout<<newNums[i]<<' '; cout<<endl;
    
        dp.resize(newNums.size()); 
        for(int i = 0;i < newNums.size();i++) dp[i] = 0x3f3f3f3f;
        dp[0] = 0;
        for(int i = 0;i < newNums.size();i++){
            if(dp[i] == 0x3f3f3f3f || !newNums[i]) continue;
            if(i + newNums[i] >= newNums.size() - 1){
                dp[newNums.size()-1] = min(dp[newNums.size()-1],dp[i]+1);
                continue;
            }
            for(int j = 1;j <= newNums[i];j++){
                if(i+j >= newNums.size()) break;
                dp[i+j] = min(dp[i+j],dp[i]+1);
            }
        }
        if(dp[newNums.size()-1] == 0x3f3f3f3f) return false;
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> input = {2,3,1,1,4};
    cout<<sol.canJump(input)<<endl;
    return 0;
}