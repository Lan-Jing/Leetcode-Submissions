#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <stdint.h>
#include <utility>

/*
    Another tricky problem. As linear time/space is required, brutal force solution will
    make use of sorting not based on comparision, such as radix sort. Considering INT range,
    radix sort should run on exactly O(n) space and O(10n) time, which is quite a perfect choice.

    The perfect solution bases on piegon principle. Consider a sorted array, when distance between two 
    adjacent numbers shrinks, that between other numbers may enlarge. In the best case, numbers are 
    distributed evenly from the minimum number to the maximum, for instance, 0,3,6,9. The piegon principle 
    ensure a minimum gap (max-min)/(n-1), where max-min is the largest distance and n-1 number of gaps.
    Therefore, we don't need to concern about numbers with mutual distances smaller than the minimum gap.
    We use n buckets, as the ith bucket stores numbers between min+(minGap)*i and min+(minGap)*(i+1)-1.
    Numbers in the same bucket will never affect the maximum gap we want. What we need to do is maintaining 
    the maximum number and minimum one for each bucket, and check all distances between two non-empty 
    buckets by min[r]-max[l] to get the final answer.

    Be careful of corner cases.
    1. all numbers are equal: minGap = 0;
    2. numbers distributed evenly: the maximum number stored in the nth bucket.
    3. empty buckets: skip them when checking.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxn = 0, minn = INT32_MAX;
        int n = nums.size();
        if(n < 2) return 0;
        if(n == 2) return abs(nums[0]-nums[1]);
        for(int i = 0;i < n;i++)
            maxn = max(maxn,nums[i]),
            minn = min(minn,nums[i]);
        int minGap = ceil((double)(maxn-minn)/(double)(n-1));
        if(!minGap) return 0;
        vector<pair<int,int> > bucket(n);
        for(int i = 0;i < n;i++)
            bucket[i].first = INT32_MAX,
            bucket[i].second = 0;
        for(int i = 0;i < n;i++){
            int target = (nums[i]-minn) / minGap;
            bucket[target].first = min(bucket[target].first,nums[i]);
            bucket[target].second = max(bucket[target].second,nums[i]);
        }
        int ans = minGap;
        int l = 0, r = 1;
        while(r < n){
            if(bucket[r].first != INT32_MAX || bucket[r].second != 0){
                cout<<bucket[r].first-bucket[l].second<<endl;
                ans = max(ans,bucket[r].first-bucket[l].second);
                l = r;
            }
            r++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {100,3,2,1};
    cout<<sol.maximumGap(input)<<endl;
    return 0;
}