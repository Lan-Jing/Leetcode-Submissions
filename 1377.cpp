#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    void dfs(double &ans, double pro, int now, int before, int ti, vector<vector<int> > &next, int &t, int &target) {
        cout<<now<<' '<<pro<<' '<<ti<<endl;
        if(ans) return ;
        if(target == now) {
            if(next[now].size() > (now == 1 ? 0 : 1)) {
                if(ti == t) ans = pro;
                else ans = 0;                
            } else {
                if(ti <= t) ans = pro;
                else ans = 0; 
            }
            return ;
        }
        for(int i = 0;i < next[now].size();i++)
            if(before != next[now][i])
                dfs(ans, pro / (next[now].size() - (now != 1)), next[now][i], now, ti + 1, next, t, target);
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int> > next(n+1);
        for(int i = 0;i < n-1;i++)
            next[edges[i][0]].push_back(edges[i][1]),
            next[edges[i][1]].push_back(edges[i][0]);
        double ans = 0;
        if(n == 1) return 1;
        dfs(ans, 1, 1, -1, 0, next, t, target);
        return ans;
    }
};
/*
8
[[2,1],[3,2],[4,1],[5,1],[6,4],[7,1],[8,7]]
7
7
*/