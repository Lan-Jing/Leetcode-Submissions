#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    every trick dfs problem.
    First do not try to solve it with divide-and-conquer manner with arbitrary order, due to limited computation order and precedence.
    Then a trivial solution is to try all four possibility between every two chars: nothing, '+', '-' or '*'.
    finally use O(n) time to compute the answer, which is inefficent.

    Think about keeping the current evaluated value from left to right. Then we first determine two operands then the operator.
    Use a loop to cut out the second operand, while the current evaluation is always the first. Try every operator. Mind that 
    multiplication holds different order. The left operand computed should now combined to its right instead of left that is already 
    completed. To handle this we need a mulRes parameter to record the multiplication results and previous operands. when a multiplcation
    is added, reverse the last operation(which can only be add or sub), get the new result then add it into the current value.
*/
 
class Solution {
public:
    void dfs(vector<string> &ans, string &num, int target, string tmp, int nowPos, long long nowVal, long long mulRes) {
        if(nowVal == target && nowPos == num.length()){
            ans.push_back(tmp); return ;
        }
        string curStr = "";
        long long cur = 0;
        for(int i = nowPos;i < num.length();i++){
            cur = cur * 10 + num[i]-'0';
            curStr += num[i];
            if(i > nowPos && num[nowPos] == '0') break;
            if(!nowPos) dfs(ans,num,target,tmp+curStr,i+1,nowVal+cur,cur);
            else{
                dfs(ans,num,target,tmp+"+"+curStr,i+1,nowVal+cur,cur);
                dfs(ans,num,target,tmp+"-"+curStr,i+1,nowVal-cur,-cur);
                dfs(ans,num,target,tmp+"*"+curStr,i+1,nowVal-mulRes+mulRes*cur,mulRes*cur);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string tmp = "";
        dfs(ans,num,target,tmp,0,0,0);
        return ans;
    }
};

int main() {
    Solution sol;
    string num = "3456237490"; int target = 9191;
    vector<string> ans = sol.addOperators(num,target);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}