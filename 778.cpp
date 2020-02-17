#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    int gox[4]={0,0,-1,1}, goy[4]={-1,1,0,0};
    static bool cmp(pair<int,int> &a, pair<int,int> &b) {
        return a.first < b.first;
    }
    int find(vector<int> &uni ,int x) { return uni[x] == x ? x : find(uni,uni[x]); }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int> > vec;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                vec.push_back(make_pair(grid[i][j],i*n+j));
        sort(vec.begin(),vec.end(),cmp);
        vector<int> uni(n*n);
        for(int i = 0;i < n*n;i++) uni[i] = i;
        int ans = 0;
        for(int i = 0;i < vec.size();i++){
            int nowHeight = vec[i].first, 
                x = vec[i].second % n, y = vec[i].second / n;
            for(int j = 0;j < 4;j++){
                int nx = x + gox[j], ny = y + goy[j];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(grid[ny][nx] < nowHeight){
                    int fnew = find(uni,ny*n+nx), fnow = find(uni,y*n+x);
                    if(fnew == fnow) continue;
                    uni[fnew] = uni[fnow];
                }
            }
            if(find(uni,0) == find(uni,n*n-1)){
                ans = nowHeight; 
                break;
            }
        }
        return ans;
    }
};

int main() {

}