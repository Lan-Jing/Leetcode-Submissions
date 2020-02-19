#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stdint.h>

/*
    Then we can further reduce both time and space complexities to O(kn) and O(k)/O(n)
    If we print dp[k][j] as a k*length matrix, value of each node (k,j) comes from
    (k-1,i)|i<j and (k,i)|i<j. All have been computed before, which makes it possible 
    to keep track of the maximum one directly without iteration on i.

    1. If we iterate k first then j, only the (k-1)th and kth rows are needed.
       Let tmpMax be max(dp[k-1][i]-price[i]|i<j), meaning the maximum profit
       completing k-1 transactions before i and begining the kth on i. Each time we visit
       (k,j), tmpMax is updated with dp[k-1][j-1]-prices[j-1] (the correspoding upperleft node),
       which can be interpreted as buying in the kth transaction on period j-1. Then we can update node (k,j).
       Two row (k-1,0:j-1)(maximum balance tracked by tmpMax) and (k,0:j-1)(no move on j) are 
       recorded, making it O(kn) time and O(n) space.

    2. If we iterate position j first then k, we still need the two rows above for update while the process
       goes on the columns first. Then we have to introduce a tmpMax array instead of single variable.
       balance[k] holds the maximum balance(during kth transaction) and profit[k] holds the maximum profit(after kth transaction).
       Each time we visit (k,j): 
       1)  we try to buy in stock on j by updating max balance on transaction k, which comes from maximum profit after transaction k-1.
       2)  we try to sell out stock on j by updating max profit on transaction k, which comes from maximum balance on transaction k.
       This solution is still O(kn) time but with O(k) space complexity. Considering if k > n/2 we will have a greedy strategy runs on O(n) time,
       O(k) should always be smaller.

    Actually we have a greedy solution for this problem that runs in O(n + klogn) time.
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
        1) when p1 > p2. As (v1,p1) is more profitable, keep it in the stack and start the second one. 
        2) when p1 <= p2, we are not sure on the decision, so we push (p1,v2) into the profit heap and (v1,p2) into the stack for improvement.
           Notice that the decision we can't make would be whether to take two chances to gain extra profit, which requires p1 > v2. Otherwise there is 
           no need to seperate them. When (v1,p2) and (p1,v2) are both taken in the heap, we get equivalent profit to (v1,p1) and (v2,p2). Otherwise we take them combined.
    Finally we combine transactions as many as possible and let the heap to decide whether to seperate some parts from them, by adding profit of seperation. 
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> newPrices;
        int flag = 0;
        for(int i = 0;i < prices.size();i++){
            if(!i || i == prices.size()-1) newPrices.push_back(prices[i]);
            else if((prices[i] < prices[i-1] && prices[i] > prices[i+1]) || 
                    (prices[i] > prices[i-1] && prices[i] < prices[i+1]))
                flag = 0;
            else if(prices[i] == prices[i-1]){
                if(!flag) newPrices.push_back(prices[i]), flag = 1;
            }else newPrices.push_back(prices[i]), flag = 0;
        }
        if(newPrices.size() < 2) return 0;
        int ans = 0, buyPrice;
        if(k > newPrices.size()/2){
            for(int i = 0;i < newPrices.size();i++){
                if(!i){
                    if(newPrices[i] < newPrices[i+1]) buyPrice = newPrices[i];
                }else if(i == newPrices.size()-1){
                    if(newPrices[i-1] < newPrices[i]) ans += newPrices[i]-buyPrice;
                }else{
                    if(newPrices[i] <= newPrices[i-1] && newPrices[i] < newPrices[i+1]) buyPrice = newPrices[i];
                    if(newPrices[i] > newPrices[i-1] && newPrices[i] >= newPrices[i+1]) ans += newPrices[i]-buyPrice;
                }
            }
            return ans;
        }
        vector<int> profit(k+1);
        vector<int> balance(k+1,INT32_MIN);
        for(int j = 1;j < newPrices.size();j++){
            for(int p = 1;p <= k;p++){
                balance[p] = max(balance[p],profit[p-1]-newPrices[j]);
                profit[p] = max(profit[p],balance[p]+newPrices[j]);
            }
        }
        return profit[k];
    }
};

int main() {
    Solution sol;
    vector<int> input = {3,2,6,5,0,3,3,2,3,3,6,9};
    cout<<sol.maxProfit(1000,input)<<endl;
    return 0;
}