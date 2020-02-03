#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <utility>

/*
    find the maximum number out of sliding windows.
    easy by using ascending queue. Basic thought was that 
    if a number is smaller than the previous, it can't change the max number in a window.
    So for the queue we only push in greater numbers. Record the locations for poping 
    when numbers are out of the window area. Finally the max number will be the front 
    of the queue at any single time.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(!nums.size()) return ans;
        deque<pair<int,int> > que;
        for(int i = 0;i < k;i++){
            if(que.empty()) que.push_front(make_pair(i,nums[i]));
            else{
                while(!que.empty() && que.front().second <= nums[i])
                    que.pop_front();
                que.push_front(make_pair(i,nums[i]));
            }
        }
        ans.push_back(que.back().second);
        for(int i = k;i < nums.size();i++){
            if(que.back().first == i-k) que.pop_back();
            while(!que.empty() && que.front().second <= nums[i])
                que.pop_front();
            que.push_front(make_pair(i,nums[i]));
            ans.push_back(que.back().second);
        }
        return ans;
    }
};

int main() {
    Solution sol; 
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    vector<int> output = sol.maxSlidingWindow(input,5);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<' '; cout<<endl;
    return 0;
}