#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length();
        int ans = 0;
        string ansString;
        for(int i = 0;i < l;i++){
            for(int j = 0;0 <= i - j && i + j < l;j++){
                if(s[i-j] != s[i+j]) break;
                else{
                    if(2*j+1 > ans) ansString = s.substr(i-j,2*j+1);
                    ans = max(ans,2*j+1);
                }
            }
            for(int j = 1;0 <= i - j + 1 && i + j < l;j++){
                if(s[i-j+1] != s[i+j]) break;
                else{
                    if(2*j > ans) ansString = s.substr(i-j+1,2*j);
                    ans = max(ans,2*j);
                }
            }
        }
        return ansString;
    }
};

int main(){
    Solution sol;
    cout<<sol.longestPalindorme("cbbd")<<endl;
    return 0;
}