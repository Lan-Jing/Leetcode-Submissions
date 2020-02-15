#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    radix sort, not bad!
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        vector<int> radix(10);
        radix[0] = 1;
        for(int i = 1;i < radix.size();i++) radix[i] = radix[i-1] * 10;
        int n = nums.size();
        if(n < 2) return 0;
        for(int i = 0;i < 10;i++){
            vector<vector<int> > radixList(10);
            for(int j = 0;j < n;j++){
                int target = (nums[j] / radix[i]) % 10;
                radixList[target].push_back(nums[j]);
            }
            int index = 0;
            for(int j = 0;j < 10;j++)
                for(int k = 0;k < radixList[j].size();k++)
                    nums[index++] = radixList[j][k];
        }
        int ans = 0;
        for(int i = 1;i < n;i++) 
            ans = max(ans,nums[i]-nums[i-1]);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {1,1,1,1};
    cout<<sol.maximumGap(input)<<endl;
    return 0;
}
