#include <iostream>
using namespace std;
#include <string>
#include <vector>

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