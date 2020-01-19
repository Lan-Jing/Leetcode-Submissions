#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>

/*
    BFS. notice that a node can be accessed mutiple times, 
    as recieving time can be smaller following other paths.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int> > &edges, int N, int K) {
        int vis[101];
        int cnt, ans;
        memset(vis,0x3f,sizeof(vis));
        vector<vector<pair<int,int> > > neighbors; neighbors.resize(N+1);
        for(int i = 0;i < edges.size();i++){
            int a = edges[i][0], b = edges[i][1], c = edges[i][2];
            neighbors[a].push_back(make_pair(b,c));
        }
        queue<pair<int,int> > que; que.push(make_pair(K,0));
        ans = cnt = 0;
        while(!que.empty()){
            pair now = que.front(); que.pop();
            if(now.second >= vis[now.first]) continue;
            vis[now.first] = now.second; 
            for(int i = 0;i < neighbors[now.first].size();i++){
                int b = neighbors[now.first][i].first;
                int c = neighbors[now.first][i].second;
                que.push(make_pair(b,c+now.second));
            }
        }
        for(int i = 1;i <= N;i++){
            ans = max(ans,vis[i]);
            if(vis[i] != vis[0]) cnt++;
        }
        if(cnt == N) return ans;
        else return -1;
    }
};

int main() {

}