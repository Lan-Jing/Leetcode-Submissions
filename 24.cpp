#include <iostream>
using namespace std;
#include <string>

/*
    speical case for swaping in K groups.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void addToHead(ListNode* &head,ListNode* &tail, int x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = head;
        head = newNode;
        if(head->next == NULL) tail = head;
    }
    void printList(ListNode* head) {
        ListNode* ptr = head;
        while(ptr != NULL){
            cout<<ptr->val<<' ';
            ptr = ptr->next;
        }
        cout<<endl;
    }
    ListNode* swapPairs(ListNode* &head) {
        ListNode* ptr = head;
        ListNode* prev = NULL;
        while(ptr != NULL){
            if(ptr->next == NULL) break;
            if(ptr == head){
                head = ptr->next;
                ptr->next = head->next;
                head->next = ptr;
            }else{
                prev->next = ptr->next;
                ptr->next = prev->next->next;
                prev->next->next = ptr;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};

int main() {
    Solution sol;
    ListNode* head = NULL, *tail = NULL;
    for(int i = 0;i < 5;i++) sol.addToHead(head,tail,i);
    sol.printList(head);
    sol.swapPairs(head);
    sol.printList(head);
    return 0;
}