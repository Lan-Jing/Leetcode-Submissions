#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int gox[4]={0,0,-1,1}, goy[4]={1,-1,0,0};
    void dfs(vector<vector<int> >& vis, vector<vector<char> >& grid, int &m, int &n, int y, int x) {
        vis[y][x] = 1;
        for(int i = 0;i < 4;i++) {
            int ny = y + goy[i], nx = x + gox[i];
            if(ny < 0 || nx < 0 || ny >= m || nx >= n || grid[ny][nx] == '0' || vis[ny][nx]) continue;
            dfs(vis, grid, m, n, ny, nx);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size(), count = 0;
        vector<vector<int> > vis(m);
        for(int i = 0;i < m;i++) vis[i].resize(n);
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(vis, grid, m, n, i, j);
                }
        return count;
    }
};

int main() {

}