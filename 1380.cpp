#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> minRow(m), maxCol(n);
        for(int i = 0;i < m;i++) minRow[i] = INT32_MAX;

        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                minRow[i] = min(minRow[i], matrix[i][j]);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                maxCol[i] = max(maxCol[i], matrix[j][i]);
        vector<int> ans;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                    ans.push_back(matrix[i][j]);
        return ans;
    }
};

int main() {

}