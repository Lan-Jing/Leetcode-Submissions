#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int flag = 0;
    void dfsCheck(TreeNode *now, vector<int> &target, string tmp) {
        if(flag) return ;
        if(tmp.length() == target.size()) {
            int f = 1;
            for(int i = 0;i < target.size();i++)
                if((int)tmp[i] != target[i]) {
                    f = 0; break;
                }
            if(f) {
                flag = 1; return ;
            }
        }
        if(now->left != NULL) {
            string newTmp = tmp;
            if(newTmp.length() == target.size()) newTmp.erase(0,1);
            newTmp.push_back(now->left->val);
            dfsCheck(now->left, target, newTmp);
        }
        if(now->right != NULL) {
            string newTmp = tmp;
            if(newTmp.length() == target.size()) newTmp.erase(0,1);
            newTmp.push_back(now->right->val);
            dfsCheck(now->right, target, newTmp);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        int listL = 0;
        ListNode *ptr = head;
        vector<int> list;
        while(ptr != NULL) {
            list.push_back(ptr->val);
            ptr = ptr->next;
            listL++;
        }
        string tmp = "";
        tmp.push_back((char)root->val);
        dfsCheck(root, list, tmp);
        return flag;
    }
};

int main() {

}