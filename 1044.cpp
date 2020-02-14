#include <iostream>
using namespace std;
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <cmath>

/*
    A better method is to use Rabin-karp matching algorithm, which is accessible.
    Consider a sliding window, we encode each substring in the window with rolling hash strategy.
    Take care of overflow and hash collision. Notice that the performance of hash heavily depends on
    length of the hashTable(shouldn't be too large). Try to change it for improvement.
*/

class Solution {
public:
    string ans;
    int pow(long long base, int t, int mod) {
        int ans = 1;
        while(t){
            if(t % 2) ans = (ans * base) % mod;
            t /= 2;
            base = (base * base) % mod;
        }
        return ans;
    }
    bool check(string s, int l) {
        int mod = 500007, ls = s.length();
        vector<vector<int> > hashTable(mod);
        long long nowHash = 0;
        for(int i = 0;i < l;i++)
            nowHash = (nowHash * 2 + s[i]-'a') % mod;
        hashTable[nowHash].push_back(0);
        for(int i = l;i < ls;i++){
            nowHash = ((2 * (nowHash - (s[i-l]-'a')*pow(2,l-1,mod))) % mod + s[i]-'a' + mod) % mod;
            if(!hashTable[nowHash].size()) hashTable[nowHash].push_back(i-l+1);
            else{
                for(int j = 0;j < hashTable[nowHash].size();j++){
                    int flag = 1, target = hashTable[nowHash][j];
                    string now = "";
                    for(int k = 0;k < l;k++)
                        if(s[i-l+k+1] != s[target+k]){
                            flag = 0; break;
                        }else now += s[i-l+k+1];
                    if(flag){
                        ans = now;
                        return true;
                    }
                }
                hashTable[nowHash].push_back(i-l+1);
            }
        }
        return false;
    }
    string longestDupSubstring(string s) {
        int ls = s.length();
        int l = 0, r = ls;
        while(l < r){
            int mid = (l+r)/2;
            if(check(s,mid)) l = mid + 1;
            else r = mid;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.longestDupSubstring("banana")<<endl;
    return 0;
}