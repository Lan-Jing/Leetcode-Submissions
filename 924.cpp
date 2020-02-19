#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

/*
    union-find. Prevent a node from being initially infected wiil only help chunks with exacyly one initial malware.
    Record number of initial malware, pick out the biggest chunk with only one infected node. 
*/

class Solution {
public:
    struct malWare {
        int nodeCount, initialCount, head;
        malWare(int _n, int _ni, int _head) : nodeCount(_n), initialCount(_ni), head(_n) {}
        malWare() {}
    };
    int find(vector<malWare> &mal, int x) { return mal[x].head == x ? x : find(mal,mal[x].head); }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(),initial.end());
        int n = graph.size(), m = initial.size();
        vector<malWare> mal(n);
        for(int i = 0;i < n;i++)
            mal[i].nodeCount = 1, mal[i].head = i, mal[i].initialCount = 0;
        for(int i = 0;i < m;i++)
            mal[initial[i]].initialCount = 1;
        for(int i = 0;i < n;i++)
            for(int j = i+1;j < n;j++){
                if(!graph[i][j]) continue;
                int fi = find(mal,i), fj = find(mal,j);
                if(fi == fj) continue;
                mal[fi].head = fj;
                mal[fj].nodeCount += mal[fi].nodeCount;
                mal[fj].initialCount += mal[fi].initialCount;
                mal[fi].initialCount = mal[fi].nodeCount = 0;
            }
        int maxN = 0, ans = initial[0];
        for(int i = 0;i < m;i++){
            int now = find(mal,initial[i]);
            if(!mal[now].nodeCount || mal[now].initialCount > 1) continue;
            if(mal[now].nodeCount > maxN){
                maxN = mal[now].nodeCount;
                ans = initial[i];
            }
        }
        return ans;
    }
};

int main() {
}