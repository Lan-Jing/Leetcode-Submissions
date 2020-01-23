#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

/*
    dfs for string partition.
*/

class Solution {
public:
    void dfs(vector<vector<string> > &ans, vector<string> &res, vector<vector<int> > pos,
             string s, int left, int tot){
        if(left == tot){
            for(int i = 0;i < res.size();i++) cout<<res[i]<<' '; cout<<endl;
            ans.push_back(res);
            return ;
        }
        for(int i = 0;i < pos[left].size();i++){
            res.push_back(s.substr(left,pos[left][i]-left));
            dfs(ans,res,pos,s,pos[left][i],tot);
            res.pop_back();
        }
    }
    vector<vector<string> > partition(string s) {
        int ls = s.length();
        vector<vector<int> > pos; pos.resize(ls);
        vector<vector<string> >  ans;
        vector<string> res;
        for(int i = 0;i < ls;i++){
            for(int j = 0;i-j >= 0 && i+j < ls;j++){
                if(s[i-j] != s[i+j]) break;
                pos[i-j].push_back(i+j+1);
            }
            for(int j = 0;i-j >= 0 && i+j+1 < ls;j++){
                if(s[i-j] != s[i+j+1]) break;
                pos[i-j].push_back(i+j+2);
            }
        }
        for(int i = 0;i < ls;i++) sort(pos[i].begin(),pos[i].end());
        for(int i = 0;i < ls;i++){
            cout<<i<<':';
            for(int j = 0;j < pos[i].size();j++) cout<<pos[i][j]<<' ';
            cout<<endl;
        }
        dfs(ans,res,pos,s,0,ls);
        return ans;
    }
};

int main(){
    Solution sol; 
    string input = "a";
    sol.partition(input);
    return 0;
}