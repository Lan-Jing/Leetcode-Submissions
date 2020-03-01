#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    static bool cmp(pair<int,vector<int> > a, pair<int,vector<int> > b) {
        for(int i = 0;i < a.second.size();i++)
            if(a.second[i] != b.second[i])
                return a.second[i] > b.second[i];
        return a.first < b.first;
    }
    string rankTeams(vector<string>& votes) {
        string ans = "";
        int n = votes.size();
        if(!n) return ans;
        int m = votes[0].length();

        vector<vector<int> > cnt(26);
        for(int i = 0;i < cnt.size();i++)
            cnt[i].resize(m);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cnt[votes[i][j]-'A'][j]++;
        vector<pair<int,vector<int> > > vec(26);
        for(int i = 0;i < 26;i++)
            vec[i] = make_pair(i,cnt[i]);
        sort(vec.begin(),vec.end(),cmp);
        for(int i = 0;i < m;i++)
            ans.push_back('A'+vec[i].first);
        return ans;
    }
};

int main() {

}