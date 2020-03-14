#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    void dfs(int &ans, int now, int nowTime, vector<vector<int> > &next, vector<int> &informTime) {
        ans = max(ans,nowTime);
        for(int i = 0;i < next[now].size();i++)
            dfs(ans, next[now][i], nowTime + informTime[next[now][i]], next, informTime);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> maxTime;
        vector<vector<int> > next(n);
        for(int i = 0;i < n;i++)
            if(manager[i] != -1)
                next[manager[i]].push_back(i);
        int ans = 0;
        dfs(ans, headID, informTime[headID], next, informTime);
        return ans;
    }
};