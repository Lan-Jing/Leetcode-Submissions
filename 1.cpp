#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    struct node{
        int index, num;
        node(){}
        node(int index,int num){ this->index = index, this->num = num; }
        bool operator < (const node &other) const {
            return this->num < other.num;
        }
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        struct node list[100010];
        for(int i = 0;i < nums.size();i++) list[i] = node(i,nums[i]);
        sort(list,list+nums.size());
//        for(int i = 0;i < nums.size();i++) cout<<list[i].num<<' '; cout<<endl;
        for(int i = 0;i < nums.size();i++){
            if(list[i].num > target / 2) break;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
//                cout<<l<<' '<<r<<endl;
                int mid = (l + r)/2;
                if(list[mid].num < target - list[i].num) l = mid + 1;
                else r = mid;
            }
            if(list[l].num == target - list[i].num){
                result.push_back(list[i].index); 
                result.push_back(list[l].index);
                break;
            }
        }
        return result;
    }
};


int main(){
    Solution sol;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    nums.push_back(24);
    nums.push_back(4);
    nums.push_back(10);
    vector<int> result = sol.twoSum(nums,25);
    cout<<result[0]<<' '<<result[1]<<endl;
    return 0;
}