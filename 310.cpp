#include <iostream>
using namespace std;
#include <vector>
#include <queue>

/*
    find the root that makes a tree with minimum height.
    toposort method:
        implement a toposort on the undirected tree, like peeling an onion.
        In order to determine the double-answer situation, we can record 
        layer indecies for comparing the last two nodes.
    dfs method:
        think of the problem in another way, it wasn't hard to consider the problem 
        as finding the longest path in the tree and its center. A dfs from any point can 
        determine one end of the longest path by picking up the farthest node in the search. 
        Then do dfs again from this point to get the wanted path. Record the path and find the center(s).
*/

class Solution {
public:
    struct layerNode {
        int layer, val;
        layerNode(int _l, int _v) : val(_v), layer(_l) {}
    };
    vector<int> findMinHeightTrees(int n, vector<vector<int> > &edges) {
        queue<layerNode> que;
        vector<vector<int> > neighbors; neighbors.resize(n);
        vector<int> Degree; Degree.resize(n);
        vector<int> ans;
        if(n == 1){
            ans.push_back(0); return ans;
        }
        int cnt = 0;
        for(int i = 0;i < edges.size();i++){
            int a = edges[i][0], b = edges[i][1];
            Degree[a]++, Degree[b]++;
            neighbors[a].push_back(b), neighbors[b].push_back(a);
        }
        for(int i = 0;i < n;i++) if(Degree[i] == 1) que.push(layerNode(1,i));
        while(!que.empty()){
            if(n-cnt == 2){
                layerNode res1 = que.front(); que.pop();
                layerNode res2 = que.front(); que.pop();
                if(res1.layer == res2.layer){
                    ans.push_back(res1.val), ans.push_back(res2.val);
                }else ans.push_back(res2.val);
                return ans;
            }
            layerNode now = que.front(); que.pop(); cnt++;
            for(int i = 0;i < neighbors[now.val].size();i++){
                Degree[neighbors[now.val][i]]--;
                if(Degree[neighbors[now.val][i]] == 1) 
                    que.push(layerNode(now.layer+1,neighbors[now.val][i]));
            }
        }
        return ans;
    }
};

int main() {

}