#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <queue>

/*
    this is a TLE solution for Problem 407.
    The trivial thought was to fill up the holes from bottom to top.
    Maintain a heap for picking up location for filling. The minimum height 
    goes up 1 at a time (which makes it unefficient).
*/

class Solution {
public:
    struct node {
        int y, x, height;
        node(int y,int x,int h) : y(y), x(x), height(h) {}
        bool operator < (const node &other) const {
            return this->height > other.height;
        }
        bool operator == (const node &other) const {
            return this->x == other.x && this->y == other.y;
        }
    };
    priority_queue<node> que;
    bool valid[115][115];
    bool vis[115][115];
    int gox[4]={0,0,1,-1}, goy[4]={1,-1,0,0};
    int change(vector<vector<int> > &heightMap, node now, int mode) {
        if(now.y == 0 || now.x == 0 || now.y == heightMap.size()-1 || now.x == heightMap[0].size()-1) return 0;
        vis[now.y][now.x] = 1;
        if(!mode) valid[now.y][now.x] = 0;
        else heightMap[now.y][now.x] = now.height + 1, que.push(node(now.y,now.x,heightMap[now.y][now.x]));
        int res = 0;
        for(int i = 0;i < 4;i++){
            int nx = now.x + gox[i], ny = now.y + goy[i];
            if(nx < 0 || ny < 0 || nx >= heightMap[0].size() || ny >= heightMap.size() ||
               vis[ny][nx] || heightMap[ny][nx] > now.height) 
                continue;
            if(mode) res += change(heightMap,node(ny,nx,heightMap[ny][nx]),mode);
        }
        return mode ? res + 1 : 0;
    }
    int dfsFlow(vector<vector<int> > &heightMap, node now, node start) {
        if(now.y == 0 || now.x == 0 || now.y == heightMap.size()-1 || now.x == heightMap[0].size()-1) return 0;
        vis[now.y][now.x] = 1;
        int res = 1;
        for(int i = 0;i < 4;i++){
            int nx = now.x + gox[i], ny = now.y + goy[i];
            if(nx < 0 || ny < 0 || nx >= heightMap[0].size() || ny >= heightMap.size() ||
               vis[ny][nx] || heightMap[ny][nx] > now.height) 
                continue;
            res &= dfsFlow(heightMap,node(ny,nx,heightMap[ny][nx]),start);
        }
        if(now == start){
            memset(vis,0,sizeof(vis)); return change(heightMap,now,res);
        }else return res;
    }
    int trapRainWater(vector<vector<int> > &heightMap) {
        if(!heightMap.size()) return 0;
        while(!que.empty()) que.pop();
        int m = heightMap.size(), n = heightMap[0].size();
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                valid[i][j] = 1, que.push(node(i,j,heightMap[i][j]));
        int ans = 0;
        while(!que.empty()){
            node now = que.top(); que.pop();
            if(!valid[now.y][now.x] || heightMap[now.y][now.x] != now.height) continue;
            memset(vis,0,sizeof(vis));
            int res = dfsFlow(heightMap,now,now);
            if(res) ans += res; 
        }
        return ans;
    }
};

int main() {

}