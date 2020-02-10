#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    void dfsBuild(vector<string> &ans, vector<int> &list, vector<string> &wordDict, vector<vector<int> > &antecedent, int now) {
        if(!now){
            string tmp;
            for(int i = list.size()-1;i >= 0;i--){
                if(i < list.size()-1) tmp += " ";
                tmp += wordDict[list[i]];
            }
            ans.push_back(tmp);
            return ;
        }
        cout<<now<<endl;
        for(int i = 0;i < antecedent[now].size();i++){
            list.push_back(antecedent[now][i]);
            dfsBuild(ans,list,wordDict,antecedent,now-wordDict[antecedent[now][i]].length());
            list.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l = s.length(), n = wordDict.size();
        vector<vector<int> > trans(l+1), antecedent(l+1);
        for(int i = 0;i < l;i++)
            for(int j = 0;j < n;j++){
                int lj = wordDict[j].length();
                if(i + lj-1 >= l) continue;
                if(s.substr(i,lj) == wordDict[j]) 
                    trans[i].push_back(j);
            }
        for(int i = 0;i < l;i++)
            for(int j = 0;j < trans[i].size();j++){
                if(i+wordDict[trans[i][j]].length() > l) continue;
                antecedent[i+wordDict[trans[i][j]].length()].push_back(trans[i][j]);
            }
        vector<string> ans;
        vector<int> list;
        dfsBuild(ans,list,wordDict,antecedent,l);
        return ans;
    }
}; 

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> output = sol.wordBreak(s,wordDict);
    for(int i = 0;i < output.size();i++) cout<<output[i]<<endl;
}