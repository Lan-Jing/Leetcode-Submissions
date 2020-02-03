#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

/*
    graph building and disjoint set.
    consider the connection between a couple as an undirected edge,
    then a connected group with n nodes, formed by two adjacent people needs n-1 swaps to reconstruct.
    Then we can solve the problem by counting connected groups and numbers of nodes in them.
*/

class Solution {
public:
    int uni[50];
    int weight[50];
    int g[50][50];
    int find(int x) { return uni[x] == x ? x : find(uni[x]); }
    int minSwapsCouples(vector<int> &row) {
        int n = row.size() / 2;
        for(int i = 0;i < 50;i++) 
            uni[i] = i, weight[i] = 1;
        for(int i = 0;i < n;i++)
            for(int j = i;j < n;j++)
                for(int k = 0;k <= 1;k++){
                    int l = 2*i+k;
                    if((row[l] % 2 && (row[2*j] == row[l]-1 || row[2*j+1] == row[l]-1)) ||
                       (!(row[l] % 2) && (row[2*j] == row[l]+1 || row[2*j+1] == row[l]+1))){
                           int fi = find(i), fj = find(j);
                           if(fi == fj) continue;
                           uni[fi] = fj, weight[fj] += weight[fi], weight[fi] = 0;
                       }
                }
        int ans = 0;
        for(int i = 0;i < n;i++) cout<<weight[i]<<' '; cout<<endl;
        for(int i = 0;i < n;i++)
            if(weight[i] > 1) ans += weight[i]-1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {5,1,2,3,4,0};
    cout<<sol.minSwapsCouples(input)<<endl;
    return 0;
}