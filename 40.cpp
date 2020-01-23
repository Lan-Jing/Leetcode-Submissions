#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

/*
    harder version of Problem 39: a number can be used multiple and different times. 
    A better manner is to view numbers of same value as a group, then dfs how many numbers are chosen from a group,
    instead of choosing a single one at a time.
*/

class Solution {
public:
    vector<vector<int> > ans;
    void dfsBuild(vector<pair<int,int> > can, vector<pair<int,int> > &res, int now, int sum, int target) {
        if(now >= can.size() && sum != target) return ;
        if(sum == target){
            vector<int> actRes;
            for(int i = 0;i < res.size();i++)
                for(int j = 0;j < res[i].second;j++) actRes.push_back(res[i].first);
            ans.push_back(actRes);
            return;
        }
        for(int i = 0;i <= can[now].second;i++) {
            if(sum + i * can[now].first > target) break;
            res.push_back(make_pair(can[now].first,i));
            dfsBuild(can,res,now+1,sum+i*can[now].first,target);
            res.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        if(!candidates.size()) return ans;
        map<int,int> Map;
        for(int i = 0;i < candidates.size();i++)
            Map[candidates[i]]++;                
        vector<pair<int,int> > newCan;
        vector<pair<int,int> > res;
        for(map<int,int>::iterator iter = Map.begin();iter != Map.end(); iter++)
            if(iter->second)
                newCan.push_back(make_pair(iter->first,iter->second));
        dfsBuild(newCan,res,0,0,target);
        return ans;
    }
};


int main() {
    Solution sol; 
    vector<int> candidates = {2,5,2,1,2};
    vector<vector<int> > ans;
    ans = sol.combinationSum2(candidates,5);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}