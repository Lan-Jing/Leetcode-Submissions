#include <iostream>
using namespace std;
#include <utility>
#include <unordered_map>
#include <vector>
#include <string>

/*
    exellent practice! hashMap + union-find.
    To consider the problem, I need to learn hashMap first. With hashMap, we can in average in O(1) time tell 
    whether a number is recorded, which is much more efficient than tree-based map. However, hashMap doesn't 
    record relations between any two numbers.
    
    With hashMap, we now can instantly check the existence of i-1 or i+1 for any given number i. 
    These neighbors present natural connection with number i by adding or subtracting 1, 
    which can also be considered as edges in an undirected graph. Then the problem can be thought as finding number 
    of nodes in the largest subgraph connected by neighboring relations. Union-find will do fine on this.
*/

class Solution {
public:
    int find(vector<int> &uni, int x) { return uni[x] == x ? x : find(uni,uni[x]); }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(!n) return ans;

        vector<int> weight(n,1), uni(n);
        for(int i = 0;i < n;i++) uni[i] = i;
        unordered_map<int,int> hashMap;
        // this is the key! Finding neighboring numbers in O(1) time!

        for(int i = 0;i < n;i++){
            if(hashMap.count(nums[i])) continue;
            else hashMap[nums[i]] = i;

            int left = -1, right = -1;
            if(hashMap.count(nums[i]-1)) left = hashMap[nums[i]-1];
            if(hashMap.count(nums[i]+1)) right = hashMap[nums[i]+1];
            int fl = left == -1 ? -1 : find(uni,left), 
                fr = right == -1 ? -1 : find(uni,right);
            if(fl != -1){
                weight[i] += weight[fl];
                weight[fl] = 0;
                uni[fl] = i;
            }
            if(fr != -1){
                weight[i] += weight[fr];
                weight[fr] = 0;
                uni[fr] = i;
            }
            ans = max(ans,weight[i]);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {100,99,4,200,98,97,101,1,3,2};
    cout<<sol.longestConsecutive(input)<<endl;
    return 0;
}