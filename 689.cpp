#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    medium array problem.
    We check the segment in the middle, then the job becomes finding segments from left and right, both with maximum sum, 
    which can be easily handled in O(n) time.
*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> leftKSum, rightKSum;
        vector<int> maxLeft, maxRight, leftInd, rightInd;
        leftKSum.resize(nums.size()), rightKSum.resize(nums.size());
        maxLeft.resize(nums.size()), maxRight.resize(nums.size());
        leftInd.resize(nums.size()), rightInd.resize(nums.size());
        for(int i = k-1;i < nums.size();i++){
            if(i == k-1){
                for(int j = 0;j <= i;j++) leftKSum[i] += nums[j];
                maxLeft[i] = leftKSum[i], leftInd[i] = 0;
            }else leftKSum[i] = leftKSum[i-1] + nums[i] - nums[i-k];
            if(!i) continue;
            if(leftKSum[i] > maxLeft[i-1]){
                maxLeft[i] = leftKSum[i], leftInd[i] = i-(k-1);
            }else maxLeft[i] = maxLeft[i-1], leftInd[i] = leftInd[i-1];
        }
        for(int i = nums.size()-k;i >= 0;i--){
            if(i == nums.size()-k){
                for(int j = i;j < nums.size();j++) rightKSum[i] += nums[j];
                maxRight[i] = rightKSum[i], rightInd[i] = i;
            }else rightKSum[i] = rightKSum[i+1] + nums[i] - nums[i+k];
            if(i == nums.size()-1) continue;
            if(rightKSum[i] >= maxRight[i+1]){
                maxRight[i] = rightKSum[i], rightInd[i] = i;
            }else maxRight[i] = maxRight[i+1], rightInd[i] = rightInd[i+1];
        }
        int ans = 0;
        vector<int> res; res.resize(3);
        for(int i = k;i < nums.size()-k;i++){
            cout<<i<<':'<<maxLeft[i-1]<<' '<<leftKSum[i+k-1]<<' '<<maxRight[i+k]<<endl;
            if(maxLeft[i-1]+leftKSum[i+k-1]+maxRight[i+k] > ans){
                ans = maxLeft[i-1]+leftKSum[i+k-1]+maxRight[i+k];
                res[0] = leftInd[i-1];
                res[1] = i;
                res[2] = rightInd[i+k];
            }
        }
        return res;
    }
};

int main() {
    vector<int> input = {1,2,1,2,6,7,5,1};
    Solution sol;
    vector<int> output;
    output = sol.maxSumOfThreeSubarrays(input,1);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<' '; cout<<endl;
}