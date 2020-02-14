#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

/*
    segment tree solution with maximum value insert and query.
    Added lazy update tag for speed up. Now it's capable of passing all test cases.
*/

class Solution {
public:
    struct segNode {
        int l,r, height;
        int lazy;
    }seg[80010];
    int realPos[80010];
    void build(int x, int l, int r) {
        seg[x].l = l, seg[x].r = r, seg[x].height = seg[x].lazy = 0;
        if(l >= r-1) return ;
        int mid = (l+r)/2;
        build(2*x,l,mid); build(2*x+1,mid,r);
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
    int query(int x, int l, int r) {
        if(seg[x].lazy){
            seg[x].height = max(seg[x].height,seg[x].lazy);
            if(seg[x].l < seg[x].r-1){
                seg[2*x].lazy = max(seg[2*x].lazy,seg[x].lazy);
                seg[2*x+1].lazy = max(seg[2*x+1].lazy,seg[x].lazy);
            }
            seg[x].lazy = 0;
        }
        int mid = (seg[x].l + seg[x].r)/2;
        if(l <= seg[x].l && seg[x].r <= r) return seg[x].height;
        if(l >= mid) return query(2*x+1,l,r);
        else if(r <= mid) return query(2*x,l,r);
        else return max(query(2*x,l,mid),query(2*x+1,mid,r));
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int> > ans;
        int n = buildings.size();
        if(!n) return ans;

        map<int,int> posMap;
        vector<int> pos;
        for(int i = 0;i < n;i++) 
            pos.push_back(buildings[i][0]), pos.push_back(buildings[i][1]);
        sort(pos.begin(),pos.end());
        int index = 0;
        for(int i = 0;i < pos.size();i++){
            posMap[pos[i]] = index;
            realPos[index++] = pos[i];
        }

        build(1,0,index-1);
        for(int i = 0;i < n;i++)
            insert(1,posMap[buildings[i][0]],posMap[buildings[i][1]],buildings[i][2]);

        vector<int> point(2);
        int lastH = 0;
        for(int i = 0;i < pos.size()-1;i++){
            int h = query(1,i,i+1);
            if(h != lastH){
                point[0] = realPos[i], point[1] = h;
                ans.push_back(point);
                lastH = h;
            }
        }
        point[0] = realPos[index-1], point[1] = 0; 
        ans.push_back(point);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > buildings;
    vector<int> building;
    building = {2,9,10}; buildings.push_back(building);
    building = {3,7,15}; buildings.push_back(building);
    building = {5,12,12}; buildings.push_back(building);
    building = {15,20,10}; buildings.push_back(building);
    building = {19,24,8}; buildings.push_back(building);
    vector<vector<int> > ans = sol.getSkyline(buildings);
    for(int i = 0;i < ans.size();i++) cout<<ans[i][0]<<','<<ans[i][1]<<endl;
    return 0;
}