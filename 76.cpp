#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

/*
    another standard sliding window problem.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int lt = t.length(), ls = s.length();
        map<char,int> Map;
        set<char> Set;
        int cnt = 0;
        for(int i = 0;i < lt;i++)
            Set.insert(t[i]), Map[t[i]]++;
        cnt = Set.size();

        string ans = "";
        int l = 0,r = 0;
        int minL = 0x3f3f3f3f, minPos = -1;
        while(r < ls){
            cout<<l<<' '<<r<<endl;
            if(Set.count(s[r])){
                Map[s[r]]--;
                if(Map[s[r]] == 0) cnt--;
            }
            if(!cnt){
                while(l <= r){
                    if(!Set.count(s[l]) || (Set.count(s[l]) && Map[s[l]] < 0)){
                        if(Set.count(s[l])) Map[s[l]]++;
                        l++;
                    }else break;
                }
            }
            if(!cnt && minL > (r-l+1)){
                minL = r-l+1; minPos = l;
                cout<<"*:"<<l<<' '<<r<<endl;
            }
            r++;
        }

        if(minPos != -1) ans = s.substr(minPos,minL);
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "bdab", t = "ab";
    cout<<sol.minWindow(s,t)<<endl;
    return 0;
}