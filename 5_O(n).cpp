#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    string longestPalindrome(string s) {
        string ans, t = "<";
        int ls = s.length();
        if(!ls) return ans;
        for(int i = 0;i < ls;i++)
            t += '#', t += s[i];
        t += "#>";
        int lt = t.length();
        vector<int> p(lt);
        int center = 0, right = 0, maxL = 0;
        for(int i = 1;i < lt-1;i++){
            if(i > right) p[i] = 1;
            else p[i] = min(p[2*center-i],right-i+1);
            while(t[i-p[i]] == t[i+p[i]]) p[i]++;
            if(i+p[i]-1 > right){
                right = i+p[i]-1;
                center = i;
                if(p[i]-1 > maxL){
                    maxL = p[i]-1;
                    ans = s.substr((i-p[i])/2,p[i]-1);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "abcbabcba";
    cout<<sol.longestPalindrome(input)<<endl;
    return 0;
}