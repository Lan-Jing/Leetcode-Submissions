#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    struct segNode {
        int l, r, count;
    }seg[100010];
    void build(int x, int l, int r) {
        seg[x].l = l, seg[x].r = r, seg[x].count = 0;
        if(l == r) return ;
        int mid = (l+r)/2;
        build(2*x,l,mid), build(2*x+1,mid+1,r);
    }
    void insert(int x, int l) {
        seg[x].count++;
        if(seg[x].l == seg[x].r)
            return ;
        int mid = (seg[x].l + seg[x].r) / 2;
        if(l > mid) insert(2*x+1,l);
        else insert(2*x,l);
    }
    int query(int x, int l, int r) {
        if(l > r) return 0;
        if(l <= seg[x].l && seg[x].r <= r)
            return seg[x].count;
        int mid = (seg[x].l + seg[x].r) / 2;
        if(l > mid) return query(2*x+1,l,r);
        if(r <= mid) return query(2*x,l,r);
        return query(2*x,l,mid) + query(2*x+1,mid+1,r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmpNums = nums;
        sort(tmpNums.begin(),tmpNums.end());
        unordered_map<int,int> numMap;
        for(int i = 0;i < tmpNums.size();i++)
            numMap[tmpNums[i]] = i;
        vector<int> ans;
        int n = nums.size();
        if(!n) return ans;
        build(1,0,n-1);
        for(int i = n-1;i >= 0;i--){
            ans.push_back(query(1,0,numMap[nums[i]]-1));
            insert(1,numMap[nums[i]]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {5};
    vector<int> ans = sol.countSmaller(input);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}