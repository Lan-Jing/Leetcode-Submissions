#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height){
        int ans = 0;
        vector<int> leftQue, rightQue;
        int last = -1;
        for(int i = 0;i < height.size();i++){
            if(height[i] <= last) continue;
            last = height[i];
            leftQue.push_back(i);
        }
        last = -1;
        for(int i = height.size()-1;i >= 0;i--){
            if(height[i] <= last) continue;
            last = height[i];
            rightQue.push_back(i);
        }
        for(int i = 0;i < leftQue.size();i++){
            for(int j = 0;j < rightQue.size();j++){
                if(leftQue[i] >= rightQue[j]) break;
                ans = max(ans,(rightQue[j]-leftQue[i])*(min(height[rightQue[j]],height[leftQue[i]])));
//                cout<<ans<<' '<<leftQue[i]<<','<<rightQue[j]<<endl;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    cout<<sol.maxArea(input)<<endl;
    return 0;
}