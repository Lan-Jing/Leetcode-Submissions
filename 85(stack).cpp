#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stack>

/*
    in O(n^2) time sum up bar height for every point (i,j) then sub-problem on each row 
    is the "maximum area in a histogram", which can be solved in O(n) time
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        vector<vector<int> > height(m);
        for(int i = 0;i < m;i++) height[i].resize(n);
        for(int j = 0;j < n;j++)
            for(int i = 0;i < m;i++){
                if(matrix[i][j] == '0') height[i][j] = 0;
                else height[i][j] = (i ? height[i-1][j] : 0) + 1;
            }
        stack<int> stk;
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(stk.empty() || height[i][stk.top()] < height[i][j])
                    stk.push(j);
                else{
                    while(!stk.empty() && height[i][stk.top()] >= height[i][j]){
                        int now = stk.top(); stk.pop();
                        ans = max(ans,height[i][now]*(j-(stk.empty() ? -1 : stk.top())-1));
                    }
                    stk.push(j);
                }
            }
            while(!stk.empty()){
                int now = stk.top(); stk.pop();
                ans = max(ans,height[i][now]*(n-(stk.empty() ? -1 : stk.top())-1));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char> > input;
    vector<char> tmp;
    tmp = {'1','0','1','1','0'}; input.push_back(tmp);
    tmp = {'1','0','1','1','1'}; input.push_back(tmp);
    tmp = {'1','1','1','1','1'}; input.push_back(tmp);
    tmp = {'1','0','1','1','0'}; input.push_back(tmp);
    cout<<sol.maximalRectangle(input)<<endl;
    return 0;
}