#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>
#include <cstring>

class Solution {
public:
    int vis[40][40], viss[40][40];
    int gox[4]={0,0,-1,1}, goy[4]={1,-1,0,0};
    struct queNode {
        int y, x, step, k;
        queNode(int _y, int _x, int _s, int _k) : y(_y), x(_x), step(_s), k(_k) {}
        queNode() {}
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<queNode> que; que.push(queNode(0,0,0,k));
        memset(vis,-1,sizeof(vis));
        memset(viss,0x3f,sizeof(viss));
        int ans = 0x3f3f3f3f;
        while(!que.empty()){
            queNode now = que.front(); que.pop();
            if(now.k <= vis[now.y][now.x] && now.step >= viss[now.y][now.x]) continue;
            else vis[now.y][now.x] = now.k, viss[now.y][now.x] = now.step;
        //    cout<<now.y<<','<<now.x<<':'<<now.step<<' '<<now.k<<endl;
            if(now.y == m-1 && now.x == n-1){
                ans = min(ans,now.step); 
            }
            for(int i = 0;i < 4;i++){
                int x = now.x + gox[i], y = now.y + goy[i];
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(grid[y][x] == 0){
                    que.push(queNode(y,x,now.step+1,now.k));
                }else if(now.k){
                    que.push(queNode(y,x,now.step+1,now.k-1));
                }
            }
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input;
    vector<int> tmp;
    tmp = {0,1,0,0,0,1,0,0}; input.push_back(tmp);
    tmp = {0,1,0,1,0,1,0,1}; input.push_back(tmp);
    tmp = {0,0,0,1,0,0,1,0}; input.push_back(tmp);
    cout<<sol.shortestPath(input,1)<<endl;
    return 0;
}