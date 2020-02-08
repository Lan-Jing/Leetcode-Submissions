#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    a DP solution on Problem 85, based on the preprocessing strategy for "maximum area in a histogram".
    Consider the basic thought of the strategy, In O(n) time we try to find the first bar that is shorter 
    to its left and right, respectively. 
    
    In the 2-D situation, left[i] and right[i] for each i can be transited directly from the upper row, 
    as all information has been computed. Also notice that the left and right ranges
    on a consecutive rows with '1's should be monotomously increasing and decreasing. The allowed range 
    should follow the shortest one, shrinking when '0' are met at the corners:
    0 1 |1| 0 0
    0 1 |1| 1 0
    0 0 |1| 0 0 
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        vector<int> leftMost(n,-1), rightMost(n,n), height(n);
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                height[j] = matrix[i][j] == '0' ? 0 : height[j]+1;
            int left = 0, right = n;
            for(int j = 0;j < n;j++)
                if(matrix[i][j] == '0') leftMost[j] = -1, left = j;
                else leftMost[j] = max(left,leftMost[j]);
            for(int j = n-1;j >= 0;j--)
                if(matrix[i][j] == '0') rightMost[j] = n, right = j;
                else rightMost[j] = min(right,rightMost[j]);
            for(int j = 0;j < n;j++)
                ans = max(ans,height[j]*(rightMost[j]-leftMost[j]-1));
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