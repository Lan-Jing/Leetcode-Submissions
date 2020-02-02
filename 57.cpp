#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval) {
        vector<vector<int> > res;
        if(!intervals.size()){
            res.push_back(newInterval); return res;
        }
        int a = newInterval[0], b = newInterval[1];
        int left = -1;
        for(int i = 0;i < intervals.size();i++)
            if(intervals[i][0] <= a){
                left = i;
                if(i == intervals.size()-1 || intervals[i+1][0] > a) break;
            }
        int right = 0x3f3f3f3f;
        for(int i = 0;i < intervals.size();i++)
            if(intervals[i][0] > b){
                right = i; break;
            }
        cout<<left<<' '<<right<<endl;
        if(left == -1 && right == 0x3f3f3f3f){
            if(intervals[intervals.size()-1][1] > b)
                newInterval[1] = intervals[intervals.size()-1][1];
            res.push_back(newInterval); return res;
        }else if(left == -1 && right != 0x3f3f3f3f){
            if(right && intervals[right-1][1] > b)
                newInterval[1] = intervals[right-1][1];
            res.push_back(newInterval);
            for(int i = right;i < intervals.size();i++) 
                res.push_back(intervals[i]);
            return res;
        }else if(right == 0x3f3f3f3f && left != -1){
            if(intervals[intervals.size()-1][1] > b)
                newInterval[1] = intervals[intervals.size()-1][1];
            if(intervals[left][1] >= a){
                newInterval[0] = intervals[left][0];
                for(int i = 0;i < left;i++)
                    res.push_back(intervals[i]);
                if(intervals[left][1] > b) 
                    newInterval[1] = intervals[left][1];
            }else{
                for(int i = 0;i <= left;i++)
                    res.push_back(intervals[i]);
            }
            res.push_back(newInterval);
            return res;
        }else{
            if(intervals[left][1] >= a){
                newInterval[0] = intervals[left][0];
                for(int i = 0;i < left;i++)
                    res.push_back(intervals[i]);
            }else{
                for(int i = 0;i <= left;i++)
                    res.push_back(intervals[i]);
            }
            if(intervals[right-1][1] >= b)
                newInterval[1] = intervals[right-1][1];
            res.push_back(newInterval);
            for(int i = right;i < intervals.size();i++)
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > input, output;
    vector<int> tmp = {3,7}; input.push_back(tmp);
//    tmp = {3,5}; input.push_back(tmp);
//    tmp = {6,7}; input.push_back(tmp);
//    tmp = {7,7}; input.push_back(tmp);
    tmp = {8,16}; input.push_back(tmp);
    vector<int> newin = {1,7};
    output = sol.insert(input, newin);
    for(int i = 0;i < output.size();i++)
        cout<<output[i][0]<<','<<output[i][1]<<endl;
    return 0;
}