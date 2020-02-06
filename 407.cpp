#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>
#include <cstring>

/*
    This is actually an extension of the 1-D rain trapping problem. 
    Reccll the 1-D situation, we can have a two-pointer solution.
    We maintain two pointers pointed to current positions as well as the maximum height visited by these pointers. 
    Each time we pick up one of the two pointed position and compute water capacity of that bar directly.
    Choices are made by comparing heights of the two pointed bar, as we will be safe to fill the shorter one because 
    water won't overflow to the other side (with a higher bar). Capacity is determined through the current maximum height, 
    which should always come from the same side of the current bar (otherwise we should fill bar from the other side).
    Finally the two pointers will meet at one point, finishing the process.

    The 2-D situation is basiclly the same, despite the 4-direction possibility. Instead of two boundary in a line,
    we take the outmost rectangle as initial boundary. The simple comparision is replaced by picking up a boundary bar 
    with minimum height (using a heap). Also water filled is determined by the visited maximum height. Notice that once 
    the bar is filled, change its height and push it into the heap for further comparision. Higher nodes should be directly
    pushed into the heap.
*/

class Solution {
public:
    int gox[4]={-1,1,0,0}, goy[4]={0,0,1,-1};
    struct node{
        int y,x,h;
        node(int _y, int _x, int _h) : y(_y), x(_x), h(_h) {}
        bool operator < (const node &other) const {
            return h > other.h;
        }
    };
    int vis[115][115];
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<node> que;
        int m = heightMap.size(), n = heightMap[0].size();
        for(int i = 0;i < m;i++)
            que.push(node(i,0,heightMap[i][0])),
            que.push(node(i,n-1,heightMap[i][n-1]));
        for(int i = 1;i < n-1;i++)
            que.push(node(0,i,heightMap[0][i])),
            que.push(node(m-1,i,heightMap[m-1][i]));
        int maxH = 0, ans = 0;
        memset(vis,0,sizeof(vis));
        while(!que.empty()){
            node now = que.top(); que.pop();
            maxH = max(maxH,now.h);
            vis[now.y][now.x] = 1;
            for(int i = 0;i < 4;i++){
                int x = now.x + gox[i], y = now.y + goy[i];
                if(x >= n || y >= m || x < 0 || y < 0 || vis[y][x]) continue;
                if(heightMap[y][x] < maxH){
                    ans += maxH-heightMap[y][x];
                    heightMap[y][x] = maxH;
                }
                que.push(node(y,x,heightMap[y][x]));
            }
        }
        return ans;
    }
};

int main() {

}