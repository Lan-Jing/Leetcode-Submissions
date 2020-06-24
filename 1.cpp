#include <iostream>
using namespace std;
#include <string>
#include <set>

class Solution {
public:
    int countElements(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        set<int> Set;
        for(int i = 0;i < n;i++) Set.insert(arr[i]);
        for(int i = 0;i < n;i++) ans += Set.count(arr[i]+1);
        return ans;
    }
};