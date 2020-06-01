#include <iostream>
using namespace std;
#include <string>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(0, head);
        ListNode *sortedHead = newHead, *ptr, *prev;
        while(sortedHead->next != NULL) {
            int Min = INT32_MAX;
            ptr = sortedHead;
            while(ptr->next != NULL) {
                if(ptr->next->val < Min) {
                    Min = ptr->next->val;
                    prev = ptr;
                }
                ptr = ptr->next;
            }

            swap(sortedHead->next->val, prev->next->val);

            sortedHead = sortedHead->next;
        }
        return newHead->next;
    }
};