#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

/*
    However, we can solve this problem without even "trying". Consider any two points in the middle of one of our answer path, their 
    distance should always be minimized. Otherwise, a shorter path shorter then the shortest one is found, which is impossible.
    So we can collect direct antecedents of each point when computing the shortest distances. Then from the end point, follow 
    antecedents recursively to construct all answers. Finally reverse the path and push it.
*/

class Solution {
public:
    struct queNode {
        int index, dis;
        queNode(int _ind, int _dis) : index(_ind), dis(_dis) {}
        bool operator < (const queNode &other) const {
            return dis > other.dis;
        }
    };
    void dijkstra(vector<vector<int> > &antecedent, vector<int> &dis, vector<int> &vis, vector<vector<int> > &g,
                  int start) {
        priority_queue<queNode> que; que.push(queNode(start,0));
        dis[start] = 0;
        while(!que.empty()){
            queNode now = que.top(); que.pop();
            if(vis[now.index]) continue; else vis[now.index] = 1;
            for(int i = 0;i < g[now.index].size();i++){
                int next = g[now.index][i];
                if(dis[next] >= now.dis + 1){
                    if(dis[next] > now.dis + 1){
                        antecedent[next].clear();
                        dis[next] = now.dis + 1;
                        que.push(queNode(next,dis[next]));
                    }
                    antecedent[next].push_back(now.index);
                }
            }
        }
    }
    void dfsBuild(vector<vector<string> > &ans, vector<string> &tmp, vector<vector<int> > &antecedent, vector<int> &vis, vector<string> &wordList, 
                  int now, int end) {
        if(now == end){
            ans.push_back(tmp); reverse(ans.back().begin(), ans.back().end());
            return ;
        }
        vis[now] = 1;
        for(int i = 0;i < antecedent[now].size();i++){
            int next = antecedent[now][i];
            if(vis[next]) continue;
            tmp.push_back(wordList[next]);
            dfsBuild(ans,tmp,antecedent,vis,wordList,next,end);
            tmp.pop_back();
        }
        vis[now] = 0;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > ans;
        int n = wordList.size(), k = beginWord.size();
        if(!n) return ans;
        int found = 0;
        for(int i = 0;i < n;i++) found = found | (wordList[i] == endWord);
        if(!found) return ans;

        wordList.push_back(beginWord);
        vector<vector<int> > g(n+1);
        for(int i = 0;i < n;i++)
            for(int j = i+1;j <= n;j++){
                found = 0;
                for(int p = 0;p < k;p++) found += wordList[i][p] != wordList[j][p];
                if(found == 1) g[i].push_back(j), g[j].push_back(i);
            }
        vector<int> dis(n+1,0x3f3f3f3f), vis(n+1,0);
        vector<vector<int> > antecedent(n+1);
        dijkstra(antecedent,dis,vis,g,n);

        for(int i = 0;i < n;i++)
            if(wordList[i] == endWord){
                found = i; break;
            }
        vector<string> tmp; tmp.push_back(wordList[found]);
        for(int i = 0;i <= n;i++) vis[i] = 0;
        dfsBuild(ans,tmp,antecedent,vis,wordList,found,n);
        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string> > ans = sol.findLadders(beginWord,endWord,wordList);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++) cout<<ans[i][j]<<' '; cout<<endl;
    }
    return 0;
}