#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <map>

/*
    dfs to find a path that goes through all edges. 
    1. use a map to check if edges have been searched
    2. note that a single node can be visited couple times.
    3. if a solution is found, break all other procedures.
*/

class Solution {
public:
    struct edge{
        string a,b; 
        bool operator < (const edge &other) const {
            if(this->a != other.a) return this->a < other.a;
            else return this->b < other.b;
        }
        edge(string a,string b) : a(a), b(b) {} 
    };
    vector<string> ans;
    int flag;
    void dfs(map<edge,int> &vis, map<string,int> index, vector<vector<string> > neighbors,
             string now, vector<string> &seq, int step, int tot) {
        if(flag) return ;
        int nowIndex = index[now];
        if(step == tot && !flag){
            flag = 1;
            ans = seq; return ;
        }
        for(int i = 0;i < neighbors[nowIndex].size();i++){
            if(vis[edge(now,neighbors[nowIndex][i])] == 0) continue;
            vis[edge(now,neighbors[nowIndex][i])]--;
            seq.push_back(neighbors[nowIndex][i]);
            dfs(vis,index,neighbors,neighbors[nowIndex][i],seq,step+1,tot);
            seq.pop_back();
            vis[edge(now,neighbors[nowIndex][i])]++;
        }
    }
    vector<string> findItinerary(vector<vector<string> > &tickets) {
        vector<vector<string> > neighbors;
        map<string,int> index; int NNode = 0;
        map<edge,int> vis; 
        for(int i = 0;i < tickets.size();i++){
            string a = tickets[i][0], b = tickets[i][1];
            if(index.count(a) == 0) index[a] = NNode++;
            if(index.count(b) == 0) index[b] = NNode++;
            vis[edge(a,b)]++;
        }
        neighbors.resize(NNode);
        for(int i = 0;i < tickets.size();i++){
            string a = tickets[i][0], b = tickets[i][1];
            neighbors[index[a]].push_back(b);
        }
        for(int i = 0;i < NNode;i++) sort(neighbors[i].begin(), neighbors[i].end());
        vector<string> temp; temp.push_back("JFK");
        flag = 0;
        dfs(vis,index,neighbors,"JFK", temp, 1, tickets.size()+1);
        return ans;
    }
};

int main() {

}