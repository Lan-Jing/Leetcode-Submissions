#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    bool check(string target, map<string,int> dic, int step, int tot, int l) {
        if(step == tot) return true;
        string tar = target.substr(0,l);
        if(dic[tar] != 0){
            dic[tar]--;
            return check(target.substr(l,target.length()-l),dic,step+1,tot,l);
        }else return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int ls = s.length(), ldic = 0;
        map<string,int> dic;
        vector<int> ans;
        if(!words.size()) return ans;
        for(int i = 0;i < words.size();i++) 
            dic[words[i]]++, ldic += words[i].length();
        for(int i = 0;i < ls;i++)
            if(check(s.substr(i,ldic),dic,0, words.size(),words[0].length()))
                ans.push_back(i);
        return ans;
    }
};