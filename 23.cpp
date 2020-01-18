#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <queue>

/*
    O(nlogk) supported by a heap.
    Heap is used for maintianing the smallest head of all K lists.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    struct queNode{
        int val;
        ListNode* ptr;
        queNode(int x, ListNode* ptr){ this->val = x, this->ptr = ptr; }
        bool operator < (const queNode &other) const {
            return this->val > other.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<queNode> que;
        for(int i = 0;i < lists.size();i++)
            if(lists[i] != NULL) 
                que.push(queNode(lists[i]->val,lists[i]));
        ListNode* head = NULL;
        ListNode* ptr = NULL;
        while(!que.empty()){
            queNode temp = que.top(); que.pop();
            if(head == NULL){
                head = new ListNode(temp.val);
                ptr = head;
            }else{
                ptr->next = new ListNode(temp.val);
                ptr = ptr->next;
            }
            if(temp.ptr->next != NULL) 
                que.push(queNode(temp.ptr->next->val,temp.ptr->next));
        }
        return head;
    }
};

int main() {
    Solution sol;

}