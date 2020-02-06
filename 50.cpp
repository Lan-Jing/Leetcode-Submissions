#include <iostream>
using namespace std;
#include <string>
#include <cmath>
#include <stdint.h>

/*
    quickPow with binary factorization.
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;
        else if(n < 0){
            if(n == INT32_MIN) return x*myPow(1/x,-(n+1));
            return myPow(1/x,-n);
        }else{
            double ans = 1, base = x;
            while(n){
                if(n%2) ans *= base;
                n /= 2;
                base *= base;
            }
            return ans;
        }
    }
};

int main() {
    Solution sol;
    double x = 2.00000;
    int n = 1;
    cout<<sol.myPow(x,n)<<endl;
    return 0;
}