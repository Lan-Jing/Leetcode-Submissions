#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <stack>

class Solution {
public:
    struct node{
        int pos, fin;
        node(int _pos, int _fin) : pos(_pos), fin(_fin) {}
        node() : pos(0), fin(0) {}
    };
    int longestValidParentheses(string s){
        int ls = s.length();
        node stk[1000010]; 
        int ans = 0, top = 0, rightMostUn = -1;
        for(int i = 0;i < ls;i++){
            if(s[i] == '('){
                rightMostUn = top;
                stk[top++] = node(i,-1);
            }else{
                if(rightMostUn == -1){
                    top = 0;
                    continue;
                }
                stk[rightMostUn].fin = 1;
                if(!rightMostUn){
                    top = rightMostUn + 1;
                    rightMostUn--;
                }else{
                    if(stk[rightMostUn-1].fin == 1){
                        top = rightMostUn;
                        rightMostUn -= 2;
                    }else{
                        top = rightMostUn + 1;
                        rightMostUn--;
                    }
                }
                ans = max(ans,i-stk[top-1].pos+1);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int ls = s.length();
        vector<vector<int> > dp; dp.resize(ls+5);
        for(int i = 0;i < ls+1;i++) dp[i].resize(ls+5);
        for(int i = 0;i < ls;i++)
            for(int j = 0;j <= ls;j++) dp[i][j] = -0x3f3f3f3f;
        for(int i = 0;i < ls;i++){
            for(int j = 0;j < ls;j++){
                if(s[i] == '(' && j){
                    if(j == 1){
                        if(i) dp[i][j] = max(1,dp[i-1][j-1] + 1);
                        else dp[i][j] = 1;
                    }else if(i) dp[i][j] = dp[i-1][j-1] + 1;
                }
                if(s[i] == ')' && i) dp[i][j] = dp[i-1][j+1] + 1;
//                cout<<'('<<i<<','<<j<<"):"<<dp[i][j]<<' ';
            }
//            cout<<endl;
        }
        int ans = 0;
        for(int i = 0;i < ls;i++) ans = max(ans,dp[i][0]);
        return ans;
    }
};
*/
int main() {
    Solution sol;
    cout<<sol.longestValidParentheses(")()())")<<endl;
    return 0;
}