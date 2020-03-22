#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cstring>

class Solution {
public:
    int next[100010];
    void get_next(string s) {
        int l = s.length();

        int j = -1;
        next[0] = -1;
        for(int i = 1;i < l;i++) {
            while(s[j+1] != s[i] && j > -1) j = next[j];
            if(s[j+1] == s[i]) j++;
            next[i] = j;
        }
    }
    string longestPrefix(string s) {
        int l = s.length();
        string ans = "";
    
        memset(next,0,sizeof(next));
        get_next(s);
        ans = s.substr(0,next[l-1]+1);

        return ans;
    }
};