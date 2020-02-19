#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>

/*
    Trie tree solution. Mind the property that when palindrome is formed by concatenating s[i] and s[j],
    one end of the palindrome should be a prefix of another end.
    So that we build up a trie tree by inserting every string and its reverse. Then match each string in the trie
    and check if the substring left, which will reside in the middle of the palindrome, is parlindrome.
    Matching and ckecking process both run in O(n) time, while time may be consumed by finding all substrings.
*/

class Solution {
public:
    struct TrieNode {
        char ch;
        vector<int> index;
        unordered_map<char,TrieNode*> next;
        TrieNode(char _ch): ch(_ch) {}
    };
    int n;
    void buildTrie(TrieNode *now, string newS, int nowPos, int index) {
        if(nowPos == newS.length()) return ;
        if(!now->next.count(newS[nowPos]))
            now->next[newS[nowPos]] = new TrieNode(newS[nowPos]);
        if(nowPos == newS.length()-1)
            now->next[newS[nowPos]]->index.push_back(index);
        buildTrie(now->next[newS[nowPos]],newS,nowPos+1,index);
    }
    void dfsCheck(set<pair<int,int> > &Set, TrieNode *now, string nowS, int index) {
        if(now->index.size()){
            int flag = 1, ls = nowS.length();
            if(ls % 2){
                int i = ls/2;
                for(int j = 1;i-j >= 0;j++)
                    if(nowS[i-j] != nowS[i+j]){
                        flag = 0; break;
                    }
            }else if(ls > 0){
                int i = ls/2-1;
                for(int j = 0;i-j >= 0;j++)
                    if(nowS[i-j] != nowS[i+j+1]){
                        flag = 0; break;
                    }
            }
            if(flag){
                for(int i = 0;i < now->index.size();i++){
                    if(now->index[i]/n + index/n != 1 || now->index[i]%n == index%n) continue;
                    Set.insert(make_pair(now->index[i]/n ? index%n : now->index[i]%n, now->index[i]/n ? now->index[i]%n : index%n));
                }
            }
        }
        for(unordered_map<char,TrieNode*>::iterator iter = now->next.begin();iter != now->next.end();iter++)
            dfsCheck(Set,iter->second,nowS+iter->first,index);
    }
    void find(set<pair<int,int> > &Set, TrieNode *now, string nowS, int nowPos, int index) {
        if(nowPos == nowS.length()){
            dfsCheck(Set,now,"",index);
            return ;
        }
        if(now->next.count(nowS[nowPos]))
            find(Set,now->next[nowS[nowPos]],nowS,nowPos+1,index);
    }
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > ans;
        set<pair<int,int> > Set;
        n = words.size();
        if(!n) return ans;
        TrieNode *root = new TrieNode('.');
        for(int i = 0;i < 2*n;i++){
            if(i < n){
                string t = words[i];
                reverse(t.begin(),t.end());
                words.push_back(t);
            }
            if(!words[i].length())
                root->index.push_back(i);
            else buildTrie(root,words[i],0,i);
        } 
        for(int i = 0;i < 2*n;i++)
            find(Set,root,words[i],0,i);
        vector<int> tmp(2);
        for(set<pair<int,int> >::iterator iter = Set.begin();iter != Set.end();iter++){
            tmp[0] = iter->first, tmp[1] = iter->second;
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"bat","tab","cat"};
    vector<vector<int> > ans = sol.palindromePairs(input);
    for(int i = 0;i < ans.size();i++) cout<<ans[i][0]<<','<<ans[i][1]<<endl;
    return 0;
}