#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <utility>
#include <cmath>

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int minError = INT32_MAX;
        pair<int,int> ans;
        vector<int> res;
        for(int n = num+1;n <= num+2;n++) {
            for(int i = 1;i <= sqrt(n);i++) {
                if(n % i) continue;
                if(n/i - i < minError) {
                    ans.first = i, ans.second = n/i;
                    minError = n/i - i;
                }
            }
        }
        res.push_back(ans.first), res.push_back(ans.second);
        return res;
    }
};

int main() {

}