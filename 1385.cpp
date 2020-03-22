#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = arr1.size();
        for(int i = 0;i < arr1.size();i++) {
            int flag = 0;
            for(int j = 0;j < arr2.size();j++)
                if(abs(arr1[i] - arr2[j]) <= d) {
                    flag = 1; break;
                }
            ans -= flag;
        }
        return ans;
    }
};