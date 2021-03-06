#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <utility>
#include <vector>

/*
    this is an O(n^2) solution with improvement.
    Considering all positions, nodes with smaller range than those from left is useless.
    We can remove these nodes and adjust the rest in O(n), making it possible to pass the last case.

    Greedy algorithm will be better. To further consider the improvement above, we can actually perform it
    in every jump. Each node corresponds to a jump range, from which the node with largest range is chosen.
    This decision will always ensure a maximum flexibility and no possible path will be omitted.
*/

class Solution {
public:
    int jump(vector<int> &nums) {
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
        return dp[newNums.size()-1];
    }
};

int main() {
    Solution sol;
    vector<int> input = {2,2,4,1,1,4};
    cout<<sol.jump(input)<<endl;
    return 0;
}
