#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int maxn = 0, ans = 0;
        for(int i = 0;i < light.size();i++){
            maxn = max(maxn, light[i]);
            if(maxn == i+1) ans++;
        }
        return ans;
    }
};