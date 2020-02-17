#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>

class Solution {
public:
    struct malWare {
        int nodeCount, initialCount, head;
    };
    int find(vector<malWare> &mal, int x) { return mal[x].head == x ? x : find(mal,mal[x].head); }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(),initial.end());
        int n = graph.size(), m = initial.size();
        int minn = INT32_MAX, ans = 0;
        for(int removed = 0;removed < m;removed++){
            int now = initial[removed];
            vector<malWare> mal(n);
            for(int i = 0;i < n;i++) 
                mal[i].head = i, mal[i].nodeCount = 1, mal[i].initialCount = 0;
            for(int i = 0;i < m;i++)
                mal[initial[i]].initialCount = 1;
            for(int i = 0;i < n;i++){
                if(i == now) continue;
                for(int j = i+1;j < n;j++){
                    if(j == now || !graph[i][j]) continue;
                    int fi = find(mal,i), fj = find(mal,j);
                    if(fi == fj) continue;
                    mal[fi].head = fj;
                    mal[fj].initialCount += mal[fi].initialCount;
                    mal[fj].nodeCount += mal[fi].nodeCount;
                    mal[fi].initialCount = mal[fi].nodeCount = 0;
                }
            }
            int cnt = 0;
            for(int i = 0;i < n;i++)
                if(mal[i].head == i && mal[i].initialCount)
                    cnt += mal[i].nodeCount;
            if(cnt < minn){
                minn = cnt;
                ans = now;
            } 
        }
        return ans;
    }
};

int main() {

}