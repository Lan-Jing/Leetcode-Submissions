#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <algorithm>

/*
    for every number picked up, do 2Sum
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int> > Set;
        vector<vector<int> > ans;
        if(nums.size() < 3) return ans;
        if(nums[0] == 0){
            if(nums[nums.size()-1] == 0){
                vector<int> temp;
                for(int i = 1;i <= 3;i++) temp.push_back(0);
                ans.push_back(temp);
            }
            return ans;
        }

        for(int i = 0;i < nums.size()-2;i++)
            for(int j = i + 1;j < nums.size()-1;j++){
                int target = -(nums[i] + nums[j]);
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    int mid = (l+r)/2;
                    if(nums[mid] < target) l = mid + 1; 
                    else r = mid;
                }
                if(nums[l] == target){
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[l]);
                    Set.insert(ans);
//                    cout<<nums[i]<<','<<nums[j]<<','<<nums[l]<<endl;
                }
            }
        if(Set.empty()) return ans;
        for(set<vector<int> >::iterator iter = Set.begin();iter != Set.end();iter++)
            ans.push_back(*iter);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > ans;
    vector<int> input = {-1,0,0,1,2,-1,-4};
//    vector<int> input = {0};
    ans = sol.threeSum(input);
    return 0;
}