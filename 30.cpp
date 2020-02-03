#include <iostream>
using namespace std;
#include <string>
#include <utility>
#include <map>
#include <vector>

/*
    first map all substrings in s into numbers, which turn the problem into validations 
    of number lists. Restriction on word length would be useful. It split string s into K parts,
    each a number list to fit(by numbers from words). Then we manage to change the original problem 
    into sliding window problems, counting all windows containing every numbers from set words.
    
    each char in s make up a node in one of K lists. Also each node should be visited up to two times
    (left and right bounds), making it an O(N) solution.
*/ 

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> ans;
        if(!words.size()) return ans;

        int ls = s.length(), k = words[0].length();
        map<string,int> smap;
        int index = 0;
        for(int i = 0;i+k-1 < ls;i++){
            string tmp = s.substr(i,k);
            if(smap.count(tmp)) continue;
            smap[tmp] = index++;
        }
        
        map<int,int> Count; 
        int cnt = 0;
        for(int i = 0;i < words.size();i++){
            if(!smap.count(words[i])) return ans;
            if(!Count.count(smap[words[i]])) cnt++;
            Count[smap[words[i]]]++;
        }
        
        vector<int> mapList;
        for(int i = 0;i < k;i++){
            int j = i;
            mapList.clear();
            map<int,int> tmpCount = Count;
            int tmpCnt = cnt;
            while(j+k-1 < ls){
                string tmp = s.substr(j,k);
                mapList.push_back(smap[tmp]);
                j += k;
            }

            int l = 0, r = 0;
            while(r < mapList.size()){
                if(!tmpCount.count(mapList[r])){
                    tmpCount = Count;
                    tmpCnt = cnt;
                    l = r = r+1;
                }else{
                    if(!tmpCount[mapList[r]])
                        while(l < r && !tmpCount[mapList[r]]){
                            if(!tmpCount[mapList[l]]) tmpCnt++;
                            tmpCount[mapList[l++]]++;
                        }
                    tmpCount[mapList[r]]--;
                    if(!tmpCount[mapList[r]]) tmpCnt--;
                    if(!tmpCnt) ans.push_back(i+l*k);
                    r++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string input = "aaa";
    vector<string> words = {"a","b"};
    vector<int> ans = sol.findSubstring(input,words);
    for(int i = 0;i < ans.size();i++) cout<<ans[i]<<' '; cout<<endl;
    return 0;
}