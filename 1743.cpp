#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        map<int, vector<int> >idxHash;
        for(int i = 0;i < n-1;i++) {
            idxHash[adjacentPairs[i][0]].push_back(i);
            idxHash[adjacentPairs[i][1]].push_back(i);
        }
        int start = 0, loc = 0;
        for(map<int, vector<int> >::iterator iter=idxHash.begin();iter != idxHash.end();iter++) {
            if(iter->second.size() == 1) {
                start = iter->first;
                loc = iter->second[0];
                break;
            }
        }
        vector<int> ans;
        while(ans.size() < n) {
            vector<int> now = adjacentPairs[loc];
            cout<<start<<endl;
            if(now[0] == start) {
                ans.push_back(now[0]);
                start = now[1];
            } else {
                ans.push_back(now[1]);
                start = now[0];
            }
            
            if(ans.size() == n)
                break;
            if(ans.size() == n-1) {
                loc = idxHash[start][0];
            } else {
                loc = idxHash[start][0] == loc ? idxHash[start][1] : idxHash[start][0];
            }
        }
        return ans;
    }
};