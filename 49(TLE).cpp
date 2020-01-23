#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    a hand-coding hashTable which is EXETREMLY slow, which can't survive the last few cases.
*/

class Solution {
public:
    struct hashNode {
        vector<int> fre;
        vector<string> group;
        int in;
        hashNode() : in(0) {}
    };
    bool check(vector<int> hashNode, vector<int> fre) {
        for(int i = 0;i < hashNode.size();i++) if(fre[i] != hashNode[i]) return false;
        return true;
    }
    int hashCal(vector<hashNode> hashList, vector<int> fre, vector<int> prime) {
        int x = 0;
        for(int i = 0;i < fre.size();i++) x = (x + fre[i] * prime[i]) % prime[prime.size()-1];
        while(hashList[x].in && !check(hashList[x].fre,fre)){
            if(x+1 < hashList.size()) x++;
            else x = 0;
        }
        cout<<x<<endl;
        return x;
    }
    void makePrime(vector<int> &prime) {
        int isntPrime[10000]; memset(isntPrime,0,sizeof(isntPrime));
        for(int i = 2;i < 10000;i++){
            if(!isntPrime[i]) prime.push_back(i);
            for(int j = 1;i*j < 10000;j++) isntPrime[i*j] = 1;
        }
//       for(int i = 0;i < prime.size();i++) cout<<prime[i]<<' '; cout<<endl;
    }
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > res;
        vector<hashNode> hashList; hashList.resize(1000);
        vector<int> prime;
        makePrime(prime);
        cout<<strs.size()<<endl;
        for(int i = 0;i < strs.size();i++){
            vector<int> fre; fre.resize(26);
            for(int j = 0;j < strs[i].length();j++) fre[strs[i][j]-'a']++;
            int x = hashCal(hashList,fre,prime);
            hashList[x].fre = fre;
            hashList[x].in = 1;
            hashList[x].group.push_back(strs[i]);
        }
        for(int i = 0;i < hashList.size();i++){
            if(!hashList[i].in) continue;
            res.push_back(hashList[i].group);
        }
        return res;
    }
};

int main() {
    Solution sol; 
    vector<string> input = {"","","aa","aaa","eat","tea","tan","ate","nat","bat"};
    vector<vector<string> > res = sol.groupAnagrams(input);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++) cout<<res[i][j]<<','; cout<<endl;
    }
    return 0;
}