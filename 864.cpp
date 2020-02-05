#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    struct node{
        int y, x, step;
        vector<int> key;
        node(int _y, int _x, int _s) : y(_y), x(_x), step(_s) {
            key.resize(6); 
        }
        node(int _y, int _x, int _s, vector<int> _key) : y(_y), x(_x), step(_s) { 
            key = _key; 
        }
    };
    int gox[4]={0,-1,0,1}, goy[4]={1,0,-1,0};
    set<vector<int> > vis[30][30];
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), k = 0;
        queue<node> que;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '@')
                    que.push(node(i,j,0));
                if('a' <= grid[i][j] && grid[i][j] <= 'f') k++;
            }
        int ans = -1;
        while(!que.empty()){
            node now = que.front(); que.pop();
            if('a' <= grid[now.y][now.x] && grid[now.y][now.x] <= 'f')
                now.key[grid[now.y][now.x]-'a'] = 1;
            if(vis[now.y][now.x].count(now.key)) continue;
            vis[now.y][now.x].insert(now.key);
        //    cout<<now.y<<','<<now.x<<':';
        //    for(int i = 0;i < k;i++) cout<<now.key[i]<<' '; cout<<endl;

            int cnt = 0;
            for(int i = 0;i < now.key.size();i++) cnt += now.key[i];
            if(cnt == k){
                ans = now.step; break;
            }

            for(int i = 0;i < 4;i++){
                int x = now.x + gox[i], y = now.y + goy[i];
                if(x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '#') continue;
                if('A' <= grid[y][x] && grid[y][x] <= 'Z' && !now.key[grid[y][x]-'A']) continue;
                que.push(node(y,x,now.step+1,now.key));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> input;
    string tmp = "@.a.#"; input.push_back(tmp);
    tmp = "###.#"; input.push_back(tmp);
    tmp = "b.A.B"; input.push_back(tmp);
    cout<<sol.shortestPathAllKeys(input)<<endl;
}