#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    bool dfs(vector<vector<vector<int> > > &is, string &s1, string &s2, int start1, int start2, int l){
        if(is[start1][start2][l] != -1) return is[start1][start2][l];
        if(l == 1) return is[start1][start2][l] = (s1[start1] == s2[start2]);
        if(s1.substr(start1,l) == s2.substr(start2,l)) return is[start1][start2][l] = 1;
        is[start1][start2][l] = 0;
        for(int i = 1;i < l;i++){
            bool t1 = dfs(is,s1,s2,start1,start2,i), t2 = dfs(is,s1,s2,start1+i,start2+i,l-i);
            bool t3 = dfs(is,s1,s2,start1,start2+(l-i),i), t4 = dfs(is,s1,s2,start1+i,start2,l-i);
            is[start1][start2][l] = max(is[start1][start2][l],(int)((t1 && t2) || (t3 && t4)));
        }
        return is[start1][start2][l];
    }
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int n = s1.length();
        vector<vector<vector<int> > > is(n);
        for(int i = 0;i < n;i++){
            is[i].resize(n);
            for(int j = 0;j < n;j++){
                is[i][j].resize(n+1);
                for(int k = 0;k <= n;k++) is[i][j][k] = -1;
            }
        }        
        return dfs(is,s1,s2,0,0,n);
    }
};

int main() {
    Solution sol;
    string s1 = "great", s2 = "rgtae";
    cout<<sol.isScramble(s1,s2)<<endl;
    return 0;
}