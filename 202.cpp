#include <iostream>
using namespace std;
#include <string>
#include <set>

class Solution {
public:
    set<int> Set;
    int getNext(int x) {
        int ans = 0;
        while(x) {
            ans += (x % 10) * (x % 10);
            x /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        while(n != 1 && n != 10 && n != 100) {
            if(Set.count(n)) return false;
            else {
                Set.insert(n);
                n = getNext(n);
            }
        }
        return true;
    }
};