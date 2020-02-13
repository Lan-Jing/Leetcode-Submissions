#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/*
    medium dfs problem.
    First we need to check the existence of answers, which can be done by shortest-path algorithms quickly.
    Then the construction of answers can be done easily by dfs.
*/

class Solution {
public:
    void dfsBuild(vector<string> &ans, vector<int> &list, vector<string> &wordDict, vector<vector<int> > &antecedent, int now) {
        if(!now){
            string tmp;
            for(int i = list.size()-1;i >= 0;i--){
                if(i < list.size()-1) tmp += " ";
                tmp += wordDict[list[i]];
            }
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0;i < antecedent[now].size();i++){
            list.push_back(antecedent[now][i]);
            dfsBuild(ans,list,wordDict,antecedent,now-wordDict[antecedent[now][i]].length());
            list.pop_back();
        }
    }
    int flag = 0;
    struct queNode{
        int dis, ind;
        bool operator < (const queNode &other) const {
            return dis > other.dis;
        }
        queNode(int _d, int _i) : dis(_d), ind(_i) {}
    };
    void dijkstra(vector<string> &wordDict, vector<vector<int> > &trans, vector<int> &dis, vector<int> &vis, int end) {
        priority_queue<queNode> que; que.push(queNode(0,0));
        dis[0] = 0;
        while(!que.empty()){
            queNode now = que.top(); que.pop();
            if(vis[now.ind]) continue; else vis[now.ind] = 1;
            for(int i = 0;i < trans[now.ind].size();i++){
                int next = now.ind+wordDict[trans[now.ind][i]].length(); 
                dis[next] = min(dis[next],now.dis+1);
                que.push(queNode(dis[next],next)); 
            }
        }
        if(dis[end] < 0x3f3f3f3f) flag = 1;
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l = s.length(), n = wordDict.size();
        vector<vector<int> > trans(l+1), antecedent(l+1);
        for(int i = 0;i < l;i++)
            for(int j = 0;j < n;j++){
                int lj = wordDict[j].length();
                if(i + lj-1 >= l) continue;
                if(s.substr(i,lj) == wordDict[j]) 
                    trans[i].push_back(j);
            }
        for(int i = 0;i < l;i++)
            for(int j = 0;j < trans[i].size();j++){
                if(i+wordDict[trans[i][j]].length() > l) continue;
                antecedent[i+wordDict[trans[i][j]].length()].push_back(trans[i][j]);
            }
        vector<string> ans;
        vector<int> vis(l+1), dis(l+1,0x3f3f3f3f);
        dijkstra(wordDict,trans,dis,vis,l);
        if(!flag) return ans;

        vector<int> list;
        dfsBuild(ans,list,wordDict,antecedent,l);
        return ans;
    }
}; 

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> output = sol.wordBreak(s,wordDict);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<endl;
}