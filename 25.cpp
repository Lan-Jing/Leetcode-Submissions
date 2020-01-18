#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

/*
    swap in K groups.
    maintain pointers to the moved nodes and the destinations.
    Then repeat the delete-and-insert operation several times.
*/

struct ListNode {
    int val;
    ListNode *next; 
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void printList(ListNode *&head) {
        ListNode *ptr = head;
        while(ptr != NULL) cout<<ptr->val<<' ', ptr = ptr->next;
        cout<<endl;
    }
    ListNode* reverseKGroup(ListNode* &head, int k) {
        if(k == 1) return head;
        int cnt = 0;
        ListNode *prev = NULL, *ptr = head;
        while(ptr != NULL){
            if(cnt < k - 1) cnt++;
            else{
                cnt = 0;
                if(prev == NULL){
                    for(int i = 0;i < k - 1;i++){
                        ListNode* tmp = head;
                        head = head->next;
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                    }
                }else{
                    for(int i = 0;i < k - 1;i++){
                        ListNode* tmp = prev->next;
                        prev->next = tmp->next;
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                    }
                }
                for(int i = 0;i < k - 1;i++) ptr = ptr->next;
                prev = ptr;
//                printList(head);
            }
            ptr = ptr->next;
        }
        return head;
    }
};

int main() {

}