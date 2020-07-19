#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng = g.size(), ns = s.size();
        sort(g.begin(), g.end()); sort(s.begin(), s.end());
        int index = 0, ans = 0;
        for(int i = 0;i < ng;i++) {
            while(index < ns && s[index] < g[i]) index++;
            if(index >= ns) break;
            ans++; index++;
        }
        return ans;
    }
};