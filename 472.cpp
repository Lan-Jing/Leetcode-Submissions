#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    struct TrieNode {
        char ch;
        int end;
        unordered_map<char,TrieNode*> next;
        TrieNode(char _ch, int _end) : ch(_ch), end(_end) {}
    };
    TrieNode *root;
    unordered_map<string,TrieNode*> endMap;
    void buildTrie(TrieNode *now, string nowS, int nowPos) {
        if(nowPos == nowS.length()) return ;
        if(!now->next.count(nowS[nowPos]))
            now->next[nowS[nowPos]] = new TrieNode(nowS[nowPos],nowPos == nowS.length()-1);
        now->next[nowS[nowPos]]->end |= nowPos == nowS.length()-1;
        if(now->next[nowS[nowPos]]->end) endMap[nowS] = now->next[nowS[nowPos]];
        buildTrie(now->next[nowS[nowPos]],nowS,nowPos+1); 
    }
    int flag = 0;
    void dfsCheck(TrieNode *now, string &checked, int checkedPos, int turn) {
        if(flag) return ;
        if(checkedPos == checked.length()){
            if(now->end && now != endMap[checked] && turn) flag = 1; 
            return ;
        }
        if(now->end) dfsCheck(root,checked,checkedPos,turn+1);
        if(now->next.count(checked[checkedPos]))
            dfsCheck(now->next[checked[checkedPos]],checked,checkedPos+1,turn);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        root = new TrieNode('.',0);
        for(int i = 0;i < n;i++)
            buildTrie(root,words[i],0);
        for(int i = 0;i < n;i++){
            flag = 0;
            dfsCheck(root,words[i],0,0);
            if(flag) ans.push_back(words[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> output = sol.findAllConcatenatedWordsInADict(input);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<endl;
    return 0;
}