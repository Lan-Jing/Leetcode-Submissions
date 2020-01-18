#include <iostream>
using namespace std;
#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <map>

/*
    build up the graph and traverse the whole graph.
*/

class Solution {
public:
    int vis[1010];
    double g[1010][1010];
    void dfsBuild(int NNode, int root, int now, double value) {
        if(vis[now]) return ;
        vis[now] = 1;
        g[root][now] = value;
        for(int i = 0;i < NNode;i++){
            if(g[now][i] == 0 || vis[i]) continue;
            dfsBuild(NNode, root, i, value * g[now][i]);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        map<string,int> index; int NNode = 0;
        for(int i = 0;i < equations.size();i++){
            string a = equations[i][0], b = equations[i][1];
            if(index.count(a) == 0) index.insert(make_pair(a,NNode++));
            if(index.count(b) == 0) index.insert(make_pair(b,NNode++));
        }
        memset(g,0,sizeof(g));
        for(int i = 0;i < equations.size();i++){
            string a = equations[i][0], b = equations[i][1];
            int aa = index[a], bb = index[b];
            g[aa][bb] = values[i];  g[bb][aa] = 1 / values[i];
        }
        for(int i = 0;i < NNode;i++){
            memset(vis,0,sizeof(vis));
            dfsBuild(NNode, i, i, 1.0);
        }
        vector<double> ans;
        for(int i = 0;i < queries.size();i++){
            string a = queries[i][0], b = queries[i][1];
            if(!index.count(a) || !index.count(b)){
                ans.push_back(-1.0); continue;
            }
            if(g[index[a]][index[b]]) ans.push_back(g[index[a]][index[b]]);
            else ans.push_back(-1.0);
        }
        return ans;
    }
};

int main() {

}