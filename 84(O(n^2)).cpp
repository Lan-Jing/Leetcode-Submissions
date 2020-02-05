#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cmath>

/*
    This O(n^2) solution just merely pass all test cases.
    Again it just consider the ascending-left-wall property to reudce the calculations.
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if(!heights.size()) return 0;
        vector<int> lque;
        vector<long long int> segMin;
        long long int ans = 0;
        lque.push_back(0), segMin.push_back(heights[0]);
        for(int i = 0;i < heights.size();i++){
            if(i && heights[i] > heights[i-1]){
                lque.push_back(i);
                segMin.push_back(heights[i]);
            }
            
            segMin.back() = min(segMin.back(),(long long int)heights[i]);
            long long int minh = pow(2,32);
            for(int j = lque.size()-1;j >= 0;j--){
                minh = min(minh,segMin[j]);
                cout<<'('<<lque[j]<<','<<i<<')'<<minh*(i-lque[j]+1)<<endl;
                ans = max(ans,minh*(i-lque[j]+1));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {0,2147483647};
    cout<<sol.largestRectangleArea(input)<<endl;
    return 0;
}