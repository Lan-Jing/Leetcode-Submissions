#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include <cstring>

class Solution {
public:
    int from[7]={-1,3,0,3,2,3,0},
        to[7]={-1,1,2,2,1,0,1}, 
        goy[4]={-1,0,1,0},
        gox[4]={0,1,0,-1};
    vector<pair<int,int> > con;
    int flag;
    void dfs(int ny, int nx, int ty, int tx, int from, vector<vector<int> >& grid) {
        if(flag) return ;
        if(ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size()) return ;
        int di1 = con[grid[ny][nx]].first, di2 = con[grid[ny][nx]].second;
        if(ny == ty && nx == tx && (from == di1 || from == di2 || from == -1)) {
            flag = 1; return ;
        }

        if(from == -1 || from == di1 || from == di2) {
            int di;
            if(from == -1) {
                di = ny + goy[di1] >= 0 && nx + gox[di1] >= 0 ? di1 : di2;
            } else {
                di = from == di1 ? di2 : di1;
            }

            int nexty = ny + goy[di], nextx = nx + gox[di];
            dfs(nexty, nextx, ty, tx, (di+2)%4, grid);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0;i <= 6;i++) con.push_back(make_pair(from[i],to[i]));

        flag = 0;
        dfs(0, 0, m-1, n-1, -1, grid);
        cout<<endl;

        return flag;
    }
};