#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    struct segNode {
        int l, r, min;
    }seg[100000];
    int buildSeg(vector<int> &prices, int l, int r, int x) {
        seg[x].l = l, seg[x].r = r;
        if(l == r) seg[x].min = prices[l];
        else{
            int mid = (l+r)/2;
            seg[x].min = min(buildSeg(prices,l,mid,2*x),buildSeg(prices,mid+1,r,2*x+1));
        }
        return seg[x].min;
    }
    int findMin(int l, int r, int x) {
        if(l <= seg[x].l && seg[x].r <= r) return seg[x].min;
        int mid = (seg[x].l + seg[x].r)/2;   
        if(mid < l) return findMin(l,r,2*x+1);
        if(mid >= r) return findMin(l,r,2*x);
        return min(findMin(l,mid,2*x),findMin(mid+1,r,2*x+1));     
    }
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<int> newPrices; newPrices.push_back(prices[0]);
        int i = 1, flag = 0;
        while(i+1 < prices.size()){
            if((prices[i] < prices[i-1] && prices[i] > prices[i+1]) || 
               (prices[i] > prices[i-1] && prices[i] < prices[i+1])) flag = 0;
            else if(prices[i] == prices[i-1]){
                if(!flag) newPrices.push_back(prices[i]), flag = 1;
            }else newPrices.push_back(prices[i]), flag = 0;
            i++;
        }
        newPrices.push_back(prices.back());
        for(int i = 0;i < newPrices.size();i++) cout<<newPrices[i]<<' '; cout<<endl;
        vector<int> minPrice; minPrice.resize(newPrices.size());
        for(int i = 0;i < newPrices.size();i++)
            minPrice[i] = i ? min(minPrice[i-1],newPrices[i]) : newPrices[i];
        buildSeg(newPrices,0,newPrices.size()-1,1);
        int ans = 0;
        if(newPrices.size() < 2) return ans;
        for(int i = 1;i < newPrices.size();i++){
            int tmp = minPrice[i-1] >= newPrices[i] ? 0 : newPrices[i]-minPrice[i-1];
        //    cout<<i<<':'<<tmp<<endl;
            ans = max(ans,tmp);
            for(int j = i+2;j < newPrices.size();j++){
                int minn = findMin(i+1,j-1,0);
                int tmpp = minn >= newPrices[j] ? 0 : newPrices[j]-minn;
            //    cout<<i<<','<<j<<':'<<tmpp<<endl;
                ans = max(ans,tmp+tmpp);
            }
        //    cout<<endl;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> input = {9,8,0,0,0,7,6,5,10};
    cout<<sol.maxProfit(input)<<endl;
    return 0;
}