#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int getPosition(vector<int>& nums1, vector<int>& nums2, int target) {
        int l = 0, r = min(target,(int)nums1.size()-1);
        while(l <= r){
//            cout<<l<<' '<<r<<endl;
            int mid = (l + r) / 2;
            int ll = 0, lr = nums2.size();
            while(ll < lr){
//                cout<<"   "<<ll<<' '<<lr<<endl;
                int lmid = (ll + lr) / 2;
                if(nums2[lmid] < nums1[mid]) ll = lmid + 1;
                else lr = lmid;
            }
            int ul = 0, ur = nums2.size();
            while(ul < ur){
//                cout<<"   "<<ul<<' '<<ur<<endl;
                int umid = (ul + ur) / 2;
                if(nums2[umid] <= nums1[mid]) ul = umid + 1;
                else ur = umid; 
            }
            int resMin = mid + ll, resMax = mid + ul;
            if(resMin <= target && target <= resMax)
                return mid;
            else if(l == r) return -1;
            else{
                if(target < resMin) r = mid;
                else l = mid + 1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if((l1 + l2) % 2){
            int pos1 = getPosition(nums1,nums2,(l1+l2)/2);
//            cout<<pos1<<endl;
            int pos2 = getPosition(nums2,nums1,(l1+l2)/2);
//            cout<<pos1<<' '<<pos2<<endl;
            if(pos1 != -1) return nums1[pos1];
            else return nums2[pos2];
        }else{
            int pos11 = getPosition(nums1,nums2,(l1+l2)/2-1);
            int pos12 = getPosition(nums2,nums1,(l1+l2)/2-1);
            int pos21 = getPosition(nums1,nums2,(l1+l2)/2);
            int pos22 = getPosition(nums2,nums1,(l1+l2)/2);
//            cout<<pos11<<' '<<pos12<<','<<pos21<<' '<<pos22<<endl;
            return ((double)(pos11 != -1 ? nums1[pos11] : nums2[pos12] ) + (double)(pos21 != -1 ? nums1[pos21] : nums2[pos22]) )/2;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums1, nums2;
    nums1 = {1,3}; nums2 = {2};
    cout<<sol.findMedianSortedArrays(nums1,nums2)<<endl;
    cout<<endl;
    nums1 = {1,2}; nums2 = {3,4};
    cout<<sol.findMedianSortedArrays(nums1,nums2)<<endl;
    return 0;
}