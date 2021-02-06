#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>

class Solution {
public:
    int box_of_ball(int num) 
    {
        int idx = 0;
        while(num) {
            idx += num % 10;
            num /= 10;
        }
        return idx;
    }
    int countBalls(int lowLimit, int highLimit) 
    {
        int n = highLimit - lowLimit + 1;
        int maxCnt = 0;
        vector<int> cnt(50, 0);
        for(int i = lowLimit;i <= highLimit;i++) {
            maxCnt = max(maxCnt, ++cnt[box_of_ball(i)]);
        }
        return maxCnt;
    }
};

int main() 
{
    Solution sol;
    cout<<sol.countBalls(19, 28)<<endl;
    return 0;
}