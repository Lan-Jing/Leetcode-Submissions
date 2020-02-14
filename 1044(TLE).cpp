#include <iostream>
using namespace std;
#include <string>
#include <set>

/*
    The basic and trick idea of this problem is binary searching the maximum length of duplicates.
    For any given length, we need to find duplicates as fast as possible.
    TLE solution use set as trivial method.
*/

class Solution {
public:
    string ans;
    bool check(string S, int l) {
        set<string> Set;
        int ls = S.length();
        for(int i = 0;i+l-1 < ls;i++){
            string now = S.substr(i,l);
            if(Set.count(now)){
                ans = now;
                return true;
            }else Set.insert(now);
        }
        return false;
    }
    string longestDupSubstring(string S) {
        int ls = S.length();
        int l = 0, r = ls-1;
        while(l < r){
            int mid = (l+r)/2;
            if(check(S,mid)) l = mid + 1;
            else r = mid;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.longestDupSubstring("a")<<endl;
    return 0;
}