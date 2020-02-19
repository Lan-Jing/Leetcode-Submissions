#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cmath>

/*
    math problem. Easy to solve when lower-level digits goes from 0 to 9.
    Otherwise, we use recursion.
    Answer comes from three parts.
    1. count of 1 from lower-level digits 0-9, easily computed and recorded in dp.
    2. count of all numbers from lower levels: we use 1 in current position.
    3. count of 1 from lower-level digits, but only from 0 to some int i.
       Use recursion to solve it, with boundary 1 or 0.
*/

class Solution {
public:
    long long recSol(vector<long long> &dp, int nowPos, int num) {
        int powTen = (int)pow(10,nowPos);
        int headBit = (num / powTen) % 10;
        // get current digit.
        if(!nowPos) return headBit ? 1 : 0;
        // recursion boundary, 1 for 1-9, 0 for 0.
        long long res = 0;
        if(headBit == 0) return recSol(dp,nowPos-1,num);
        // seperate count into three parts.
        if(headBit == 1){
            return dp[nowPos-1]+(num%powTen+1)+recSol(dp,nowPos-1,num%powTen);
        }else{
            return headBit*dp[nowPos-1]+powTen+recSol(dp,nowPos-1,num%powTen);
        }
    }
    int countDigitOne(int n) {
        if(n <= 0) return 0;

        vector<long long> dp(10);
        dp[0] = 1;
        for(int i = 1;i < 10;i++) dp[i] = dp[i-1]*10 + pow(10,i);
        int tn = n, bitCount = 0;
        while(tn){
            tn /= 10; bitCount++;
        }
        return recSol(dp,bitCount-1,n);
    }
};

int main() {
    Solution sol;
    cout<<sol.countDigitOne(234)<<endl;
    return 0;
}