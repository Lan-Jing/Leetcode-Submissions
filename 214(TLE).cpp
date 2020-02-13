#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string shortestPalindrome(string s) {
        int ls = s.length();
        if(!ls) return s;
        int right = 0;
        for(int i = 0;i <= (ls-1)/2;i++){
            int flag = 1;
            for(int j = 1;i-j >= 0;j++){
                if(s[i-j] != s[i+j]){
                    flag = 0; break;
                }
            }
            if(flag) right = max(right,2*i+1);
            flag = 1;
            for(int j = 0;i-j >= 0;j++){
                if(s[i-j] != s[i+j+1]){
                    flag = 0; break;
                }
            }
            if(flag) right = max(right,2*i+2);
        }
        string ans = s.substr(right,ls-right);
        reverse(ans.begin(),ans.end());
        return ans + s;
    }
};

int main() {
    Solution sol;
    string input = "abbacd";
    cout<<sol.shortestPalindrome(input)<<endl;
    return 0;
}