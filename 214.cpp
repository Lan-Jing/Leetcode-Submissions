#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int getNext(string s) {
        vector<int> next(s.length());
        next[0] = -1;
        int l = -1;
        for(int r = 1;r < s.length();r++){
            while(s[l+1] != s[r] && l > -1) l = next[l];
            next[r] = s[l+1] == s[r] ? ++l : l;
        }
        return next.back();
    }
    string shortestPalindrome(string s) {
        if(!s.length()) return s;
        string t = s; reverse(t.begin(),t.end());

        for(int i = getNext(s+" "+t)+1;i < s.length();i++) t += s[i];
        reverse(t.begin(),t.end());
        return t;
    }
};

int main() {
    Solution sol;
    string input = "abbacd";
    cout<<sol.shortestPalindrome(input)<<endl;
    return 0;
}