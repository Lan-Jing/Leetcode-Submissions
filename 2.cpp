#include <iostream>
using namespace std;
#include <cstring>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = 0, length2 = 0, length3 = 0;
        int num1[100010], num2[100010], num3[100010];
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        memset(num3,0,sizeof(num3));

        ListNode* ptr = l1;
        while(ptr != NULL) num1[length1++] = ptr->val, ptr = ptr->next;
        ptr = l2;
        while(ptr != NULL) num2[length2++] = ptr->val, ptr = ptr->next;

        int exceed = 0;
        for(int i = 0;i < max(length1,length2);i++){
            num3[i] = num1[i] + num2[i] + exceed;
            if(num3[i] >= 10) num3[i] -= 10, exceed = 1;
            else exceed = 0;
        } 
        if(exceed == 1){
            length3 = max(length1,length2) + 1;
            num3[length3 - 1] = 1;
        }else length3 = max(length1,length2);

        ListNode* res = new ListNode(num3[0]);
        ptr = res;
        for(int i = 1;i < length3;i++){
            ptr->next = new ListNode(num3[i]);
            ptr = ptr->next;
        }
        return res;
    }
};

int main(){

}