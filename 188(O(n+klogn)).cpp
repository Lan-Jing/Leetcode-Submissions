#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <utility>
#include <stack>

/*
    Actually we have a greedy solution for this problem that runs in O(nlogn) time.
    Instead of thinking it as consecutive decision making, we may consider it as picking out k most profitable transactions. However, we may have at most O(n^2) 
    possible transactions for a given price array. With stack implementation we can reduce it to O(n) level.
    Consider two adjacent transactions (v1,p1) and (v2,p2) with v1<p1 and v2<p2, our options are: 
    1. treat them seperately.
    2. merge them into one transaction: (v1,p2). This can be done by pushing (v1,p2) and (p1,v2) into the stack.
    Mind that condition 2. is the key to merge transactions into ones with better profit within O(n) time. Now consider their situations.
    1. When v1 >= v2,
        The second one presents bigger chance to profit(with lower starting price). We have no reason to keep the first one for further improvement.
        So we end the trip for (v1,p1) by popping it out and pushing it into the profit heap. Then push (v2,p2) into the stack to start its improvement.
    2. When v1 < v2,
        1) when p1 > p2. As (v1,p1) is more profitable, keep it in the stack(we may improve it later) and start the second one. 
           Also notice that if p1 > p2, there is no reason to combine two transactions into one with smaller profit.
        2) when p1 <= p2, we are not sure on the decision, so we push (p1,v2) into the profit heap and (v1,p2) into the stack for improvement.
           Notice that the decision we can't make would be whether to spend two chances gaining extra profit, which requires p1 > v2. Otherwise(v1<p1<v2<p2) there is 
           no need to seperate them. When (v1,p2) and (p1,v2) are both taken in the heap, we get equivalent profit to (v1,p1) and (v2,p2). Otherwise we take them combined.
    Finally we combine transactions as many as possible and let the heap to decide whether to seperate some parts from them, by adding profit created from seperation. 

    We can further modify the heap operation to reduce time from O(nlogn) to O(n+klogn). First dump all profits into a vector, then transform it into a heap.
    This trick will help us save time for inserting each profit node.
*/

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int v = -1, p = -1, n = prices.size();
        int ans = 0;
        if(n < 2) return ans;
        stack<pair<int,int> > trans;
        priority_queue<int> profit;
        while(p < n){
            for(v = p+1;v+1 < n && prices[v+1] <= prices[v];v++);
            for(p = v+1;p+1 < n && prices[p+1] >= prices[p];p++);
            if(v >= n || p >= n) break;
            while(!trans.empty() && prices[trans.top().first] > prices[v]){
                profit.push(prices[trans.top().second]-prices[trans.top().first]);
                trans.pop();
                // cannot improve the last transaction.
            }
            while(!trans.empty() && prices[trans.top().second] < prices[p]){
                profit.push(prices[trans.top().second]-prices[v]);
                // push profit of seperation.
                v = trans.top().first;
                // combine the two transaction by moving pointer v back to the previous position.
                trans.pop();
                // this is rather a replacement.
            }
            trans.push(make_pair(v,p));
            // if v moves back, the combined transaction will be pushed into the stack.
        }
        while(!trans.empty()){
            profit.push(prices[trans.top().second]-prices[trans.top().first]);
            trans.pop();
        }
        for(int i = 0;i < k && !profit.empty();i++){
            ans += profit.top(); profit.pop();
        }
        return ans;
    }
};

int main() {
    vector<int> input = {2,4,1};
    Solution sol;
    cout<<sol.maxProfit(2,input)<<endl;
}