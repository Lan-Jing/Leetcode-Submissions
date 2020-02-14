#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <stack>

/*
    longest valid parentheses, a hard stack problem. We use array-style stack to not only operate on the top but also deeper elements.
    A valid parentheses may contain multiple valid parentheses, for instance, ()(), which means we have to record some information of
    those finished parentheses. We mark each left bracket as unfinished(0) or finished(1). For finished parentheses, we only preserve 
    the leftmost one for length calculation. Other brackets should all be unfinished. 
    1. If the new valid parentheses are to the right of the finished one, finish the current match, compute the length then just pop them out.
    2. If the left bracket of the new one locates to the left while the right one to the right, holding the marked bracket in its middle,
       then we get a more left bound. change the mark and pop out the old.
    To do this we need a pointer to keep track of the rightmost unfinished left bracket, which can locate either to the left or right of the 
    leftmost finished bracket. The key is to maintain the leftmost valid left brakcet.
*/

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
                    // to its right.
                        top = rightMostUn;
                        rightMostUn -= 2;
                    }else{
                    // to its left.
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