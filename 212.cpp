#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

/*
    a dfs solution with concurrent Trie matching.
    Details:
    a word can be another's prefix, so we need a tag for marking a non-leaf node with complete word.
*/

class Solution {
public:
    struct TrieNode {
        char ch;
        int end;
        vector<TrieNode*> next;
        TrieNode(char _x, int _end) : ch(_x), end(_end) {} 
        TrieNode(){}
    };
    void dfsBuild(TrieNode *root, string word, int now) {
        if(now == word.length()){
            root->end = 1; return ;
        }
        int found = -1;
        for(int i = 0;i < root->next.size();i++){
            if(root->next[i]->ch != word[now]) continue;
            found = i; break;
        }
        if(found == -1){
            TrieNode *newNode = new TrieNode(word[now],0);
            root->next.push_back(newNode);
            dfsBuild(newNode,word,now+1);
        }else dfsBuild(root->next[found],word,now+1);
    }
    TrieNode* buildTrie(vector<string> words) {
        TrieNode *root = new TrieNode('*',0);
        for(int i = 0;i < words.size();i++)
            dfsBuild(root,words[i],0);
        return root;
    }
    int gox[4]={0,0,-1,1}, goy[4]={1,-1,0,0};
    void dfsMatch(vector<string> &res, vector<vector<char> > &board, vector<vector<int> > &vis,
                  int y, int x, TrieNode* root, string &tmp) {
        if(root->end){
            int flag = 0;
            for(int i = 0;i < res.size();i++)
                if(res[i] == tmp){
                    flag = 1; break;
                }
            if(!flag) res.push_back(tmp);
        }
        if(!root->next.size()) return ;
        cout<<y<<','<<x<<':'<<tmp<<endl;
        for(int i = 0;i < 4;i++){
            int nx = x + gox[i], ny = y + goy[i];
            if(nx < 0 || ny < 0 || ny >= board.size() || nx >= board[ny].size() || vis[ny][nx]) continue;
            int found = -1;
            for(int k = 0;k < root->next.size();k++) {
                if(root->next[k]->ch != board[ny][nx]) continue;
                found = k; break;
            }
            if(found == -1) continue ;
            cout<<ny<<','<<nx<<'-'<<board[ny][nx]<<endl;
            vis[ny][nx] = 1; tmp.push_back(board[ny][nx]);
            dfsMatch(res,board,vis,ny,nx,root->next[found],tmp);
            vis[ny][nx] = 0; tmp.pop_back();
        }
    }
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<vector<int> > vis; vis.resize(board.size());
        for(int i = 0;i < board.size();i++) vis[i].resize(board[i].size());
        vector<string> res;
        string tmp = "";
        for(int i = 0;i < board.size();i++)
            for(int j = 0;j < board[i].size();j++){
                for(int k = 0;k < root->next.size();k++)
                    if(root->next[k]->ch == board[i][j]){
                        tmp = board[i][j]; vis[i][j] = 1;
                        dfsMatch(res,board,vis,i,j,root->next[k],tmp);
                        vis[i][j] = 0;
                        break;
                    }
            }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"oath","pea","eat","rain"};
    vector<vector<char> > board;
    vector<char> row;
/*    row = {'o','a','a','n'};
    board.push_back(row);
    row = {'e','t','a','e'};
    board.push_back(row);
    row = {'i','h','k','r'};
    board.push_back(row);
    row = {'i','f','l','v'};
    board.push_back(row);
    vector<string> ans = sol.findWords(board,words);
*/    

    row = {'a','a'}; board.push_back(row);
    words = {"aaa"};
    vector<string> ans = sol.findWords(board,words);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<endl;
}