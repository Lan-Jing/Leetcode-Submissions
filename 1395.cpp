#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        if(n < 3) return ans;

        for(int i = 1;i < n-1;i++) {
            for(int l = 0;l < i;l++)
                for(int r = i+1;r < n;r++) 
                    if((rating[l] < rating[i] && rating[i] < rating[r]) || (rating[l] > rating[i] && rating[i] > rating[r]))
                        ans++;
        }
        return ans;
    }
};

int main() {
    
}