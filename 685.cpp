#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <utility>

/*
    hard to find a union-find solution at the first time.
    However dfs one may be more straight-forward.
    Consider indegree for every node.
    1. There're some node i that indegree[i] == 2. Then we already find two edge candidates, say, a and b.
        1) dfs from node i. If we meet a[1] or b[1], we find a directed loop. Only one of two candidates can be removed.
        2) Otherwise, both a and b are valid. Pick one with larger index.
    2. indegree for every node <= 1. the backward edge is surely connected to the root. The additional edge form a loop
       around the root with every edge in that loop being possible answer. The circle can be easily found with good property,
       as starting from an artbitrary node, climb up the reverse tree will have all edges in the loop visited once. 
       Also pick up one with largest index.
*/

class Solution {
public:
    void dfs_1(vector<int> &ans, vector<vector<int> > &neighbors, int now, vector<vector<int> > &targetEdges) {
        if(now == targetEdges[0][0] || now == targetEdges[1][0]){
            ans = now == targetEdges[0][0] ? targetEdges[0] : targetEdges[1];
            return ;
        }
        for(int i = 0;i < neighbors[now].size();i++)
            dfs_1(ans,neighbors,neighbors[now][i],targetEdges);
    }
    void dfs_2(vector<int> &ans, vector<vector<int> > &neighbors, vector<int> &vis, int now, vector<int> &path, map<pair<int,int>,int> &edgeIndex) {
        if(vis[now]){
            int maxIndex = 0;
            for(int i = path.size()-1;i > 0;i--){
            // go back to grab edges in the loop.
                if(edgeIndex[make_pair(path[i],path[i-1])] > maxIndex){
                    ans.resize(2);
                    ans[0] = path[i], ans[1] = path[i-1];
                }
                if(path[i-1] == now) break;
            }
            return ;
        }else vis[now] = 1;
        for(int i = 0;i < neighbors[now].size();i++){
            path.push_back(neighbors[now][i]);
            dfs_2(ans,neighbors,vis,neighbors[now][i],path,edgeIndex);
            path.pop_back();
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(int i = 0;i < edges.size();i++)
            n = max(n,max(edges[i][0],edges[i][1]));
        vector<int> indegree(n+1);
        map<pair<int,int>,int> edgeIndex;
        for(int i = 0;i < edges.size();i++)
            indegree[edges[i][1]]++,
            edgeIndex[make_pair(edges[i][0],edges[i][1])] = i;
        int index = 0;
        for(int i = 1;i <= n;i++)
            if(indegree[i] == 2){
                index = i;
                break;
            }
        vector<int> ans;
        vector<vector<int> > neighbors(n+1);
        cout<<index<<endl;
        if(index){
            vector<vector<int> > targetEdges;
            for(int i = 0;i < edges.size();i++){
                neighbors[edges[i][0]].push_back(edges[i][1]);
                if(edges[i][1] == index)
                    targetEdges.push_back(edges[i]);
            }
            dfs_1(ans,neighbors,index,targetEdges);
            if(!ans.size()) ans = edgeIndex[make_pair(targetEdges[0][0],targetEdges[0][1])] < 
                                  edgeIndex[make_pair(targetEdges[1][0],targetEdges[1][1])] ? targetEdges[1] : targetEdges[0];
        }else{
            vector<int> path;
            vector<int> vis(n+1,0);
            for(int i = 0;i < edges.size();i++)
                neighbors[edges[i][1]].push_back(edges[i][0]);
            // climb up the reverse tree and find the loop.
            path.push_back(1);
            dfs_2(ans,neighbors,vis,1,path,edgeIndex);
        }
        return ans;
    }
};

int main() {

}