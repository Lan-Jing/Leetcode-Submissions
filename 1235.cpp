#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    struct job {
        int st, et, profit;
        job(int _st, int _et, int _profit) : st(_st), et(_et), profit(_profit) {}
        bool operator < (const job &other) const {
            if(et != other.et) return et < other.et;
            else return st < other.st;
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<job> jlist;
        vector<int> dp(n);
        for(int i = 0;i < n;i++)
            jlist.push_back(job(startTime[i],endTime[i],profit[i]));
        sort(jlist.begin(),jlist.end());
        for(int i = 0;i < n;i++){
            int l = 0, r = i;
            while(l < r){
                int mid = (l + r)/2;
                if(jlist[mid].et <= jlist[i].st) l = mid + 1;
                else r = mid;
            }
        //    cout<<l<<endl;
            dp[i] = max(i ? dp[i-1] : 0,(l ? dp[l-1] : 0)+jlist[i].profit);
        }
    //    for(int i = 0;i < n;i++) cout<<dp[i]<<' '; cout<<endl;
        int ans = 0;
        for(int i = 0;i < n;i++) ans = max(ans,dp[i]);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> startTime = {4,2,4,8,2};
    vector<int> endTime = {5,5,5,10,8};
    vector<int> profit = {1,2,8,10,4};
    cout<<sol.jobScheduling(startTime,endTime,profit)<<endl;
    return 0;
}