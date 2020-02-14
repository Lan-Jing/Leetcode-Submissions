#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

/*
    We can directly dfs all answers, which take combinational time. 
    To improve it, consider that all we need is the shortest paths. Length of the shortest paths can be easily and quickly computed,
    then can be used to cut out longer paths.
*/

class Solution {
public:
    int maxStep;
    void dfs(vector<vector<string> >& ans, vector<string>& tmp, vector<vector<int> >& g, vector<int>& vis, vector<string>& wordList,
             int now, int step, string endWord) {
        if(step > maxStep) return ;
        if(wordList[now] == endWord){
            if(step < maxStep) maxStep = step, ans.clear();
            ans.push_back(tmp);
            return ;
        }
        vis[now] = 1;
        for(int i = 0;i < g[now].size();i++){
            if(vis[g[now][i]]) continue;
            tmp.push_back(wordList[g[now][i]]);
            dfs(ans,tmp,g,vis,wordList,g[now][i],step+1,endWord);
            tmp.pop_back();
        }
        vis[now] = 0;
    }
    void dijkstra(vector<int>& dis, vector<int>& vis, vector<vector<int> >& g, int start) {
        priority_queue<pair<int,int> > que; que.push(make_pair(start,0));
        dis[start] = 0;
        while(!que.empty()){
            pair<int,int> now = que.top(); que.pop();
            if(vis[now.first]) continue; else vis[now.first] = 1;
            for(int i = 0;i < g[now.first].size();i++){
                dis[g[now.first][i]] = min(dis[g[now.first][i]],dis[now.first] + 1);
                que.push(make_pair(g[now.first][i],dis[g[now.first][i]]));
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > ans;
        int k = beginWord.size(), n = wordList.size();
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
        vector<string> tmp; tmp.push_back(beginWord);
        vector<int> vis(n+1), dis(n+1,0x3f3f3f3f);
        maxStep = 0x3f3f3f3f;
        dijkstra(dis,vis,g,n);
        for(int i = 0;i <= n;i++) vis[i] = 0;
        for(int i = 0;i <= n;i++) if(wordList[i] == endWord) maxStep = dis[i];
        cout<<maxStep<<endl;
        dfs(ans,tmp,g,vis,wordList,n,0,endWord);
        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "qa", endWord = "sq";
    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    vector<vector<string> > output = sol.findLadders(beginWord,endWord,wordList);
    for(int i = 0;i < output.size();i++){
        for(int j = 0;j < output[i].size();j++) cout<<output[i][j]<<' '; cout<<endl;
    }
    return 0;
}