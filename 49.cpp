#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

/*
    sort every string and use the sorted one as key for a map.
    We can use the appearing frequency list as key and spare the sorting part.
*/

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs) {
        vector<vector<string> > res;
        map<string,int> Map;
        int index = 0;
        for(int i = 0;i < strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(!Map.count(tmp)) Map[tmp] = index++;
        }
        res.resize(index);
        for(int i = 0;i < strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            res[Map[tmp]].push_back(strs[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"", "", "eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > ans = sol.groupAnagrams(input);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++) cout<<ans[i][j]<<','; cout<<endl;
    }
    return 0;
}