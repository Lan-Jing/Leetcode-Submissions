#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

/*
    print all strings in a dfs manner.
*/

class Solution {
public:
    string Map[8];
    void dfsPrint(vector<string>& ans, string now, string digits, int pos, int tot) {
        if(pos == tot){
            ans.push_back(now);
            cout<<now<<endl;
            return ;
        }else{
            for(int i = 0;i < Map[digits[pos] - '2'].size();i++){
                now += Map[digits[pos] - '2'][i];
                dfsPrint(ans,now,digits,pos+1,tot);
                now.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        int ls = digits.length();
        Map[0] = "abc";
        Map[1] = "def";
        Map[2] = "ghi";
        Map[3] = "jkl";
        Map[4] = "mno";
        Map[5] = "pqrs";
        Map[6] = "tuv";
        Map[7] = "wxyz";
        vector<string> ans;
        if(!ls) return ans;
        dfsPrint(ans,"",digits,0,ls);
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "5";
    sol.letterCombinations(input);
    return 0;
}