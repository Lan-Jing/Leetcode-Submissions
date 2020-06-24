#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int count = 0, n = gas.size(), ans = 0;
        for(int i = 0;i < n;i++)
            count += gas[i] - cost[i];
        if(count < 0) return -1;
        count = 0;
        for(int i = 0;i < n;i++) {
            count += gas[i] - cost[i];
            if(count < 0) {
                count = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};