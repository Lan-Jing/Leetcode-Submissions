#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
    Although the original array is not sorted, the mapping relation is still clear.
    So build a mapping array to get real values, then use "virtual" addresses for binary search.
*/

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if(!nums.size()) return -1;
        int middlePos = 0, maxn = 0;
        for(int i = 0;i < nums.size();i++)
            if(nums[i] > maxn){
                maxn = nums[i];
                middlePos = i;
            }
        vector<int> realPos; realPos.resize(nums.size());
        for(int i = 0;i < nums.size();i++){
            if(i + middlePos + 1 >= nums.size()) realPos[i] = i - (nums.size()-middlePos-1);
            else realPos[i] = i + middlePos + 1;
        }
//        for(int i = 0;i < nums.size();i++) cout<<realPos[i]<<' '; cout<<endl;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = (l+r)/2;
//            cout<<mid<<' '<<realPos[mid]<<endl;
            if(nums[realPos[mid]] < target) l = mid + 1;
            else r = mid;
        }
        if(nums[realPos[l]] != target) return -1;
        else return realPos[l];
    }
};

int main() {
    Solution sol;
    vector<int> input = {4,5,6,7,8,-1,0,1,2};
    cout<<sol.search(input,7)<<endl;
    cout<<sol.search(input,3)<<endl;
    return 0;
}