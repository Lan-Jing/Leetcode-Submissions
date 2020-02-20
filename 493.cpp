#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    struct segNode {
        int l, r, cnt;
    }seg[100010];
    void build(int x, int l, int r) {
        seg[x].l = l, seg[x].r = r, seg[x].cnt = 0;
        if(l == r) return ;
        int mid = (l+r)/2;
        build(2*x,l,mid), build(2*x+1,mid+1,r);
    }
    void insert(int x, int val) {
        seg[x].cnt++;
        if(seg[x].l == seg[x].r) return ;
        int mid = (seg[x].l + seg[x].r) / 2;
        if(val <= mid) insert(2*x,val);
        else insert(2*x+1,val);
    }
    int query(int x, int l, int r) {
        if(l > r) return 0;
        if(l <= seg[x].l && seg[x].r <= r)
            return seg[x].cnt;
        int mid = (seg[x].l + seg[x].r) / 2;
        if(l > mid) return query(2*x+1,l,r);
        if(r <= mid) return query(2*x,l,r);
        return query(2*x,l,mid) + query(2*x+1,mid+1,r);
    }
    int reversePairs(vector<int> &nums) {
        int ans = 0;
        if(!nums.size()) return ans;
        vector<int> tmp = nums;
        unordered_map<int,int> Map;
        sort(tmp.begin(),tmp.end());
        for(int i = 0;i < tmp.size();i++)
            Map[tmp[i]] = i;
        build(1,0,tmp.size()-1);
        for(int i = nums.size()-1;i >= 0;i--){
            double target = ((double)nums[i])/2;
            int l = 0, r = tmp.size();
            while(l < r){
                int mid = (l+r)/2;
                if(target-tmp[mid] > 0) l = mid + 1;
                else r = mid;
            }
            ans += query(1,0,l-1);
            insert(1,Map[nums[i]]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {2,4,3,5,1};
    cout<<sol.reversePairs(input)<<endl;
    return 0;
}