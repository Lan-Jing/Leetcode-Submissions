#include <iostream>
using namespace std;
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = 0;
        int n = s.size();
        for(int i = 0;i < n;i++) {
            if(s[i] == '1' && (!i || s[i-1] == '0')) {
                if(!flag) {
                    flag = 1;
                } else return false;
            }
        }
        return true;
    }
};