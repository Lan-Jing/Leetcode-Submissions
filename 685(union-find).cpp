#include <iostream>
using namespace std;
#include <string>
#include <vector>

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