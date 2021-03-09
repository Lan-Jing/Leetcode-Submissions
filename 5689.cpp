#include <iostream>
using namespace std;
#include <cstring>
#include <vector>

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size(), j;
        if(ruleKey == "type") {
            j = 0; 
        } else if(ruleKey == "color") {
            j = 1;
        } else {
            j = 2;
        }

        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if(items[i][j] == ruleValue) {
                cnt++;
            }
        }
        return cnt;
    }
};


int main () 
{

}