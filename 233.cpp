#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    long long recSol(vector<long long> &dp, int nowPos, int num) {
        int powTen = (int)pow(10,nowPos);
        int headBit = (num / powTen) % 10;
        if(!nowPos) return headBit ? 1 : 0;
        long long res = 0;
        if(headBit == 0) return recSol(dp,nowPos-1,num);
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