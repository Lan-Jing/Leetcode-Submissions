#include <functional>
#include <iostream>
#include <utility>
using namespace std;
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    const int modulo = 1e9+7;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        auto compare = [](pair<int, int> a, pair<int, int> b) { return a > b; };
        
        vector<int> minDis(n+1, 0x3f3f3f3f);
        vector<int> visited(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> que(compare);

        que.push(make_pair(0, n));
        minDis[n] = 0;

        vector<vector<pair<int, int> > > g(n+1);
        for(int i = 0;i < edges.size();i++) {
            g[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            g[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        
        while(!que.empty()) {
            pair<int, int> now = que.top(); que.pop();
            int nowNode = now.second, 
                dis = now.first;

            if(visited[nowNode]) {
                continue;
            } else {
                visited[nowNode] = 1;
            }

            for(int i = 0;i < g[nowNode].size();i++) {
                int nextNode = g[nowNode][i].first,
                    nextDis = g[nowNode][i].second;
                if(dis + nextDis < minDis[nextNode]) {
                    minDis[nextNode] = dis + nextDis;
                    que.push(make_pair(minDis[nextNode], nextNode));
                }
            }
        }
        
        vector<int> dp(n+1, 0); dp[n] = 1;
        que.push(make_pair(0, n));
        for(int i = 0;i <= n;i++) visited[i] = 0;
        while(!que.empty()) {
            pair<int, int> now = que.top(); que.pop();
            int nowNode = now.second, 
                dis = now.first;
            
            if(visited[nowNode]) {
                continue;
            } else {
                visited[nowNode] = 1;
            }

            for(int i = 0;i < g[nowNode].size();i++) {
                int nextNode = g[nowNode][i].first;
                if(minDis[nextNode] > minDis[nowNode]) {
                    dp[nextNode] = (dp[nextNode]+dp[nowNode]) % modulo;
                    que.push(make_pair(minDis[nextNode], nextNode));
                }
            }
        }

        return dp[1];
    }
};