#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <queue>

class Solution {
public:
    map<pair<int, int>, int> Map;
    struct queNode {
        int now, vis, step;
        queNode(int _now, int _vis, int _step) : now(_now), vis(_vis), step(_step) {}
    };
    void bfs(vector<vector<int> >& graph, int begin, int &ans) {
        int n = graph.size();
        queue<queNode> que; que.push(queNode(begin, (1 << begin), 0));
        while(!que.empty()) {
            queNode nowNode = que.front(); que.pop();
            pair<int, int> nowStatus = make_pair(nowNode.now, nowNode.vis);
            if(Map.count(nowStatus) && Map[nowStatus] <= nowNode.step)
                continue;
            else Map[nowStatus] = nowNode.step;
            cout<<nowNode.now<<' '<<nowNode.vis<<' '<<nowNode.step<<endl;
            if(nowStatus.second == (1 << n)-1) {
                ans = min(ans, nowNode.step);
                return ;
            }
            for(int i = 0;i < graph[nowNode.now].size();i++) {
                int next = graph[nowNode.now][i];
                que.push(queNode(next, (nowNode.vis | (1<<next)), nowNode.step+1));
            }
        }
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), ans = INT32_MAX;
        for(int i = 0;i < n;i++) 
            bfs(graph, i, ans);
        return ans;
    }
};