#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*
    Also a dfs print 
*/

class Solution {
public:
    void dfs(vector<string>& ans, string tempAns, int step, int leftCnt, int NUnfinished, int n) {
        if(step == 2*n){
            cout<<tempAns<<endl;
            ans.push_back(tempAns);
            return ;
        }else{
            if(leftCnt < n) dfs(ans,tempAns+'(',step+1,leftCnt+1,NUnfinished+1,n);
            if(NUnfinished > 0) dfs(ans,tempAns+')',step+1,leftCnt,NUnfinished-1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans,"",0,0,0,n);
        return ans;
    }
};

int main(){
    Solution sol;
    sol.generateParenthesis(3);
    return 0;
}