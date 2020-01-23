#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    a bit integer multiplication.
    first multiply all positions, then carry all at a time
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int l1 = num1.length(), l2 = num2.length();
        reverse(num1.begin(),num1.end()); reverse(num2.begin(),num2.end());
        int c[300]; memset(c,0,sizeof(c));
        for(int i = 0;i < l1;i++)
            for(int j = 0;j < l2;j++)
                c[i+j] += (num1[i]-'0') * (num2[j]-'0');
        for(int i = 0;i < l1+l2;i++)
            if(c[i] >= 10) c[i+1] += c[i] / 10, c[i] %= 10;
        string ans; int lans = 0;
        lans = c[l1+l2-1] ? l1 + l2 : l1 + l2 - 1;
        for(int i = lans-1;i >= 0;i--) ans.push_back(c[i]+'0');
        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.multiply("1","1")<<endl;
    return 0;
}