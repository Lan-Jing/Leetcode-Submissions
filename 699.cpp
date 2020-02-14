#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/*
    Another classic segment tree problem. Only need to consider a maxHeight query then an modification for every dropped square.
*/

class Solution {
public:
    struct segNode {
        int l, r, height, lazy;
    }seg[10000];
    void build(int x, int l, int r) {
        seg[x].l = l, seg[x].r = r, seg[x].height = seg[x].lazy = 0;
        if(l >= r-1) return ;
        int mid = (l + r)/2;
        build(2*x,l,mid), build(2*x+1,mid,r);
    }
    int query(int x, int l, int r) {
        if(seg[x].lazy){
            seg[x].height = max(seg[x].height,seg[x].lazy);
            if(seg[x].l < seg[x].r-1){
                seg[2*x].lazy = max(seg[2*x].lazy,seg[x].lazy);
                seg[2*x+1].lazy = max(seg[2*x+1].lazy,seg[x].lazy);
            }
            seg[x].lazy = 0;
        }
        if(l <= seg[x].l && seg[x].r <= r) return seg[x].height;
        int mid = (seg[x].l + seg[x].r) / 2;
        if(r <= mid) return query(2*x,l,r);
        else if(l >= mid) return query(2*x+1,l,r);
        else return max(query(2*x,l,mid),query(2*x+1,mid,r));
    }
    int insert(int x, int l, int r, int val) {
        if(l <= seg[x].l && seg[x].r <= r){
            seg[x].lazy = max(seg[x].lazy,val);
            seg[x].height = max(seg[x].height,seg[x].lazy);
            return seg[x].height;
        }
        int mid = (seg[x].l + seg[x].r) / 2;
        if(r <= mid) return seg[x].height = max(seg[x].height,insert(2*x,l,r,val));
        else if(l >= mid) return seg[x].height = max(seg[x].height,insert(2*x+1,l,r,val));
        else return seg[x].height = max(seg[x].height,max(insert(2*x,l,mid,val),insert(2*x+1,mid,r,val)));
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        if(!positions.size()) return ans;
        map<int,int> Map;
        
        vector<int> tmp;
        for(int i = 0;i < positions.size();i++)
            tmp.push_back(positions[i][0]), tmp.push_back(positions[i][0]+positions[i][1]);
        sort(tmp.begin(),tmp.end());
        for(int i = 0;i < tmp.size();i++)
            Map[tmp[i]] = i;
        build(1,0,tmp.size()-1);
        int maxh = 0;
        for(int i = 0;i < positions.size();i++){
            int segMax = query(1,Map[positions[i][0]],Map[positions[i][0]+positions[i][1]]);
            maxh = max(maxh,segMax+positions[i][1]);
            ans.push_back(maxh);
            insert(1,Map[positions[i][0]],Map[positions[i][0]+positions[i][1]],segMax+positions[i][1]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input;
    vector<int> square;
    square = {100,100}; input.push_back(square);
    square = {200,100}; input.push_back(square);
    vector<int> ans = sol.fallingSquares(input);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<' '; cout<<endl;
    return 0;
}