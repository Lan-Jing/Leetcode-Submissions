#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *ptr = root;
        while(ptr != NULL){
            TreeNode *prev = ptr->left;
            if(prev == NULL){
                ans.push_back(ptr->val);
                ptr = ptr->right;
            }else{
                while(prev->right != NULL && prev->right != ptr)
                    prev = prev->right;
                if(prev->right == NULL){
                    prev->right = ptr;
                    ptr = ptr->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(ptr->val);
                    ptr = ptr->right;
                }
            }
        }
        return ans;
    }
};

int main() {

}