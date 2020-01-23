#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

class Solution {
public:
    struct node {
        int y,x;
        bool operator == (const node &other) const {
            return this->x == other.x && this->y == other.y;
        }
        node(int _y, int _x) : y(_y), x(_x) {}
    };
    int ans, tot;
    int gox[4]={0,0,-1,1}, goy[4]={1,-1,0,0};
    void dfs(vector<vector<int> > &vis, vector<vector<int> > grid,
             node start, node end, node now, int cnt) {
        if(now == end && cnt == tot){
            ans++; return ;
        }
        for(int i = 0;i < 4;i++){
            int ny = now.y + goy[i], nx = now.x + gox[i];
            if(ny < 0 || nx < 0 || nx >= grid[0].size() || ny >= grid.size() ||
               vis[ny][nx] || grid[ny][nx] == -1) continue;
            vis[ny][nx] = 1;
            dfs(vis,grid,start,end,node(ny,nx),cnt+1);     
            vis[ny][nx] = 0;       
        }
    }
    int uniquePahtsIII(vector<vector<int> > &grid) {
        node start, end;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1) start = node(i,j);
                if(grid[i][j] == 2) end = node(i,j);
                if(grid[i][j] == -1) tot--;
            } 
        tot += m*n;
        cout<<tot<<endl;
        vector<vector<int> > vis; vis.resize(m);
        for(int i = 0;i < m;i++) vis[i].resize(n);
        dfs(vis,grid,start,end,start,1);
        return ans;
    }
};

int main(){

}