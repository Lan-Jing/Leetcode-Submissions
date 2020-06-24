#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>

class Solution {
public:
    int bfs(vector<string>& wordList, int beginIndex, int endIndex) {
        int n = wordList.size(), l = wordList[0].length();
        queue<pair<int, int> > que; que.push(make_pair(beginIndex, 1));
        vector<int> vis(n, 0);
        map<string, int> Map; 
        for(int i = 0;i < n;i++) Map[wordList[i]] = i;
        while(!que.empty()) {
            pair<int, int> nowNode = que.front(); que.pop();
            if(nowNode.first == endIndex) return nowNode.second;
            if(vis[nowNode.first]) continue; else vis[nowNode.first] = 1;
            for(int i = 0;i < l;i++)
                for(int j = 'a';j <= 'z';j++) {
                    string tmp = wordList[nowNode.first];
                    tmp[i] = j;
                    if(!Map.count(tmp)) continue;
                    que.push(make_pair(Map[tmp], nowNode.second + 1));
                }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), beginIndex = -1, endIndex = -1;
        for(int i = 0;i < n;i++) {
            if(wordList[i] == beginWord)
                beginIndex = i;
            if(wordList[i] == endWord)
                endIndex = i;
        }
        if(endIndex < 0) return 0;
        if(beginIndex < 0) {
            wordList.push_back(beginWord);
            beginIndex = n++;
        }
        return bfs(wordList, beginIndex, endIndex);
    }
};