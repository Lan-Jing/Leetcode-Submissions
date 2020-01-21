#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size()) return 0;
        int lSum[height.size()], rSum[height.size()];
        memset(lSum,0,sizeof(lSum)); memset(rSum,0,sizeof(rSum));
        for(int i = 0;i < height.size();i++) lSum[i] = i ? lSum[i-1] + height[i] : height[i];
        for(int i = height.size()-1;i >= 0;i--) rSum[i] = i < height.size()-1 ? rSum[i+1] + height[i] : height[i];
        int ans = 0;
        int leftPos = 0, leftH = height[0];
        for(int i = 1;i < height.size();i++){
            if(height[i] >= leftH){
                ans += leftH * (i-leftPos-1) - (lSum[i-1]-lSum[leftPos]);
                leftH = height[i], leftPos = i;
            }
        }
        int lbound = leftPos, rightPos = height.size()-1, rightH = height[rightPos];
        for(int i = height.size()-2;i >= lbound;i--){
            if(height[i] >= rightH){
                ans += rightH * (rightPos-i-1) - (rSum[i+1]-rSum[rightPos]);
                rightH = height[i], rightPos = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol; 
    vector<int> input = {6,0,7,0,6};
    cout<<sol.trap(input)<<endl;
    return 0;
}