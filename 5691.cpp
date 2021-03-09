#include <functional>
#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        if(nums2.size() > 6*nums1.size() || nums1.size() > 6*nums2.size()) {
            return ans;
        } else ans = 0;

        vector<int> &lower = nums1, &higher = nums2;
        int n1 = nums1.size(), n2 = nums2.size();
        int sum1 = 0, sum2 = 0, gap = 0;
        for(int i = 0;i < n1;i++) sum1 += nums1[i];
        for(int i = 0;i < n2;i++) sum2 += nums2[i];
        gap = abs(sum1-sum2);
        if(sum1 == sum2) {
            return ans = 0;
        } else if(sum1 < sum2) {
            lower = nums1;
            higher = nums2;
        } else {
            swap(lower, higher);
            swap(n1, n2);
        }

        sort(lower.begin(), lower.end());
        sort(higher.begin(), higher.end(), greater<int>());

        int p1 = 0, p2 = 0;
        while(1) {
            ans++;
            if(p2 >= n2 || (p1 < n1 && 6-lower[p1] > higher[p2]-1)) {
                gap -= min(gap, 6-lower[p1]);
                p1++;
            } else if (p2 < n2) {
                gap -= min(gap, higher[p2]-1);
                p2++;
            }
            if(gap == 0) break;
        }

        return ans;
    }
};