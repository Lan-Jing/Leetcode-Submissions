#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());

        int ans = 0, nowRow = 0, j = 0;
        for(int i = 0;i < reservedSeats.size();i++) {
            if(reservedSeats[i][0] > nowRow) {
                ans += (reservedSeats[i][0] - nowRow - 1)*2;
                nowRow = reservedSeats[i][0]; j = i;
            }
            if((i < reservedSeats.size()-1 && reservedSeats[i+1][0] > nowRow) || (i == reservedSeats.size()-1)) {
                int f1 = 1, f2 = 1, f3 = 1;
                for(int k = j;k <= i;k++) {
                    if(4 <= reservedSeats[k][1] && reservedSeats[k][1] <= 7) f2 = 0;
                    if(2 <= reservedSeats[k][1] && reservedSeats[k][1] <= 5) f1 = 0;
                    if(6 <= reservedSeats[k][1] && reservedSeats[k][1] <= 9) f3 = 0;
                }
                if(f1 && f3) ans += 2;
                else if(f1 || f2 || f3) ans += 1;
            }
        }
        ans += 2*(n-reservedSeats.back()[0]);
        return ans;
    }
};