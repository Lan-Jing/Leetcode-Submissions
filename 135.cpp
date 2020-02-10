#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <stdint.h>

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(!n) return 0;
        else if(n == 1) return 1;
        
        int ans = 0;
        queue<int> que;
        vector<int> can(n), vis(n);
        for(int i = 0;i < n;i++){
            if((i ? ratings[i-1] : INT32_MAX) >= ratings[i] && 
               (i < n-1 ? ratings[i+1] : INT32_MAX) >= ratings[i]){
                   vis[i] = 1;
                   ans += can[i] = 1;
                   if(i && !vis[i-1]) que.push(i-1);
                   if(i < n-1 && !vis[i+1]) que.push(i+1);
               }
        }
        while(!que.empty()){
            int i = que.front(); que.pop();
            if(vis[i]) continue;
            if((i ? ratings[i-1] : INT32_MAX) >= ratings[i] && 
               ratings[i+1] < ratings[i] && can[i+1]){
                ans += can[i] = can[i+1] + 1;
                vis[i] = 1;
                if(i) que.push(i-1);
            }else if((i == n-1 ? INT32_MAX : ratings[i+1]) >= ratings[i] &&  
                     ratings[i-1] < ratings[i] && can[i-1]){
                ans += can[i] = can[i-1] + 1;
                vis[i] = 1;
                if(i < n-1) que.push(i+1);
            }
        }
        for(int i = 1;i < n-1;i++)
            if(!can[i]) ans += can[i] = min(can[i-1],can[i+1]) + 1;
        for(int i = 0;i < n;i++) cout<<can[i]<<' '; cout<<endl;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1,2,87,87,87,2,1}; 
    cout<<sol.candy(ratings)<<endl;
    return 0;
}