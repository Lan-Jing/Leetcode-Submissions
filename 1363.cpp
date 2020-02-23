#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool cmp(int a, int b) { return a > b; }
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(),digits.end(),cmp);
        int n = digits.size();
        string ans;
        int mod = 0;
        for(int i = 0;i < n;i++) {
            ans += digits[i]+'0';
            mod = (mod + digits[i]) % 3;
        }
        if(!mod) {
            while(ans[0] == '0' && ans.size() > 1) ans.erase(0,1);
            return ans;
        }

        for(int i = n-1;i >= 0;i--) {
            if((mod-digits[i]) % 3) continue;
            ans.erase(i,1);
            while(ans[0] == '0' && ans.size() > 1) ans.erase(0,1);
            return ans;
        }
        int flag = 0;
        for(int i = n-1;i >= 0;i--) {
            if(digits[i] % 3 == (mod == 2 ? 1 : 2)) {
                ans.erase(i,1);
                if(!flag) flag = 1;
                else break;
            }
        }
        while(ans[0] == '0' && ans.size() > 1) ans.erase(0,1);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {9,8,6,8,6};
    cout<<sol.largestMultipleOfThree(digits)<<endl;
    return 0;
}