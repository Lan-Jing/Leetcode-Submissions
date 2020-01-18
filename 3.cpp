#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <set>

/*
    use a set supporting a sliding window manner.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        int length = s.length();
        int l = 0, ans = 0;
        for(int i = 0;i < length;i++){
            while(Set.count(s[i]) && l < i) Set.erase(s[l++]);
            Set.insert(s[i]);
            ans = max(ans,i-l + 1);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}