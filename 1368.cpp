#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

class Solution {
public:
    int vis[101][101];
    int gox[5]={0,1,-1,0,0}, goy[5]={0,0,0,1,-1};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(vis,0x3f,sizeof(vis));
        vis[0][0] = 0;
        queue<pair<int,int> > que;
        que.push(make_pair(0,0));
        while(!que.empty()) {
            pair<int,int> now = que.front(); que.pop();
            int y = now.first, x = now.second;
            for(int path = 1;path < 5;path++) {
                int ny = y + goy[path], nx = x + gox[path];
                if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
                if(vis[ny][nx] <= vis[y][x] + (path != grid[y][x])) continue;
                vis[ny][nx] = vis[y][x] + (path != grid[y][x]);   
                que.push(make_pair(ny,nx));
            }
        }
        return vis[m-1][n-1];
    }
};

int main() {

}