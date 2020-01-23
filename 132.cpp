#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    For minimum cut, implement a dp algorithm for partition, record minimum time for each position.
*/

class Solution {
public:
    int minCut(string s) {
        int ls = s.length();
        vector<vector<int> > pos; pos.resize(ls);
        for(int i = 0;i < ls;i++){
            for(int j = 0;i-j >= 0 && i+j < ls;j++){
                if(s[i-j] != s[i+j]) break;
                pos[i-j].push_back(i+j+1);
            }
            for(int j = 0;i-j >= 0 && i+j+1 < ls;j++){
                if(s[i-j] != s[i+j+1]) break;
                pos[i-j].push_back(i+j+2);
            }
        }
        for(int i = 0;i < ls;i++) sort(pos[i].begin(),pos[i].end());
/*        for(int i = 0;i < ls;i++){
            cout<<i<<':';
            for(int j = 0;j < pos[i].size();j++) cout<<pos[i][j]<<' ';
            cout<<endl;
        }
*/        vector<int> dp; dp.resize(ls+1);
        for(int i = 0;i <= ls;i++) dp[i] = 0x3f3f3f3f;
        dp[0] = 0;
        for(int i = 0;i < ls;i++){
            for(int j = 0;j < pos[i].size();j++)
                dp[pos[i][j]] = min(dp[pos[i][j]],dp[i]+1);
//            cout<<dp[i]<<' ';
        }
        return dp[ls]-1;
    }
};

int main() {
    Solution sol;
    string input = "ababa";
    cout<<sol.minCut(input)<<endl;
    return 0;
}