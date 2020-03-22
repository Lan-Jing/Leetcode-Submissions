#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    int getPow(int x) {
        int ans = 0;
        while(x != 1) {
            if(x % 2) x = 3*x+1;
            else x /= 2;
            ans++;
        }
        return ans;
    }
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int> > vec;

        for(int i = lo;i <= hi;i++) {
            vec.push_back(make_pair(getPow(i),i));
        }
        sort(vec.begin(),vec.end(),cmp);
        return vec[k-1].second;
    }
};