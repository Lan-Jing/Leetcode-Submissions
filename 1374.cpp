#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(!n) return ans;

        if(n % 2) {
            for(int i = 0;i < n;i++) ans += 'a';
        } else {
            ans += 'a';
            for(int i = 0;i < n-1;i++) ans += 'b';
        }
        return ans;
    }
};