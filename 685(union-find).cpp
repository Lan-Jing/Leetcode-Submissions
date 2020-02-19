#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    Harder to think of a union-find solution.
    Also attempt to find a node with indegree 2.
    1. node i found and two edges a and b recorded. Starting from 0, connect the graph as b ignored.
       1) if connection complete without problem, b is actually the answer(with larger index).
       2) if a directed loop is found(two nodes connected twice), a should be the answer.
       By ignoring edge b, we may prevent double connection or a loop. In both cases, b would be redundant.
    2. i not found, now we are sure that a loop will appear. Also connect the graph from 0 to m-1, 
       the process will definitely stop at the first redundant edge, which is the answer we need.

    Clever arrangement of information recorded and order of connection is the key to easily solve the problem.
*/

class Solution {
public:
    int find(vector<int> &uni, int x) { return uni[x] == x ? x : find(uni,uni[x]); }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n;
        for(int i = 0;i < edges.size();i++)
            n = max(n,max(edges[i][0],edges[i][1]));
        vector<int> uni(n+1);
        for(int i = 1;i <= n;i++) uni[i] = i;
        vector<int> ans, edge1, edge2;
        vector<int> indegree(n+1);
        int index = 0;
        for(int i = 0;i < edges.size();i++){
            indegree[edges[i][1]]++;
            if(indegree[edges[i][1]] == 2)
                index = edges[i][1];
        }
        for(int i = 0;i < edges.size();i++)
            if(edges[i][1] == index){
                if(!edge1.size()) edge1 = edges[i];
                else edge2 = edges[i];
            }
        ans = edge2;
        for(int i = 0;i < edges.size();i++){
            if(edges[i] == edge2) continue;
            int a = edges[i][0], b = edges[i][1],
                fa = find(uni,a), fb = find(uni,b);
            if(fa == fb){
                if(!index){
                    ans = edges[i]; break;
                }else{
                    ans = edge1; break;
                }
            }
            uni[fb] = fa;
        }
        return ans;
    }
};

int main() {

}