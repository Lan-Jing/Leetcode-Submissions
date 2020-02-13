#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    struct segNode {
        int l,r, maxHeight;
    }seg[80010];
    int realPos[80010];
    void build(int x, int l, int r) {
        seg[x].l = l, seg[x].r = r, seg[x].maxHeight = 0;
        if(l >= r-1) return ;
        int mid = (l+r)/2;
        build(2*x,l,mid); build(2*x+1,mid,r);
    }
    int insert(int x, int l, int r, int val) {
        if(l <= seg[x].l && seg[x].r <= r)
            seg[x].maxHeight = max(seg[x].maxHeight,val);
        if(seg[x].l >= seg[x].r-1) return seg[x].maxHeight;
        int mid = (seg[x].l + seg[x].r)/2;
        if(l >= mid) return insert(2*x+1,l,r,val);
        else if(r <= mid) return insert(2*x,l,r,val);
        else return max(insert(2*x,l,mid,val),insert(2*x+1,mid,r,val));
    }
    int query(int x, int l, int r) {
        if(l <= seg[x].l && seg[x].r <= r) return seg[x].maxHeight;
        int mid = (seg[x].l + seg[x].r)/2;
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
        for(int i = 0;i < n;i++) pos.push_back(buildings[i][0]), pos.push_back(buildings[i][1]);
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
        point[0] = realPos[index-1], point[1] = 0; ans.push_back(point);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > buildings;
    vector<int> building;
    building = {1,2,1}; buildings.push_back(building);
    building = {2147483646,2147483647,2147483647}; buildings.push_back(building);
    vector<vector<int> > ans = sol.getSkyline(buildings);
    for(int i = 0;i < ans.size();i++) cout<<ans[i][0]<<','<<ans[i][1]<<endl;
    return 0;
}