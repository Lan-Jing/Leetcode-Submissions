#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int nType = candiesCount.size(), n = queries.size();
        vector<long long int> sum(nType);
        vector<bool> ans;

        for(int i = 0;i < nType;i++) {
            sum[i] = i == 0 ? candiesCount[i] : sum[i-1] + candiesCount[i];
        }
        for(int i = 0;i < n;i++) {
            long long int lLimit = queries[i][1], rLimit = (long long int)(queries[i][1]+1)*(long long int)queries[i][2];
            cout<<lLimit<<' '<<rLimit<<endl;
            if(sum[queries[i][0]] > lLimit && (queries[i][0] == 0 || sum[queries[i][0]-1] < rLimit)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};