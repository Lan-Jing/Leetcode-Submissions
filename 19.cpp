#include <iostream>
using namespace std;
#include <string>
#include <cstring>

/*
    first count the length, then remove the wanted node.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int cnt = 0;
        while(ptr != NULL) ptr = ptr->next, cnt++;
        ptr = head;
        for(int i = 0;i < cnt-n-1;i++) ptr = ptr->next;
        if(cnt == n){
            head = head->next;
            delete ptr;
        }else{
            ListNode* deleted = ptr->next;
            ptr->next = ptr->next->next;
            delete deleted;
        }
        return head;
    }
};

int main() {

}