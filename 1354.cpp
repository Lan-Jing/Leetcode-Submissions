#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stdint.h>

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int curSum = 0;
        if(target.size() == 1) return target[0] == 1;
        priority_queue<long long int,vector<long long int>,less<long long int> > que;
        for(int i = 0;i < target.size();i++)
            curSum += target[i], que.push(target[i]);
        while(!que.empty()){
            long long int now = que.top(); que.pop();
            if(now == 1) continue;
            long long int otherSum = curSum - now;
            long long int newNum = now;
            long long int l = 1, r = INT32_MAX / otherSum;
            while(l < r){
                long long int mid = (l+r)/2;
                if(newNum - mid*otherSum > que.top()) l = mid + 1;
                else r = mid;
            }
            newNum -= l * otherSum;
            curSum -= l * otherSum;
            if(newNum < 1) return false;
            que.push(newNum);
        }
        return true;
    }
};

int main() {

}