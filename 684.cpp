#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int uni[1010];
    int cnt;
    int find(int x) { return uni[x] == x ? x : find(uni[x]); }
    vector<int> findRedundantConnection(vector<vector<int> > &edges) {
        for(int i = edges.size()-1;i >= 0;i--){
            cnt = edges.size();
            for(int j = 1;j <= 1000;j++) uni[j] = j;
            for(int j = edges.size()-1;j >= 0;j--){
                if(i == j) continue;
                int a = edges[j][0], b = edges[j][1];
                int fa = find(a), fb = find(b);
                if(fa != fb){
                    cnt--;
                    uni[fa] = fb;
                }
            }
            if(cnt == 1) return edges[i];
        }
        return edges[0];
    }
};

int main() {

}