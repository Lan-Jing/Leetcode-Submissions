#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    dfs construction
*/

class Solution {
public:
    vector<vector<int> > ans;
    void dfsBuild(vector<int> candidates, vector<int> &res, int last, int sum, int target) {
        if(sum == target){
            ans.push_back(res);
            return ;
        }
        for(int i = last;i < candidates.size();i++){
            if(candidates[i] + sum > target) continue;
            res.push_back(candidates[i]);
            dfsBuild(candidates,res,i,sum+candidates[i],target);
            res.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> res;
        dfsBuild(candidates,res,0,0,target);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<vector<int> > ans = sol.combinationSum(candidates,8);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}