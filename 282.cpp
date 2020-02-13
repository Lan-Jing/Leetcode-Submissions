#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        
    }
};

int main() {
    Solution sol;
    string num = "123"; int target = 6;
    vector<string> ans = sol.addOperators(num,target);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}