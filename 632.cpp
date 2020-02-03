#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>

/*
    find the shortest range that covers at least one number from each group.
    First we need a map for mapping discrete numbers into consecutive indecies.
    Then we introduce a sliding window strategy to determine the wanted range.
    Maintain a counter for covered group. When all groups are covered, try to
    narrow the range by moving the left bound to right.
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,int> ind, reInd, Set;
        int cnt = 0, index = 0;
        vector<int> temp;
        for(int i = 0;i < nums.size();i++)
            for(int j = 0;j < nums[i].size();j++)
                temp.push_back(nums[i][j]);
        sort(temp.begin(),temp.end());
        for(int i = 0;i < temp.size();i++){
            if(index && ind[index] == temp[i]) continue;
            ind[++index] = temp[i];
            reInd[temp[i]] = index;
        }

        for(int i = 0;i < temp.size();i++) cout<<temp[i]<<':'<<reInd[temp[i]]<<endl; cout<<endl;

        vector<vector<int> > color; color.resize(index+10);
        for(int i = 0;i < nums.size();i++)
            for(int j = 0;j < nums[i].size();j++)
                if(!j || (j && nums[i][j] != nums[i][j-1]))
                    color[reInd[nums[i][j]]].push_back(i);
        int l = 1, r = 1, minL = 0x3f3f3f3f, minPos = -1;
        while(r <= index){
            for(int i = 0;i < color[r].size();i++){
                if(!Set.count(color[r][i])) cnt++;
                Set[color[r][i]]++;
            }
            if(cnt == nums.size()){
                while(l <= r){
                    cout<<l<<' '<<r<<endl;
                    int flag = 1;
                    for(int i = 0;i < color[l].size();i++){
                        if(Set[color[l][i]] == 1){
                            flag = 0; break;
                        }
                    }
                    if(flag){
                        for(int i = 0;i < color[l].size();i++)
                            Set[color[l][i]]--;
                        l++;
                    }else break;
                }
            }
            if(cnt == nums.size() && ind[r]-ind[l]+1 < minL){
                minL = ind[r]-ind[l]+1;
                minPos = ind[l];
            }
            r++;
        }
        vector<int> range;
        range.push_back(minPos);
        range.push_back(minPos+minL-1);
        return range;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input; vector<int> tmp;
    tmp = {10,10}; input.push_back(tmp);
    tmp = {11,11}; input.push_back(tmp);
//    tmp = {5,18,22,30}; input.push_back(tmp);
    tmp = sol.smallestRange(input);
    cout<<tmp[0]<<','<<tmp[1]<<endl;
    return 0;
}