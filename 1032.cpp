#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class StreamChecker {
public:
    struct TrieNode {
        char ch;
        int end;
        unordered_map<char,TrieNode*> next;
        TrieNode(char _ch, int _end) : ch(_ch), end(_end) {}
    };
    TrieNode *root;
    string buffer;
    void buildTrie(TrieNode *now, string &nowS, int nowPos) {
        if(nowPos == nowS.length()) return ;
        if(!now->next.count(nowS[nowPos]))
            now->next[nowS[nowPos]] = new TrieNode(nowS[nowPos],nowPos == nowS.length()-1);
        now->next[nowS[nowPos]]->end |= nowPos == nowS.length()-1;
        buildTrie(now->next[nowS[nowPos]],nowS,nowPos+1);
    }
    bool queryTrie(TrieNode *now, string &buffer, int nowPos) {
        if(now->end) return true;
        if(nowPos < 0) return false; 
        if(now->next.count(buffer[nowPos]))
            return queryTrie(now->next[buffer[nowPos]],buffer,nowPos-1);
        else return false;
    }
    StreamChecker(vector<string>& words) {
        root = new TrieNode('.',0);
        for(int i = 0;i < words.size();i++){
            reverse(words[i].begin(),words[i].end());
            buildTrie(root,words[i],0);
        }
    }
    bool query(char letter) {
        buffer += letter;
        return queryTrie(root,buffer,buffer.length()-1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> input = {"cd","f","kl"};
    StreamChecker streamChecker(input); // init the dictionary.
    cout<<streamChecker.query('a')<<endl;          // return false
    cout<<streamChecker.query('b')<<endl;          // return false
    cout<<streamChecker.query('c')<<endl;          // return false
    cout<<streamChecker.query('d')<<endl;          // return true, because 'cd' is in the wordlist
    cout<<streamChecker.query('e')<<endl;          // return false
    cout<<streamChecker.query('f')<<endl;          // return true, because 'f' is in the wordlist
    cout<<streamChecker.query('g')<<endl;          // return false
    cout<<streamChecker.query('h')<<endl;          // return false
    cout<<streamChecker.query('i')<<endl;          // return false
    cout<<streamChecker.query('j')<<endl;          // return false
    cout<<streamChecker.query('k')<<endl;          // return false
    cout<<streamChecker.query('l')<<endl;          // return true, because 'kl' is in the wordlist
    return 0;
}